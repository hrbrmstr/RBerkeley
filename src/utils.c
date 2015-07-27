#pragma GCC diagnostic ignored "-Wswitch"

#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include "db.h"

SEXP rberkeley_check_pointer (SEXP _dbh)
{
  int *ptr;

  if(TYPEOF(_dbh) != EXTPTRSXP) {
    warning("invalid database handle");
    return ScalarInteger(0);
  }
  ptr = R_ExternalPtrAddr(_dbh);
  if(ptr == NULL) {
    return ScalarInteger(0);
  } else return ScalarInteger(1);
}

SEXP rberkeley_fclose (SEXP _file_ptr)
{
  FILE *f;

  f = R_ExternalPtrAddr(_file_ptr);
  if(f != NULL) {
    fclose(f);
    R_ClearExternalPtr(_file_ptr);
Rprintf("file close; external pointer cleared\n");
  }
  return R_NilValue;
}

SEXP put_values_from_C (SEXP _dbp)
{
  DB *dbp;
  DBT key, data;
  int ret;

  dbp = R_ExternalPtrAddr(_dbp);

  memset(&key, 0, sizeof(DBT));
  memset(&data, 0, sizeof(DBT));

  double d = 123.4;
  key.data = &d;
  key.size = sizeof(double);

  int i = 1;
  data.data = &i;
  data.size = sizeof(int);

  ret = dbp->put(dbp, NULL, &key, &data, 0);

  return ScalarInteger(ret);
}
