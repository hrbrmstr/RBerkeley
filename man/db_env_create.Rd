\name{db_env_create}
\Rdversion{1.1}
\alias{db_env_create}
\title{
Create An Environment Handle
}
\description{
Create An Environment Handle
}
\usage{
db_env_create(flags = 0L)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{flags}{
flags parameter created with mkFlags
}
}
\details{
See Berkeley DB API documentation for usage details.
}
\value{
A database environment handle.
}
\references{
Oracle Berkeley DB API\cr
\url{http://www.oracle.com/technetwork/database/database-technologies/berkeleydb/overview/index.html}\cr
}
\author{
Jeffrey A. Ryan
}
\seealso{
\code{\link{Environments}}\cr
\code{\link{db_create}}
}
\examples{
\dontrun{
dbh <- db_env_create()
}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ database }
