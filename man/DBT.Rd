\name{DBT}
\alias{DBT}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Create DBT Structure
}
\description{
Berkeley DB uses a C-level struct referred to as
a DBT (short for Data Base Thang).  This is represented
in the R code as a list of class DBT.  At present it
is only used in \code{db_get} calls to allow for
more advance operations such as partial record retrieval.
}
\usage{
DBT(data = NULL,
    size = NULL,
    ulen = NULL,
    dlen = NULL,
    doff = NULL,
    flags = NULL)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{data}{
An R object of type \sQuote{raw}.
}
  \item{size}{
The size (in bytes) of the data object. Must be integer or NULL.
}
  \item{ulen}{
The ulen attribute of DBT. Must be integer or NULL.
}
  \item{dlen}{
The dlen attribute of DBT. Used for partial get/put. Must be integer or NULL.
}
  \item{doff}{
The dlen attribute of DBT. Used for partial get/put. Must be integer or NULL.
}
  \item{flags}{
The flags to DBT. Must be 0 or a valid \code{DBT} flag.
}
}
\details{
This interface to the underlying Berkeley DB DBT structure is
currently experimental, and is only supported in limited places
in \pkg{RBerkeley}.
}
\value{
A \code{DBT} object.
}
\references{
Official Oracle Documentation for DBT structs:
\url{http://docs.oracle.com/cd/E17076_04/html/gsg/C/cstructs.html}
}
\author{
Jeffrey A. Ryan
}

\keyword{ database }
\keyword{ interface }
