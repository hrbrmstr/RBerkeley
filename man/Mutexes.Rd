\name{BerkeleyDB Mutexes}
\Rdversion{1.1}
\alias{Mutexes}
\alias{dbenv_mutex_alloc}
\alias{dbenv_mutex_free}
\alias{dbenv_mutex_lock}
\alias{dbenv_mutex_stat}
\alias{dbenv_mutex_stat_print}
\alias{dbenv_mutex_unlock}
\alias{dbenv_mutex_set_align}
\alias{dbenv_mutex_set_increment}
\alias{dbenv_mutex_set_max}
\alias{dbenv_mutex_set_tas_spins}

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
  \emph{Mutexes} \tab \emph{Description}\cr
  \tab \cr
  dbenv_mutex_alloc \tab Allocate a mutex \cr
  dbenv_mutex_free \tab  Free a mutex \cr
  dbenv_mutex_lock \tab  Lock a mutex \cr
  dbenv_mutex_stat \tab  Mutex statistics \cr
  dbenv_mutex_unlock \tab    Unlock a mutex \cr
  \tab \cr
  \emph{Mutexes Configuration} \tab \emph{Description}\cr
  \tab \cr
  dbenv_mutex_set_align* \tab Configure mutex alignment \cr
  dbenv_mutex_set_increment* \tab Configure number of additional mutexes \cr
  dbenv_mutex_set_max* \tab   Configure total number of mutexes \cr
  dbenv_mutex_set_tas_spins* \tab Configure test-and-set mutex spin count \cr
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
\url{http://www.oracle.com/technetwork/database/database-technologies/berkeleydb/overview/index.html}\cr\cr
Oracle Berkeley DB C API\cr
\url{http://docs.oracle.com/cd/E17076_04/html/gsg/C/index.html}\cr\cr
Oracle Berkeley DB Reference Guide\cr
\url{http://docs.oracle.com/cd/E17076_04/html/index.html}
}
\author{
Jeffrey A. Ryan for the R API
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ database }
