\name{mkFlags}
\Rdversion{1.1}
\alias{mkFlags}
\title{
Create Valid Flags For DB Calls
}
\description{
Allows for unquoted DB API-like constant names
to be bitwise OR'd together for passing into
low-level database calls.
}
\usage{
mkFlags(...)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{\dots}{
  quoted or unquoted comma separated names of DB constants
}
}
\details{
The Berkeley DB (tm) database makes use of
predefined constants in the C code to pass as
flags to many of the function calls.

These flags may be combined, using bitwise
OR logic, and the resultant value can than
be used as a valid flag argument.

This function takes unquoted arguments
that match the underlying API flag/constant
names.

If a name is passed that is not part of the
available API, a warning is returned and
the argument is effectively ignored.  If this
value \emph{should} be present, and simply isn't
please submit a bug report to the RBerkeley maintainer.

All bitwise operations are within the C code to
allow for maximum consistency with the API,
as well as allowing as close to the API
semantics as possible.
}
\value{
An integer suitable for use as a \emph{flags} argument
in the lower-level API calls.
}
\references{
Oracle BerkeleyDB \url{https://www.oracle.com}
}
\author{
Jeffrey A. Ryan
}

\examples{
mkFlags(DB_CREATE)
mkFlags(DB_CREATE, DB_EXCL)
mkFlags(DB_CREATE, DB_EXCL, DB_NOMMAP)
mkFlags(DB_RDONLY)

# DB_NOTHERE is not valid, throws warning
\dontrun{
mkFlags(DB_NOMMAP,DB_CONSTANT_NOT_DEFINED)
}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ misc }% __ONLY ONE__ keyword per line
\keyword{ database }% __ONLY ONE__ keyword per line
