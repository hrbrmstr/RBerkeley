\name{BerkeleyDB Cursors}
\Rdversion{1.1}
\alias{Cursors}
\alias{DBC}
\alias{db_cursor}
\alias{dbcursor_close}
\alias{dbcursor_count}
\alias{dbcursor_del}
\alias{dbcursor_dup}
\alias{dbcursor_pget}
\alias{dbcursor_set_priority}
\alias{dbcursor_get_priority}

\title{
BerkeleyDB Database Operations and Methods
}
\description{
Low-level calls to the BerkeleyDB API. These
functions simply wrap most of the DB functionality
and expose it at the \R level.

Documentation on usage, valid arguments, and
flags from the official Oracle C API should
be all that is required to correctly use this API.

\tabular{ll}{
  \emph{Database Cursors} \tab \emph{Description}\cr
  \tab \cr
db_cursor \tab  Create a cursor \cr
dbcursor_close \tab Close a cursor \cr
dbcursor_count \tab Return count of duplicates \cr
dbcursor_del \tab   Delete by cursor \cr
dbcursor_dup \tab   Duplicate a cursor \cr
dbcursor_get \tab   Retrieve by cursor \cr
dbcursor_pget \tab   Retrieve by cursor \cr
dbcursor_put \tab   Store by cursor \cr
dbcursor_set_priority \tab  Set the cursor's cache priority \cr
}

}
\details{
The user should refer to the official API documentation for the
Berkeley DB database available from Oracle.
}
\value{
Varies by function call.
}
\references{
Oracle Berkeley DB\cr
\url{http://www.oracle.com/technology/documentation/berkeley-db/db/index.html}\cr\cr
Oracle Berkeley DB C API\cr
\url{http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/frame.html}\cr\cr
Oracle Berkeley DB Reference Guide\cr
\url{http://www.oracle.com/technology/documentation/berkeley-db/db/ref/toc.html}
}
\author{
Jeffrey A. Ryan for the R API
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ database }
