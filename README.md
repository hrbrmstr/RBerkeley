<!-- README.md is generated from README.Rmd. Please edit that file -->
This is the resurrected code for the RBerkeley which has been archived on 2014-09-19 as vignette locations were never updated for R 3.1.0. We refer to/use it in [Data-Driven Security](http://dds.ec/) so I felt somewhat responsible to keep it going.

I've changed the autoconf and C source setup a bit for lidbdb \> 4.

This package relies on the [Oracle Berkeley DB library](http://www.oracle.com/technetwork/database/database-technologies/berkeleydb/overview/index.html) being present on the system.

<http://www.oracle.com/technetwork/database/database-technologies/berkeleydb/overview/index.html>

on debian-ish:

    sudo apt-get install libdb-dev

on os x:

    brew install berkeley-db

CentOS/RedHat require some additional work:

    sudo yum install libdb4-devel

and ensure:

    export LD_LIBRARY_PATH=/usr/lib64/libdb4
    export LDFLAGS=-L/usr/lib64/libdb0-04
    export CPPFLAGS=-I/usr/include/libdb4

are in the environment before configuring/building

Until it's on CRAN, you can do:

    devtools::install_github("hrbrmstr/RBerkeley") 

to use the package.
