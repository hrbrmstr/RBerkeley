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

/* Berkeley DB: Database Environments and Related Methods */
/* Copyright Oracle (tm) */
/* R API Jeffrey A. Ryan 2009 */

/*** Database Environment Operations ***/
/* {{{ rberkeley_db_env_create */
SEXP rberkeley_db_env_create (SEXP _flags)
{
  DB_ENV *dbenvp;
  u_int32_t flags;
  int ret;

  flags = (u_int32_t)INTEGER(_flags)[0];

  ret = db_env_create(&dbenvp, flags);

  if(ret != 0)
    return ScalarInteger(ret);

  return R_MakeExternalPtr(dbenvp, RBerkeley_DB_ENV, ScalarLogical(TRUE));
}
/* }}} */
/* {{{ rberkeley_db_get_env */
SEXP rberkeley_db_get_env (SEXP _dbp)
{
  DB *dbp;
  DB_ENV *dbenv;

  dbp = R_ExternalPtrAddr(_dbp);
  if(R_ExternalPtrTag(_dbp) != install("DB") || dbp == NULL)
    error("invalid 'db' handle");

  dbenv = dbp->get_env(dbp);
  return R_MakeExternalPtr(dbenv, RBerkeley_DB_ENV, ScalarLogical(TRUE));
}
/* }}} */
/* {{{ rberkeley_dbenv_close */
SEXP rberkeley_dbenv_close (SEXP _dbenv, SEXP _flags)
{
  DB_ENV *dbenv;
  u_int32_t flags;
  int ret;

  flags = (u_int32_t)INTEGER(_flags)[0]; /* currently must be 0L */

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->close(dbenv, flags);
  if(ret == 0)
    R_ClearExternalPtr(_dbenv);

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbenv_dbremove */
SEXP rberkeley_dbenv_dbremove (SEXP _dbenv, SEXP _txnid, SEXP _file,
                               SEXP _database, SEXP _flags)
{
  DB_ENV *dbenv;
  DB_TXN *txnid;
  u_int32_t flags;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  if(!isNull(_txnid)) {
    txnid = R_ExternalPtrAddr(_txnid);
  } else txnid = NULL;
  flags = (u_int32_t)INTEGER(_flags)[0];

  ret = dbenv->dbremove(dbenv, txnid,
                        CHAR(STRING_ELT(_file,0)), CHAR(STRING_ELT(_database,0)),
                        flags);

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbenv_dbrename */
SEXP rberkeley_dbenv_dbrename (SEXP _dbenv, SEXP _txnid, SEXP _file,
                               SEXP _database, SEXP _newname, SEXP _flags)
{
  DB_ENV *dbenv;
  DB_TXN *txnid;
  u_int32_t flags;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  if(!isNull(_txnid)) {
    txnid = R_ExternalPtrAddr(_txnid);
  } else txnid = NULL;
  flags = (u_int32_t)INTEGER(_flags)[0];

  ret = dbenv->dbrename(dbenv, txnid,
                        CHAR(STRING_ELT(_file,0)), CHAR(STRING_ELT(_database,0)),
                        CHAR(STRING_ELT(_newname,0)), flags);

  return ScalarInteger(ret);
}
/* }}} */
/* rberkeley_dbenv_err */
/* rberkeley_dbenv_errx */
/* rberkeley_dbenv_failchk */
/* {{{ rberkeley_dbenv_get_home */
SEXP rberkeley_dbenv_get_home (SEXP _dbenv)
{
  DB_ENV *dbenv;
  const char * homep;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->get_home(dbenv, &homep);

  if(ret != 0)
    return ScalarInteger(ret);
  return mkString(homep);
}
/* }}} */
/* {{{ rberkeley_dbenv_get_open_flags */
SEXP rberkeley_dbenv_get_open_flags (SEXP _dbenv)
{
  DB_ENV *dbenv;
  u_int32_t flags;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->get_open_flags(dbenv, &flags);

  if(ret != 0)
    return ScalarInteger(ret);
  return ScalarInteger(flags);
}
/* }}} */
/* rberkeley_dbenv_lsn_reset */
/* {{{ rberkeley_dbenv_open */
SEXP rberkeley_dbenv_open (SEXP _dbenv, SEXP _db_home, SEXP _flags, SEXP _mode)
{
  DB_ENV *dbenv;
  u_int32_t flags;
  int ret;

  flags = (u_int32_t)INTEGER(_flags)[0];

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->open(dbenv, CHAR(STRING_ELT(_db_home,0)), flags, INTEGER(_mode)[0]);
  if(ret != 0) {
    ret = dbenv->close(dbenv, 0);
    if(ret == 0)
      R_ClearExternalPtr(_dbenv);
  }

  return ScalarInteger(ret);

}
/* }}} */
/* {{{ rberkeley_dbenv_remove */
SEXP rberkeley_dbenv_remove (SEXP _dbenv, SEXP _db_home, SEXP _flags)
{
  DB_ENV *dbenv;
  u_int32_t flags;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  flags = (u_int32_t)INTEGER(_flags)[0];

  ret = dbenv->remove(dbenv, CHAR(STRING_ELT(_db_home,0)), flags);
  warning("'dbenv' handle is no longer valid");

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbenv_stat_print */
SEXP rberkeley_dbenv_stat_print (SEXP _dbenv, SEXP _flags)
{
  DB_ENV *dbenv;
  u_int32_t flags;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  flags = (u_int32_t)INTEGER(_flags)[0];

  ret = dbenv->stat_print(dbenv, flags);

  return ScalarInteger(ret);
}
/* }}} */

/*** Environment Configuration ***/
/* rberkeley_dbenv_set_alloc */
/* rberkeley_dbenv_set_app_dispatch */
/* {{{ rberkeley_dbenv_set_cachesize */
SEXP rberkeley_dbenv_set_cachesize (SEXP _dbenv, SEXP _gbytes,
                                    SEXP _bytes, SEXP _ncache)
{
  DB_ENV *dbenv;
  int ncache, ret;
  u_int32_t gbytes, bytes;

  gbytes = (u_int32_t)INTEGER(_gbytes)[0];
   bytes = (u_int32_t)INTEGER(_bytes)[0];
  ncache = (int)INTEGER(_ncache)[0];

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->set_cachesize(dbenv, gbytes, bytes, ncache);

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbenv_get_cachesize */
SEXP rberkeley_dbenv_get_cachesize (SEXP _dbenv)
{
  DB_ENV *dbenv;
  int ncachep, ret;
  u_int32_t gbytesp, bytesp;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->get_cachesize(dbenv, &gbytesp, &bytesp, &ncachep);

  if(ret != 0)
    return ScalarInteger(ret);

  SEXP result;
  PROTECT(result = allocVector(VECSXP, 3));
  SET_VECTOR_ELT(result, 0, ScalarInteger(gbytesp));
  SET_VECTOR_ELT(result, 1, ScalarInteger(bytesp));
  SET_VECTOR_ELT(result, 2, ScalarInteger(ncachep));
  UNPROTECT(1);
  return result;
}
/* }}} */
/* {{{ rberkeley_dbenv_set_data_dir */
SEXP rberkeley_dbenv_set_data_dir (SEXP _dbenv, SEXP _dir)
{
  DB_ENV *dbenv;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->set_data_dir(dbenv, CHAR(STRING_ELT(_dir, 0)));

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbenv_get_data_dirs */
SEXP rberkeley_dbenv_get_data_dirs (SEXP _dbenv)
{
  DB_ENV *dbenv;
  const char ** dirpp;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->get_data_dirs(dbenv, &dirpp);

  if(ret != 0)
    return ScalarInteger(ret);

  return mkString(*dirpp);
}
/* }}} */
/* rberkeley_dbenv_set_encrypt */
/* rberkeley_dbenv_set_errcall */
/* rberkeley_dbenv_set_msgcall */
/* rberkeley_dbenv_set_errfile */
/* rberkeley_dbenv_set_msgfile */
/* rberkeley_dbenv_set_encrypt */
/* rberkeley_dbenv_get_encrypt_flags */
/* rberkeley_dbenv_set_errpfx */
/* rberkeley_dbenv_set_event_notify */
/* rberkeley_dbenv_set_feedback */
/* {{{ rberkeley_dbenv_set_flags */
SEXP rberkeley_dbenv_set_flags (SEXP _dbenv, SEXP _flags, SEXP _onoff)
{
  DB_ENV *dbenv;
  u_int32_t flags;
  int onoff, ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  flags = (u_int32_t)INTEGER(_flags)[0];
  onoff = INTEGER(_onoff)[0];

  ret = dbenv->set_flags(dbenv, flags, onoff);

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbenv_get_flags */
SEXP rberkeley_dbenv_get_flags  (SEXP _dbenv)
{
  DB_ENV *dbenv;
  u_int32_t flags;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->get_flags(dbenv, &flags);

  if(ret != 0)
    return ScalarInteger(ret);

  return ScalarInteger((int)flags);
}
/* }}} */
/* rberkeley_dbenv_set_isalive */
/* {{{ rberkeley_dbenv_set_intermediate_dir_mode */
SEXP rberkeley_dbenv_set_intermediate_dir_mode (SEXP _dbenv, SEXP _mode)
{
  DB_ENV *dbenv;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->set_intermediate_dir_mode (dbenv, CHAR(STRING_ELT(_mode, 0)));

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbenv_get_intermediate_dir_mode */
SEXP rberkeley_dbenv_get_intermediate_dir_mode (SEXP _dbenv)
{
  DB_ENV *dbenv;
  const char * modep;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->get_intermediate_dir_mode(dbenv, &modep);

  if(ret != 0)
    return ScalarInteger(ret);

  return mkString(modep);
}
/* }}} */
/* rberkeley_dbenv_set_rpc_server */
/* {{{ rberkeley_dbenv_set_shm_key */
SEXP rberkeley_dbenv_set_shm_key (SEXP _dbenv, SEXP _shm_key)
{
  DB_ENV *dbenv;
  long shm_key;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  shm_key = (long)INTEGER(_shm_key); /* would be better if we had longs in R ... atol? */

  ret = dbenv->set_shm_key(dbenv, shm_key);
  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbenv_get_shm_key */
SEXP rberkeley_dbenv_get_shm_key (SEXP _dbenv)
{
  DB_ENV *dbenv;
  long shm_key;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->get_shm_key(dbenv, &shm_key);

  if(ret != 0)
    return ScalarInteger(ret);

  return ScalarInteger((int)shm_key);
}
/* }}} */
/* rberkeley_dbenv_set_thread_id */
/* rberkeley_dbenv_get_thread_id */
/* rberkeley_dbenv_set_thread_id_string */
/* rberkeley_dbenv_set_timeout */
/* rberkeley_dbenv_get_timeout */
/* {{{ rberkeley_dbenv_set_tmp_dir */
SEXP rberkeley_dbenv_set_tmp_dir (SEXP _dbenv, SEXP _dir)
{
  DB_ENV *dbenv;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->set_tmp_dir(dbenv, CHAR(STRING_ELT(_dir, 0)));

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbenv_get_tmp_dir */
SEXP rberkeley_dbenv_get_tmp_dir (SEXP _dbenv)
{
  DB_ENV *dbenv;
  const char * dirp;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  ret = dbenv->get_tmp_dir(dbenv, &dirp);

  if(ret != 0)
    return ScalarInteger(ret);

  return mkString(dirp);
}
/* }}} */
/* {{{ rberkeley_dbenv_set_verbose */
SEXP rberkeley_dbenv_set_verbose (SEXP _dbenv, SEXP _which, SEXP _onoff)
{
  DB_ENV *dbenv;
  u_int32_t which;
  int onoff, ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  which = (u_int32_t)INTEGER(_which)[0];
  onoff = (int)INTEGER(_onoff)[0];

  ret = dbenv->set_verbose(dbenv, which, onoff);

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbenv_get_verbose */
SEXP rberkeley_dbenv_get_verbose (SEXP _dbenv, SEXP _which)
{
  warning("unable to get_verbose"); return R_NilValue;
  DB_ENV *dbenv;
  u_int32_t which;
  int onoffp;
  int ret;

  dbenv = R_ExternalPtrAddr(_dbenv);
  if(R_ExternalPtrTag(_dbenv) != RBerkeley_DB_ENV || dbenv == NULL)
    error("invalid 'dbenv' handle");
  which = (u_int32_t)INTEGER(_which)[0];

  ret = dbenv->get_verbose(dbenv, which, &onoffp);

  return ScalarInteger(onoffp);
}
/* }}} */
