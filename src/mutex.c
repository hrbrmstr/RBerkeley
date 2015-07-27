#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* #include "db.h" */
#include "config.h"
#include DB_HEADER
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

/* RBerkeley: Mutexes and Related Methods */

/* Mutexes and Related Methods */
/* {{{ rberkeley_dbenv_mutex_alloc */
SEXP rberkeley_dbenv_mutex_alloc (SEXP _dbenv, SEXP _flags)
{
  DB_ENV *dbenv;
  db_mutex_t mutexp;
  u_int32_t flags;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  flags = (u_int32_t)INTEGER(_flags)[0];

  ret = dbenv->mutex_alloc(dbenv, flags, &mutexp);

  if(ret != 0)
    return ScalarInteger(ret);

  return ScalarInteger((int)mutexp);
}
/* }}} */
/* {{{ rberkeley_dbenv_mutex_free */
SEXP rberkeley_dbenv_mutex_free (SEXP _dbenv, SEXP _mutex)
{
  DB_ENV *dbenv;
  db_mutex_t mutex;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  mutex = (db_mutex_t)INTEGER(_mutex)[0];

  ret = dbenv->mutex_free(dbenv, mutex);

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbenv_mutex_lock */
SEXP rberkeley_dbenv_mutex_lock (SEXP _dbenv, SEXP _mutex)
{
  DB_ENV *dbenv;
  db_mutex_t mutex;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  mutex = (db_mutex_t)INTEGER(_mutex)[0];

  ret = dbenv->mutex_lock(dbenv, mutex);

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbenv_mutex_stat */
/* }}} */
/* {{{ rberkeley_dbenv_mutex_stat_print */
SEXP rberkeley_dbenv_mutex_stat_print (SEXP _dbenv, SEXP _flags)
{
  DB_ENV *dbenv;
  u_int32_t flags;
  int ret;

  flags = (u_int32_t)INTEGER(_flags)[0];

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != install("DB_ENV") || dbenv == NULL)
    error("invalid 'dbenv' handle");

  ret = dbenv->mutex_stat_print(dbenv, flags);

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbenv_mutex_unlock */
SEXP rberkeley_dbenv_mutex_unlock (SEXP _dbenv, SEXP _mutex)
{
  DB_ENV *dbenv;
  db_mutex_t mutex;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  mutex = (db_mutex_t)INTEGER(_mutex)[0];

  ret = dbenv->mutex_unlock(dbenv, mutex);

  return ScalarInteger(ret);
}
/* }}} */

/* Mutex Configuration */
/* {{{ rberkeley_dbenv_mutex_set_align */
/* }}} */
/* {{{ rberkeley_dbenv_mutex_get_align */
/* }}} */
/* {{{ rberkeley_dbenv_mutex_set_increment */
/* }}} */
/* {{{ rberkeley_dbenv_mutex_get_increment */
/* }}} */
/* {{{ rberkeley_dbenv_mutex_set_max */
/* }}} */
/* {{{ rberkeley_dbenv_mutex_get_max */
/* }}} */
/* {{{ rberkeley_dbenv_mutex_tas_spins */
/* }}} */

