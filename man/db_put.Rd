\name{db_put}
\Rdversion{1.1}
\alias{db_put}
\alias{db_get}
\alias{db_getP}
\alias{dbcursor_put}
\alias{dbcursor_get}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Methods to Store And Retrieve Database Records
}
\description{
Store and retrieve R objects as key/value pairs
from a Berkeley DB.
}
\usage{
db_put(dbh, txnid=NULL, key, data, flags=0L)
db_get(dbh, txnid=NULL, key, data, flags=0L)

dbcursor_put(dbc, key, data, flags)
dbcursor_get(dbc, key, data, flags, n)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{dbh}{
A DB handle to an open Berkeley database.
}
  \item{dbc}{
A DBC handle to an open cursor.
}
  \item{txnid}{
A DB_TXN transaction handle. (currently ignored)
}
  \item{key}{
An \R object, raw or will be coerced to raw.  See details.
}
  \item{data}{
An \R object, raw or will be coerced to raw.  See details.
}
  \item{flags}{
A valid flag created with \code{mkFlags}.
}
  \item{n}{
Elements to return.
}
}
\details{
BerkeleyDB uses key/data pairs for records, with no underlying
data schema.

This allows for arbitrary byte-strings to be stored as
keys or values in a DB.  Internally these are a C struct
of type \code{DBT}.  To the RBerkeley user, these objects
can range from standard (serialized) R objects to anything
representable as a \code{RAW} vector in R, which is everything.

The design of \code{db_put}, \code{db_get}, \code{dbcursor_put}
and \code{dbcursor_get} differ from package philosophy in that
by default all objects are preprocessed via R to make usable
byte strings (RAW vectors) for internal Berkeley use.

When passed an R object of any type, a check is made to see if
it needs to be converted into a raw vector, if so the
\code{serialize} function is called.  This conversion
is applied to both key and value automatically.

To avoid the use of \code{serialize} one must provide
a vector of class \code{raw}.

The db_get and dbcursor_get methods will return
a vector or list of vectors of type \code{raw}.  Further
application specific processing may be required.
}
\value{
*put functions return non-zero on failure, 0 on success.
The *get calls will return a raw vector that must be processed on
success, or non-zero on failure.

These functions are called for their database side effects.
}
\references{
BerkeleyDB DB->put\cr
\url{http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html}\cr\cr
BerkeleyDB DB->get\cr
\url{http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html}
}
\author{
Jeffrey A. Ryan
}
\note{
Serialized objects in R have certain limitations with respect
to underlying design considerations. 
}


\seealso{
\code{\link{serialize}}, \code{\link{unserialize}}
}
\examples{
\dontrun{
dbh <- db_create()
db_open(dbh, flags=mkFlags(DB_CREATE))

db_put(dbh, key="key", data="value")

db_get(dbh, key="key") # serialized "value"
unserialize(db_get(dbh, key="key")) # "value"

db_put(dbh, key=charToRaw("key2"), data=charToRaw("value"))
db_get(dbh, key=charToRaw("key2"))
rawToChar(db_get(dbh, key=charToRaw("key2"))) # what you expect, "value"

db_get(dbh, key="key2")  # not there, must use symmetric marshalling/conversion

db_close(dbh) # close DB
dbh <- db_create()
db_remove(dbh, "access.db", NULL)
}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ database }
