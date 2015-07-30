#' Create Valid Flags For DB Calls
#' 
#' Allows for unquoted DB API-like constant names to be bitwise OR'd together
#' for passing into low-level database calls.
#' 
#' The Berkeley DB (tm) database makes use of predefined constants in the C
#' code to pass as flags to many of the function calls.
#' 
#' These flags may be combined, using bitwise OR logic, and the resultant value
#' can than be used as a valid flag argument.
#' 
#' This function takes unquoted arguments that match the underlying API
#' flag/constant names.
#' 
#' If a name is passed that is not part of the available API, a warning is
#' returned and the argument is effectively ignored.  If this value
#' \emph{should} be present, and simply isn't please submit a bug report to the
#' RBerkeley maintainer.
#' 
#' All bitwise operations are within the C code to allow for maximum
#' consistency with the API, as well as allowing as close to the API semantics
#' as possible.
#' 
#' @param \dots quoted or unquoted comma separated names of DB constants
#' @return An integer suitable for use as a \emph{flags} argument in the
#' lower-level API calls.
#' @author Jeffrey A. Ryan
#' @references Oracle BerkeleyDB \url{https://www.oracle.com}
#' @keywords misc database
#' @examples
#' 
#' mkFlags(DB_CREATE)
#' mkFlags(DB_CREATE, DB_EXCL)
#' mkFlags(DB_CREATE, DB_EXCL, DB_NOMMAP)
#' mkFlags(DB_RDONLY)
#' 
#' # DB_NOTHERE is not valid, throws warning
#' \dontrun{
#' mkFlags(DB_NOMMAP,DB_CONSTANT_NOT_DEFINED)
#' }
#' 
#' @export mkFlags
mkFlags <- function(...) {
  if(nargs()==1) {
    flags <- gsub(" ","",
                  unlist(
                    strsplit(
                      as.character(
                        match.call(call=sys.call())[-1]),"\\|")))
    flags <- gsub('\"',"",flags)
  } else {
    flags <- as.character(match.call(call=sys.call())[-1])
  }
  .Call("mkFlags", flags)
}
