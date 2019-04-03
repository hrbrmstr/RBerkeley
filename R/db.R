#' Create DBT Structure
#'
#' Berkeley DB uses a C-level struct referred to as a DBT (short for Data Base
#' Thang).  This is represented in the R code as a list of class DBT.  At
#' present it is only used in \code{db_get} calls to allow for more advance
#' operations such as partial record retrieval.
#'
#' This interface to the underlying Berkeley DB DBT structure is currently
#' experimental, and is only supported in limited places in \pkg{RBerkeley}.
#'
#' @param data An R object of type \sQuote{raw}.
#' @param size The size (in bytes) of the data object. Must be integer or NULL.
#' @param ulen The ulen attribute of DBT. Must be integer or NULL.
#' @param dlen The dlen attribute of DBT. Used for partial get/put. Must be
#' integer or NULL.
#' @param doff The dlen attribute of DBT. Used for partial get/put. Must be
#' integer or NULL.
#' @param flags The flags to DBT. Must be 0 or a valid \code{DBT} flag.
#' @return A \code{DBT} object.
#' @author Jeffrey A. Ryan
#' @references Official Oracle Documentation for DBT structs:
#' \url{http://docs.oracle.com/cd/E17076_04/html/gsg/C/cstructs.html}
#' @keywords database interface
#' @export DBT
DBT <- function(data=NULL, size=NULL, ulen=NULL, dlen=NULL, doff=NULL, flags=NULL) {
  structure(list(data, size, ulen, dlen, doff, flags), class="DBT")
}



#' Create A Database Handle
#'
#' Create a database handle
#'
#' See Berkeley DB API documentation for usage details.
#'
#' @param dbenv A DB_ENV handle created with db_env_create, or NULL
#' @param flags flags parameter created with mkFlags
#' @return A database handle.
#' @author Jeffrey A. Ryan
#' @seealso \code{\link{Databases}}\cr \code{\link{db_env_create}}
#' @references Oracle Berkeley DB API\cr
#' \url{http://www.oracle.com/technetwork/database/database-technologies/berkeleydb/overview/index.html}\cr\cr
#' @keywords database
#' @examples
#'
#' \dontrun{
#' dbh <- db_create()
#' }
#'
#' @export db_create
db_create <- function(dbenv=NULL, flags=0L) {
  structure(0, conn_id=.Call("rberkeley_db_create", dbenv, flags), class="DB")
}

db_strerror <- function(error) {
  .Call("rberkeley_db_strerror", as.integer(error))
}

db_del <- function(dbh, txnid=NULL, key, flags=0L) {
  if(!is.raw(key))
    key <- serialize(key, NULL)
  .Call("rberkeley_db_del", as.DB(dbh), txnid, key, as.integer(flags))
}

db_open <- function(dbh, txnid=NULL, file="access.db",
                    database=NULL, type="BTREE", flags=0L) {
  if(!is.numeric(type)) {
  type <- switch(gsub("DB_","",toupper(type)),
                       BTREE  =1L,
                       HASH   =2L,
                       RECNO  =3L,
                       QUEUE  =4L,
                       UNKNOWN=5L)
  if(is.null(type)) stop("'type' must be a one of BTREE, HASH, RECNO, QUEUE, or UNKNOWN")
  }
  .Call("rberkeley_db_open", as.DB(dbh), txnid, file, database, as.integer(type), flags)
}

db_close <- function(dbh) {
  .Call("rberkeley_db_close", as.DB(dbh))
}

db_upgrade <- function(dbh, file, flags) {
  .Call("rberkeley_db_upgrade", as.DB(dbh), file, as.integer(flags))
}

db_compact <- function(dbh, txnid=NULL, start=NULL, stop=NULL,
                       c_data=NULL, flags=0L) {
  .Call("rberkeley_db_compact", as.DB(dbh), txnid, start, stop, c_data, as.integer(flags))
}

db_set_priority <- function(dbh, priority) {
  if(is.character(priority))
    priority <- mkFlags(priority)
  .Call("rberkeley_db_set_priority", as.DB(dbh), as.integer(priority))
}

db_get_priority <- function(dbh) {
  .Call("rberkeley_db_get_priority", as.DB(dbh))
}

db_set_flags <- function(dbh, flags=0L) {
  .Call("rberkeley_db_set_flags", as.DB(dbh), as.integer(flags))
}

db_get_flags <- function(dbh) {
  .Call("rberkeley_db_get_flags", as.DB(dbh))
}


#' Methods to Store And Retrieve Database Records
#'
#' Store and retrieve R objects as key/value pairs from a Berkeley DB.
#'
#' BerkeleyDB uses key/data pairs for records, with no underlying data schema.
#'
#' This allows for arbitrary byte-strings to be stored as keys or values in a
#' DB.  Internally these are a C struct of type \code{DBT}.  To the RBerkeley
#' user, these objects can range from standard (serialized) R objects to
#' anything representable as a \code{RAW} vector in R, which is everything.
#'
#' The design of \code{db_put}, \code{db_get}, \code{dbcursor_put} and
#' \code{dbcursor_get} differ from package philosophy in that by default all
#' objects are preprocessed via R to make usable byte strings (RAW vectors) for
#' internal Berkeley use.
#'
#' When passed an R object of any type, a check is made to see if it needs to
#' be converted into a raw vector, if so the \code{serialize} function is
#' called.  This conversion is applied to both key and value automatically.
#'
#' To avoid the use of \code{serialize} one must provide a vector of class
#' \code{raw}.
#'
#' The db_get and dbcursor_get methods will return a vector or list of vectors
#' of type \code{raw}.  Further application specific processing may be
#' required.
#'
#' @aliases db_put db_get db_getP dbcursor_put dbcursor_get
#' @param dbh A DB handle to an open Berkeley database.
#' @param dbc A DBC handle to an open cursor.
#' @param txnid A DB_TXN transaction handle. (currently ignored)
#' @param key An object, raw or will be coerced to raw.  See details.
#' @param data An object, raw or will be coerced to raw.  See details.
#' @param flags A valid flag created with \code{mkFlags}.
#' @param n Elements to return.
#' @return *put functions return non-zero on failure, 0 on success. The *get
#' calls will return a raw vector that must be processed on success, or
#' non-zero on failure.
#'
#' These functions are called for their database side effects.
#' @note Serialized objects in R have certain limitations with respect to
#' underlying design considerations.
#' @author Jeffrey A. Ryan
#' @seealso \code{\link{serialize}}, \code{\link{unserialize}}
#' @references BerkeleyDB DB->put\cr
#' \url{http://docs.oracle.com/cd/E17076_04/html/gsg/C/PutEntryWCursor.html}\cr\cr
#' BerkeleyDB DB->get\cr
#' \url{http://docs.oracle.com/cd/E17076_04/html/gsg/C/Positioning.html}
#' @keywords database
#' @examples
#'
#' \dontrun{
#' dbh <- db_create()
#' db_open(dbh, flags=mkFlags(DB_CREATE))
#'
#' db_put(dbh, key="key", data="value")
#'
#' db_get(dbh, key="key") # serialized "value"
#' unserialize(db_get(dbh, key="key")) # "value"
#'
#' db_put(dbh, key=charToRaw("key2"), data=charToRaw("value"))
#' db_get(dbh, key=charToRaw("key2"))
#' rawToChar(db_get(dbh, key=charToRaw("key2"))) # what you expect, "value"
#'
#' db_get(dbh, key="key2")  # not there, must use symmetric marshalling/conversion
#'
#' db_close(dbh) # close DB
#' dbh <- db_create()
#' db_remove(dbh, "access.db", NULL)
#' }
#'
#' @export db_put
db_put <- function(dbh, txnid=NULL, key, data, flags=0L) {
  if(!is.raw(key))
    key <- serialize(key, NULL)
  if(!is.raw(data))
    data <- serialize(data, NULL)

  invisible(.Call("rberkeley_db_put", as.DB(dbh), txnid, key, data, as.integer(flags)))
}

db_get <- function(dbh, txnid=NULL, key, data=NULL, flags=0L) {
  if(!is.raw(key))
    key <- serialize(key, NULL)
  if(!is.null(data) && !is.raw(data))
    data <- serialize(data, NULL)

  # should add error checking here...
  .Call("rberkeley_db_get", as.DB(dbh), txnid, key, data, as.integer(flags))
}

db_getP <- function(dbh, txnid=NULL, key, data=NULL, flags=0L) {
  if(!is.raw(key))
    key <- serialize(key, NULL)

  if(!inherits(data,"DBT")) {
    if(!is.null(data) && !is.raw(data))
      data <- serialize(data,NULL)
    data <- DBT(data)
  }

  # should add error checking here...
  .Call("rberkeley_db_getP", as.DB(dbh), txnid, key, data, as.integer(flags))
}

db_key_range <- function(dbh, txnid=NULL, key, flags=0L) {
  if(!is.raw(key))
    key <- serialize(key, NULL)
  .Call("rberkeley_db_key_range", as.DB(dbh), txnid, key, as.integer(flags))
}

db_exists <- function(dbh, txnid=NULL, key, flags=0L) {
  if(!is.raw(key))
    key <- serialize(key, NULL)
  .Call("rberkeley_db_exists", as.DB(dbh), txnid, key, flags)
}

db_truncate <- function(dhh) { }

db_get_byteswapped <- function(dbh) {
  .Call("rberkeley_db_get_byteswapped", as.DB(dbh)) 
}

db_set_cachesize <- function(dbh, gbytes, bytes, ncache) {
  .Call("rberkeley_db_set_cachesize",
        as.DB(dbh),
        as.integer(gbytes),
        as.integer(bytes),
        as.integer(ncache))
}

db_get_cachesize <- function(dbh) {
  cachesize <- .Call("rberkeley_db_get_cachesize", as.DB(dbh))
  names(cachesize) <- c("gbytes","bytes","ncache")
  cachesize
}

db_set_pagesize <- function(dbh, pagesize) {
  .Call("rberkeley_db_set_pagesize", as.DB(dbh), as.integer(pagesize))
}

db_get_pagesize <- function(dbh) {
  pagesize <- .Call("rberkeley_db_get_pagesize", as.DB(dbh))
  pagesize
}

db_set_encrypt <- function(dbh, passwd, flags) {
  if(missing(flags))
    flags = mkFlags("DB_ENCRYPT_AES")

  .Call("rberkeley_db_set_encrypt", as.DB(dbh), passwd, flags)
}

db_get_encrypt_flags <- function(dbh) {
  .Call("rberkeley_db_get_encrypt_flags", as.DB(dbh))
}

db_set_lorder <- function(dbh, lorder) {
  lorder <- as.integer(lorder)
  if(lorder != 1234L || lorder != 4321L)
    stop("incorrect 'lorder' value")

  .Call("rberkeley_db_set_lorder", as.DB(dbh), lorder)
}

db_get_lorder <- function(dbh) {
  lorder <- .Call("rberkeley_db_get_lorder", as.DB(dbh))
  if(lorder == 1234L)
   return("little.endian")
  if(lorder == 4321L)
   return("big.endian")
}

db_stat <- function(dbh, txnid=NULL, flags=mkFlags("DB_FAST_STAT")) {
  .Call("rberkeley_db_stat", as.DB(dbh), txnid, as.integer(flags))
}

db_stat_print <- function(dbh, flags=0L) {
  .Call("rberkeley_db_stat_print", as.DB(dbh), as.integer(flags))
}

db_remove <- function(dbh, file, database) {
  .Call("rberkeley_db_remove", as.DB(dbh), file, database)
}

db_rename <- function(dbh, file, database, newname) {
  .Call("rberkeley_db_rename", as.DB(dbh), file, database, newname)
}

db_version <- function() {
  .Call("rberkeley_db_version")
}

db_get_dbname <- function(dbh) {
  .Call("rberkeley_db_get_dbname", as.DB(dbh))
}

db_sync <- function(dbh) {
  .Call("rberkeley_db_sync", as.DB(dbh))
}

db_get_type <- function(dbh) {
  .Call("rberkeley_db_get_type", as.DB(dbh))
}

db_set_errpfx <- function(dbh, errpfx) {
  .Call("rberkeley_db_set_errpfx", as.DB(dbh), errpfx)
}

db_get_errpfx <- function(dbh) {
  .Call("rberkeley_db_get_errpfx", as.DB(dbh))
}

db_set_errfile <- function(dbh, errfile) {
  if(!is.null(errfile) && !file.exists(errfile)) {
    if(!file.create(errfile)) stop(paste("could not create file"))
  }
  .Call("rberkeley_db_set_errfile", dbh, errfile)
}

db_set_msgfile <- function(dbh, msgfile) {
  if(!is.null(msgfile) && !file.exists(msgfile)) {
    if(!file.create(msgfile)) stop(paste("could not create file"))
  }
  .Call("rberkeley_db_set_msgfile", dbh, msgfile)
}

db_set_re_source <- function(dbh, source) {
	if(!file.exists(source)) {
		stop(paste("could not set_re_source source to file",source))
	}
	.Call("rberkeley_db_set_re_source",
			as.DB(dbh),
			as.character(source))
}

