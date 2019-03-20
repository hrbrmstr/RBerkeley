check_pointer <- function(dbh) {
  .Call("rberkeley_check_pointer", dbh)
}

as.DB <- function(x) {
  if(is.DB(x)) {
    return(attr(x, "conn_id"))
  } else stop("not a DB connection")
}

is.DB <- function(x) {
  inherits(x, "DB") 
}

print.DB <- function(x, ...) {
  cat("<DB Handle>\n")
}

## Utility functions for DB_ENV Objects

as.DB_ENV <- function(x) {
  if(is.DB_ENV(x)) {
    return(attr(x, "conn_id"))
  } else stop("not a DB_ENV connection")
}

is.DB_ENV <- function(x) {
  inherits(x, "DB_ENV") 
}

print.DB_ENV <- function(x, ...) {
  cat("<DB_ENV Handle>\n")
}
