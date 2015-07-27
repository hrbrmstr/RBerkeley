\name{db_create}
\Rdversion{1.1}
\alias{db_create}
\title{
Create A Database Handle
}
\description{
Create a database handle
}
\usage{
db_create(dbenv = NULL, flags = 0L)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{dbenv}{
A DB_ENV handle created with db_env_create, or NULL
}
  \item{flags}{
flags parameter created with mkFlags
}
}
\details{
See Berkeley DB API documentation for usage details.
}
\value{
A database handle.
}
\references{
Oracle Berkeley DB API\cr
\url{http://www.oracle.com/technology/documentation/berkeley-db/db/index.html}\cr\cr
}
\author{
Jeffrey A. Ryan
}
\seealso{
\code{\link{Databases}}\cr
\code{\link{db_env_create}}
}
\examples{
\dontrun{
dbh <- db_create()
}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ database }
