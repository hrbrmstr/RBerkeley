#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "db.h"
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

/* Memory Pools and Related Methods */

/* Memory Pools and Related Methods */
/* {{{ rberkeley_db_get_mpf */
SEXP rberkeley_db_get_mpf (SEXP _dbp)
{
  DB *dbp;
  /*DB_MPOOLFILE *mpf;*/

  dbp = R_ExternalPtrAddr(_dbp);
  return R_MakeExternalPtr(dbp->get_mpf(dbp), R_NilValue, R_NilValue);
}
/* }}} */
/* {{{ rberkeley_dbenv_memp_stat_print */
SEXP rberkeley_dbenv_memp_stat_print (SEXP _dbenv, SEXP _flags)
{
  DB_ENV *dbenv;
  u_int32_t flags;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  flags = (u_int32_t)INTEGER(_flags)[0];

  ret = dbenv->memp_stat_print(dbenv, flags);

  return ScalarInteger(ret);
}
/* }}} */
