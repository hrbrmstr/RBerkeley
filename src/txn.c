#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* #include "db.h" */
#include "config.h"
#include DB_HEADER
#include "RBerkeley.h"
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

/* Berkeley DB: Transaction Subsystem and Related Methods */

/* Transaction Subsystem and Related Methods */
/* {{{ rberkeley_dbenv_txn_stat_print */
SEXP rberkeley_dbenv_txn_stat_print (SEXP _dbenv, SEXP _flags) {
  DB_ENV *dbenv;
  u_int32_t flags;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  flags = (u_int32_t)INTEGER(_flags)[0];

  ret = dbenv->txn_stat_print(dbenv, flags);
  return ScalarInteger(ret);
}
/* }}} */

/* Transaction Subsystem Configuration */

/* Transaction Operations */
/* {{{ rberkeley_dbenv_txn_begin */
SEXP rberkeley_dbenv_txn_begin (SEXP _dbenv, SEXP _parent, SEXP _flags) {
  DB_ENV *dbenv;
  DB_TXN *parent, *tid;
  u_int32_t flags;
  int ret;

  flags = (u_int32_t)INTEGER(_flags)[0]; /* currently must be 0L */

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");

  if(!isNull(_parent)) {
    parent = R_ExternalPtrAddr(_parent); /* check for txnid */
  } else parent = NULL;

  ret = dbenv->txn_begin(dbenv, parent, &tid, flags);

  if(ret != 0)
    return ScalarInteger(ret);

  return R_MakeExternalPtr(tid, install("DB_TXN"), ScalarLogical(TRUE));
}
/* }}} */
/* {{{ rberkeley_dbtxn_abort */
SEXP rberkeley_dbtxn_abort (SEXP _tid) {
  DB_TXN *tid;
  int ret;

  tid = R_ExternalPtrAddr(_tid);
  if(R_ExternalPtrTag(_tid) != RBerkeley_DB_TXN || tid == NULL)
    error("invalid 'dbtxn' handle");

  ret = tid->abort(tid);
  warning("'txnid' may not be accessed again");
  R_ClearExternalPtr(_tid);

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbtxn_commit */
SEXP rberkeley_dbtxn_commit (SEXP _tid, SEXP _flags) {
  DB_TXN *tid;
  u_int32_t flags;
  int ret;

  tid = R_ExternalPtrAddr(_tid);
  if(R_ExternalPtrTag(_tid) != RBerkeley_DB_TXN || tid == NULL)
    error("invalid 'dbtxn' handle");
  flags = (u_int32_t)INTEGER(_flags)[0];

  ret = tid->commit(tid, flags);

  warning("'txnid' may not be accessed again");
  R_ClearExternalPtr(_tid);

  return ScalarInteger(ret);
}
/* }}} */
/* rberkeley_dbtxn_discard */
/* {{{ rberkeley_dbtxn_id */
SEXP rberkeley_dbtxn_id (SEXP _tid) {
  DB_TXN *tid;
  u_int32_t ret;

  tid = R_ExternalPtrAddr(_tid);
  if(R_ExternalPtrTag(_tid) != RBerkeley_DB_TXN || tid == NULL)
    error("invalid 'dbtxn' handle");

  ret = tid->id(tid);
  Rprintf("%i, %x\n", ret, ret);

  return ScalarInteger(ret);
}
/* }}} */
/* rberkeley_dbtxn_prepare */
/* rberkeley_dbtxn_set_name */
/* rberkeley_dbtxn_set_timeout */
