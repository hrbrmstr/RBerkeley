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

/* Berkeley DB: Database Cursors and Related Methods */

/* {{{ rberkeley_db_cursor */
SEXP rberkeley_db_cursor (SEXP _dbp, SEXP _txnid, SEXP _flags)
{
  DB *dbp;
  DBC *dbc;
  DB_TXN *txnid;
  int ret;
  u_int32_t flags = INTEGER(_flags)[0];

  dbp = R_ExternalPtrAddr(_dbp);
  if(R_ExternalPtrTag(_dbp) != install("DB") || dbp == NULL)
    error("invalid 'db' handle");

  if(!isNull(_txnid)) {
    txnid = R_ExternalPtrAddr(_txnid);
  } else txnid = NULL;

  ret = dbp->cursor(dbp, txnid, &dbc, flags);

  if(ret != 0)
    return ScalarInteger(ret);

  return R_MakeExternalPtr(dbc, install("DBC"), ScalarLogical(TRUE));
}
/* }}} */
/* {{{ rberkeley_dbcursor_close */
SEXP rberkeley_dbcursor_close (SEXP _dbc)
{
  DBC *dbc;
  int ret;

  dbc = R_ExternalPtrAddr(_dbc);
  if(R_ExternalPtrTag(_dbc) != install("DBC") || dbc == NULL)
    error("invalid 'dbc' handle");

  ret = dbc->close(dbc);
  if(ret == 0) {
    R_ClearExternalPtr(_dbc);
  }

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbcursor_count */
SEXP rberkeley_dbcursor_count (SEXP _dbc, SEXP _flags)
{
  DBC *dbc;
  db_recno_t countp;
  u_int32_t flags;
  int ret;

  flags = (u_int32_t)INTEGER(_flags)[0]; /* unused by API, set to 0L */

  dbc = R_ExternalPtrAddr(_dbc);
  if(R_ExternalPtrTag(_dbc) != install("DBC") || dbc == NULL)
    error("invalid 'dbc' handle");

  ret = dbc->count(dbc, &countp, flags);

  if(ret != 0)
    return ScalarInteger(ret);

  return ScalarInteger((u_int32_t)countp);
}
/* }}} */
/* {{{ rberkeley_dbcursor_del */
SEXP rberkeley_dbcursor_del (SEXP _dbc, SEXP _flags)
{
  DBC *dbc;
  u_int32_t flags;
  int ret;

  dbc = R_ExternalPtrAddr(_dbc);
  if(R_ExternalPtrTag(_dbc) != install("DBC") || dbc == NULL)
    error("invalid 'dbc' handle");
  flags = (u_int32_t)INTEGER(_flags)[0];

  ret = dbc->del(dbc, flags);

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbcursor_dup */
SEXP rberkeley_dbcursor_dup (SEXP _dbc, SEXP _flags)
{
  DBC *dbc, *dbc2;
  u_int32_t flags;
  int ret;

  dbc = R_ExternalPtrAddr(_dbc);
  if(R_ExternalPtrTag(_dbc) != install("DBC") || dbc == NULL)
    error("invalid 'dbc' handle");
  flags = (u_int32_t)INTEGER(_flags)[0];

  ret = dbc->dup(dbc, &dbc2, flags);

  if(ret != 0)
    return ScalarInteger(ret);

  return R_MakeExternalPtr(dbc2, install("DBC"), ScalarLogical(TRUE));
}
/* }}} */
/* {{{ rberkeley_dbcursor_get */
SEXP rberkeley_dbcursor_get (SEXP _dbc,
                             SEXP _key,
                             SEXP _data,
                             SEXP _flags,
                             SEXP _n /* non-API flag */)
{
  DBC *dbc;
  DBT key, data;
  u_int32_t flags;
  int i, n, ret, P=0;

  flags = (u_int32_t)INTEGER(_flags)[0];
  n = (INTEGER(_n)[0] < 0) ? 100 : INTEGER(_n)[0]; /* this should be _all_ data */

  dbc = R_ExternalPtrAddr(_dbc);
  if(R_ExternalPtrTag(_dbc) != install("DBC") || dbc == NULL)
    error("invalid 'dbc' handle");

  memset(&key, 0, sizeof(DBT));
  memset(&data, 0, sizeof(DBT));

  SEXP Keys, Data, results;
  PROTECT(Keys = allocVector(VECSXP, n)); P++;
  PROTECT(Data = allocVector(VECSXP, n)); P++;
  PROTECT(results = allocVector(VECSXP, n)); P++;

  /*
    Two scenarios for DBcursor->get calls:
    (1) key and data are SPECIFIED <OR> key is SPECIFIED, data is EMPTY
    (2) key and data are EMPTY

    We must handle these seperately in order
    to return a sensible result
  */
  if( (!isNull(_key) &&
      !isNull(_data)) || !isNull(_key)  ) {
    /* need to handle cases where multiple results
       can be returned. Possibly given that flag
       we can instead use the last if-else branch */
    key.data = (unsigned char *)RAW(_key);
    key.size = length(_key);

    if(!isNull(_data)) {
      data.data = (unsigned char *)RAW(_data);
      data.size = length(_data);
    }

    ret = dbc->get(dbc, &key, &data, flags);
    if(ret == 0) {
      SEXP KeyData;
      PROTECT(KeyData = allocVector(VECSXP, 2));P++;

      SEXP rawkey;
      PROTECT(rawkey = allocVector(RAWSXP, key.size));
      memcpy(RAW(rawkey), key.data, key.size);
      SET_VECTOR_ELT(KeyData, 0, rawkey);
      UNPROTECT(1);

      SEXP rawdata;
      PROTECT(rawdata = allocVector(RAWSXP, data.size));
      memcpy(RAW(rawdata), data.data, data.size);
      SET_VECTOR_ELT(KeyData, 1, rawdata);
      UNPROTECT(1);

      SEXP KeyDataNames;
      PROTECT(KeyDataNames = allocVector(STRSXP,2)); P++;
      SET_STRING_ELT(KeyDataNames, 0, mkChar("key"));
      SET_STRING_ELT(KeyDataNames, 1, mkChar("data"));
      setAttrib(KeyData, R_NamesSymbol, KeyDataNames);
      SET_VECTOR_ELT(results, 0, KeyData);
      PROTECT(results = lengthgets(results, 1)); P++;
    }
  } else
  if(isNull(_key) && isNull(_data)) {
    for(i = 0; i < n; i++) {
      ret = dbc->get(dbc, &key, &data, flags);
      if(ret == 0) {
        SEXP KeyData;
        PROTECT(KeyData = allocVector(VECSXP, 2));

        SEXP rawkey;
        PROTECT(rawkey = allocVector(RAWSXP, key.size));
        memcpy(RAW(rawkey), key.data, key.size);
        SET_VECTOR_ELT(KeyData, 0, rawkey);

        SEXP rawdata;
        PROTECT(rawdata = allocVector(RAWSXP, data.size));
        memcpy(RAW(rawdata), data.data, data.size);
        SET_VECTOR_ELT(KeyData, 1, rawdata);

        SEXP KeyDataNames;
        PROTECT(KeyDataNames = allocVector(STRSXP,2));
        SET_STRING_ELT(KeyDataNames, 0, mkChar("key"));
        SET_STRING_ELT(KeyDataNames, 1, mkChar("data"));
        setAttrib(KeyData, R_NamesSymbol, KeyDataNames);
        SET_VECTOR_ELT(results, i, KeyData);
        UNPROTECT(4); /* KeyDataNames, rawdata, rawkey, KeyData */
      } else { /* end of data */
        if(i == 0) { /* no results */
          UNPROTECT(P);
          return ScalarInteger(ret);
        }
        /* truncate the keys and data to the i-size found */
        PROTECT(results = lengthgets(results, i)); P++;
        break;
      }
    }
  }
  UNPROTECT(P);
  return results;
}
/* }}} */
/* {{{ rberkeley_dbcursor_put */
SEXP rberkeley_dbcursor_put (SEXP _dbc, SEXP _key, SEXP _data, SEXP _flags)
{
  DBC *dbc;
  DBT key, data;
  u_int32_t flags;
  int ret;

  flags = (u_int32_t)INTEGER(_flags)[0];
  if(flags != DB_AFTER &&
     flags != DB_BEFORE &&
     flags != DB_CURRENT &&
     flags != DB_KEYFIRST &&
     flags != DB_KEYLAST &&
     flags != DB_NODUPDATA) {
    error("incorrect flags value");
  }
  dbc = R_ExternalPtrAddr(_dbc);
  if(R_ExternalPtrTag(_dbc) != install("DBC") || dbc == NULL)
    error("invalid 'dbc' handle");

  memset(&key, 0, sizeof(DBT));
  memset(&data, 0, sizeof(DBT));

  key.data = (unsigned char *)RAW(_key);
  key.size = length(_key);

  data.data = (unsigned char *)RAW(_data);
  data.size = length(_data);

  ret = dbc->put(dbc, &key, &data, flags);

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbcursor_set_priority */
SEXP rberkeley_dbcursor_set_priority (SEXP _dbc, SEXP _priority)
{
  DBC *dbc;
  DB_CACHE_PRIORITY priority;
  int ret;

  dbc = R_ExternalPtrAddr(_dbc);
  if(R_ExternalPtrTag(_dbc) != install("DBC") || dbc == NULL)
    error("invalid 'dbc' handle");
  priority = (DB_CACHE_PRIORITY)INTEGER(_priority)[0];

  ret = dbc->set_priority(dbc, priority);

  return ScalarInteger(ret);
}
/* }}} */
/* {{{ rberkeley_dbcursor_get_priority */
SEXP rberkeley_dbcursor_get_priority (SEXP _dbc)
{
  DBC *dbc;
  DB_CACHE_PRIORITY priority;
  int ret;

  dbc = R_ExternalPtrAddr(_dbc);
  if(R_ExternalPtrTag(_dbc) != install("DBC") || dbc == NULL)
    error("invalid 'dbc' handle");

  ret = dbc->get_priority(dbc, &priority);

  if(ret != 0)
    return ScalarInteger(ret);

  switch(priority) {
    case DB_PRIORITY_VERY_LOW:
      return mkString("DB_PRIORITY_VERY_LOW");
      break;
    case DB_PRIORITY_LOW:
      return mkString("DB_PRIORITY_LOW");
      break;
    case DB_PRIORITY_DEFAULT:
      return mkString("DB_PRIORITY_DEFAULT");
      break;
    case DB_PRIORITY_HIGH:
      return mkString("DB_PRIORITY_HIGH");
      break;
    case DB_PRIORITY_VERY_HIGH:
      return mkString("DB_PRIORITY_VERY_HIGH");
      break;
    default:
      return R_NilValue;
  }
}
/* }}} */
