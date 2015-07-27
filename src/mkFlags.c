/* mkFlags.c */

#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include <string.h>

#include "db.h"
/*
#include "flags.h"
#include "flags.c.h"
*/


SEXP mkFlags (SEXP _flags)
{
  char * cur_string;
  int len_flags = length(_flags);
  u_int32_t flags_bit=0x0;
  int i;

  for(i = 0; i < len_flags; i++) {
    cur_string = (char *)CHAR(STRING_ELT(_flags, i));
    if(strcmp(cur_string,"DB_BTREE")==0) {
      flags_bit = flags_bit | DB_BTREE; continue; 
    } else
    if(strcmp(cur_string,"DB_HASH")==0) {
      flags_bit = flags_bit | DB_HASH; continue; 
    } else
    if(strcmp(cur_string,"DB_QUEUE")==0) {
      flags_bit = flags_bit | DB_QUEUE; continue; 
    } else
    if(strcmp(cur_string,"DB_RECNO")==0) {
      flags_bit = flags_bit | DB_RECNO; continue; 
    } else
    if(strcmp(cur_string,"DB_UNKNOWN")==0) {
      flags_bit = flags_bit | DB_UNKNOWN; continue; 
    } else
    if(strcmp(cur_string,"DB_AGGRESSIVE")==0) {
      flags_bit = flags_bit | DB_AGGRESSIVE; continue; 
    } else
    if(strcmp(cur_string,"DB_ARCH_ABS")==0) {
      flags_bit = flags_bit | DB_ARCH_ABS; continue; 
    } else
    if(strcmp(cur_string,"DB_ARCH_DATA")==0) {
      flags_bit = flags_bit | DB_ARCH_DATA; continue; 
    } else
    if(strcmp(cur_string,"DB_ARCH_LOG")==0) {
      flags_bit = flags_bit | DB_ARCH_LOG; continue; 
    } else
    if(strcmp(cur_string,"DB_ARCH_REMOVE")==0) {
      flags_bit = flags_bit | DB_ARCH_REMOVE; continue; 
    } else
    if(strcmp(cur_string,"DB_AUTO_COMMIT")==0) {
      flags_bit = flags_bit | DB_AUTO_COMMIT; continue; 
    } else
    if(strcmp(cur_string,"DB_CDB_ALLDB")==0) {
      flags_bit = flags_bit | DB_CDB_ALLDB; continue; 
    } else
    if(strcmp(cur_string,"DB_CHKSUM")==0) {
      flags_bit = flags_bit | DB_CHKSUM; continue; 
    } else
    if(strcmp(cur_string,"DB_CKP_INTERNAL")==0) {
      flags_bit = flags_bit | DB_CKP_INTERNAL; continue; 
    } else
    if(strcmp(cur_string,"DB_CREATE")==0) {
      flags_bit = flags_bit | DB_CREATE; continue; 
    } else
    if(strcmp(cur_string,"DB_CXX_NO_EXCEPTIONS")==0) {
      flags_bit = flags_bit | DB_CXX_NO_EXCEPTIONS; continue; 
    } else
    if(strcmp(cur_string,"DB_DIRECT")==0) {
      flags_bit = flags_bit | DB_DIRECT; continue; 
    } else
    if(strcmp(cur_string,"DB_DIRECT_DB")==0) {
      flags_bit = flags_bit | DB_DIRECT_DB; continue; 
    } else
    if(strcmp(cur_string,"DB_DSYNC_DB")==0) {
      flags_bit = flags_bit | DB_DSYNC_DB; continue; 
    }  else
    if(strcmp(cur_string,"DB_DUP")==0) {
      flags_bit = flags_bit | DB_DUP; continue; 
    }  else
    if(strcmp(cur_string,"DB_DUPSORT")==0) {
      flags_bit = flags_bit | DB_DUPSORT; continue; 
    }  else
    if(strcmp(cur_string,"DB_DURABLE_UNKNOWN")==0) {
      flags_bit = flags_bit | DB_DURABLE_UNKNOWN; continue; 
    }  else
    if(strcmp(cur_string,"DB_ENCRYPT")==0) {
      flags_bit = flags_bit | DB_ENCRYPT; continue; 
    }  else
    if(strcmp(cur_string,"DB_ENCRYPT_AES")==0) {
      flags_bit = flags_bit | DB_ENCRYPT_AES; continue; 
    }  else
    if(strcmp(cur_string,"DB_EXCL")==0) {
      flags_bit = flags_bit | DB_EXCL; continue; 
    }  else
    if(strcmp(cur_string,"DB_EXTENT")==0) {
      flags_bit = flags_bit | DB_EXTENT; continue; 
    }  else
    if(strcmp(cur_string,"DB_FAST_STAT")==0) {
      flags_bit = flags_bit | DB_FAST_STAT; continue; 
    }  else
    if(strcmp(cur_string,"DB_FCNTL_LOCKING")==0) {
      flags_bit = flags_bit | DB_FCNTL_LOCKING; continue; 
    }  else
    if(strcmp(cur_string,"DB_FLUSH")==0) {
      flags_bit = flags_bit | DB_FLUSH; continue; 
    }  else
    if(strcmp(cur_string,"DB_FORCE")==0) {
      flags_bit = flags_bit | DB_FORCE; continue; 
    } 
    if(strcmp(cur_string,"DB_FOREIGN_ABORT")==0) {
      flags_bit = flags_bit | DB_FOREIGN_ABORT; continue; 
    }  else
    if(strcmp(cur_string,"DB_FOREIGN_CASCADE")==0) {
      flags_bit = flags_bit | DB_FOREIGN_CASCADE; continue; 
    }  else
    if(strcmp(cur_string,"DB_FOREIGN_NULLIFY")==0) {
      flags_bit = flags_bit | DB_FOREIGN_NULLIFY; continue; 
    }  else
    if(strcmp(cur_string,"DB_FREELIST_ONLY")==0) {
      flags_bit = flags_bit | DB_FREELIST_ONLY; continue; 
    }  else
    if(strcmp(cur_string,"DB_FREE_SPACE")==0) {
      flags_bit = flags_bit | DB_FREE_SPACE; continue; 
    }  else
    if(strcmp(cur_string,"DB_IGNORE_LEASE")==0) {
      flags_bit = flags_bit | DB_IGNORE_LEASE; continue; 
    }  else
    if(strcmp(cur_string,"DB_IMMUTABLE_KEY")==0) {
      flags_bit = flags_bit | DB_IMMUTABLE_KEY; continue; 
    }  else
    if(strcmp(cur_string,"DB_INIT_CDB")==0) {
      flags_bit = flags_bit | DB_INIT_CDB; continue; 
    }  else
    if(strcmp(cur_string,"DB_INIT_LOCK")==0) {
      flags_bit = flags_bit | DB_INIT_LOCK; continue; 
    }  else
    if(strcmp(cur_string,"DB_INIT_LOG")==0) {
      flags_bit = flags_bit | DB_INIT_LOG; continue; 
    }  else
    if(strcmp(cur_string,"DB_INIT_MPOOL")==0) {
      flags_bit = flags_bit | DB_INIT_MPOOL; continue; 
    }  else
    if(strcmp(cur_string,"DB_INIT_REP")==0) {
      flags_bit = flags_bit | DB_INIT_REP; continue; 
    }  else
    if(strcmp(cur_string,"DB_INIT_TXN")==0) {
      flags_bit = flags_bit | DB_INIT_TXN; continue; 
    }  else
    if(strcmp(cur_string,"DB_INORDER")==0) {
      flags_bit = flags_bit | DB_INORDER; continue; 
    }  else
    if(strcmp(cur_string,"DB_JOIN_NOSORT")==0) {
      flags_bit = flags_bit | DB_JOIN_NOSORT; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOCKDOWN")==0) {
      flags_bit = flags_bit | DB_LOCKDOWN; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOCK_NOWAIT")==0) {
      flags_bit = flags_bit | DB_LOCK_NOWAIT; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOCK_RECORD")==0) {
      flags_bit = flags_bit | DB_LOCK_RECORD; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOCK_SET_TIMEOUT")==0) {
      flags_bit = flags_bit | DB_LOCK_SET_TIMEOUT; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOCK_SWITCH")==0) {
      flags_bit = flags_bit | DB_LOCK_SWITCH; continue; 
    } else
    if(strcmp(cur_string,"DB_LOCK_UPGRADE")==0) {
      flags_bit = flags_bit | DB_LOCK_UPGRADE; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOG_AUTO_REMOVE")==0) {
      flags_bit = flags_bit | DB_LOG_AUTO_REMOVE; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOG_CHKPNT")==0) {
      flags_bit = flags_bit | DB_LOG_CHKPNT; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOG_COMMIT")==0) {
      flags_bit = flags_bit | DB_LOG_COMMIT; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOG_DIRECT")==0) {
      flags_bit = flags_bit | DB_LOG_DIRECT; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOG_DSYNC")==0) {
      flags_bit = flags_bit | DB_LOG_DSYNC; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOG_IN_MEMORY")==0) {
      flags_bit = flags_bit | DB_LOG_IN_MEMORY; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOG_NOCOPY")==0) {
      flags_bit = flags_bit | DB_LOG_NOCOPY; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOG_NOT_DURABLE")==0) {
      flags_bit = flags_bit | DB_LOG_NOT_DURABLE; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOG_WRNOSYNC")==0) {
      flags_bit = flags_bit | DB_LOG_WRNOSYNC; continue; 
    }  else
    if(strcmp(cur_string,"DB_LOG_ZERO")==0) {
      flags_bit = flags_bit | DB_LOG_ZERO; continue; 
    }  else
    if(strcmp(cur_string,"DB_MPOOL_CREATE")==0) {
      flags_bit = flags_bit | DB_MPOOL_CREATE; continue; 
    }  else
    if(strcmp(cur_string,"DB_MPOOL_DIRTY")==0) {
      flags_bit = flags_bit | DB_MPOOL_DIRTY; continue; 
    }  else
    if(strcmp(cur_string,"DB_MPOOL_DISCARD")==0) {
      flags_bit = flags_bit | DB_MPOOL_DISCARD; continue; 
    }  else
    if(strcmp(cur_string,"DB_MPOOL_EDIT")==0) {
      flags_bit = flags_bit | DB_MPOOL_EDIT; continue; 
    }  else
    if(strcmp(cur_string,"DB_MPOOL_FREE")==0) {
      flags_bit = flags_bit | DB_MPOOL_FREE; continue; 
    }  else
    if(strcmp(cur_string,"DB_MPOOL_LAST")==0) {
      flags_bit = flags_bit | DB_MPOOL_LAST; continue; 
    }  else
    if(strcmp(cur_string,"DB_MPOOL_NEW")==0) {
      flags_bit = flags_bit | DB_MPOOL_NEW; continue; 
    }  else
    if(strcmp(cur_string,"DB_MPOOL_NOFILE")==0) {
      flags_bit = flags_bit | DB_MPOOL_NOFILE; continue; 
    }  else
    if(strcmp(cur_string,"DB_MPOOL_NOLOCK")==0) {
      flags_bit = flags_bit | DB_MPOOL_NOLOCK; continue; 
    }  else
    if(strcmp(cur_string,"DB_MPOOL_UNLINK")==0) {
      flags_bit = flags_bit | DB_MPOOL_UNLINK; continue; 
    }  else
    if(strcmp(cur_string,"DB_MULTIPLE")==0) {
      flags_bit = flags_bit | DB_MULTIPLE; continue; 
    }  else
    if(strcmp(cur_string,"DB_MULTIPLE_KEY")==0) {
      flags_bit = flags_bit | DB_MULTIPLE_KEY; continue; 
    }  else
    if(strcmp(cur_string,"DB_MULTIVERSION")==0) {
      flags_bit = flags_bit | DB_MULTIVERSION; continue; 
    }  else
    if(strcmp(cur_string,"DB_MUTEX_ALLOCATED")==0) {
      flags_bit = flags_bit | DB_MUTEX_ALLOCATED; continue; 
    }  else
    if(strcmp(cur_string,"DB_MUTEX_LOCKED")==0) {
      flags_bit = flags_bit | DB_MUTEX_LOCKED; continue; 
    }  else
    if(strcmp(cur_string,"DB_MUTEX_LOGICAL_LOCK")==0) {
      flags_bit = flags_bit | DB_MUTEX_LOGICAL_LOCK; continue; 
    }  else
    if(strcmp(cur_string,"DB_MUTEX_PROCESS_ONLY")==0) {
      flags_bit = flags_bit | DB_MUTEX_PROCESS_ONLY; continue; 
    }  else
    if(strcmp(cur_string,"DB_MUTEX_SELF_BLOCK")==0) {
      flags_bit = flags_bit | DB_MUTEX_SELF_BLOCK; continue; 
    }  else
    if(strcmp(cur_string,"DB_NOLOCKING")==0) {
      flags_bit = flags_bit | DB_NOLOCKING; continue; 
    }  else
    if(strcmp(cur_string,"DB_NOMMAP")==0) {
      flags_bit = flags_bit | DB_NOMMAP; continue; 
    }  else
    if(strcmp(cur_string,"DB_NOORDERCHK")==0) {
      flags_bit = flags_bit | DB_NOORDERCHK; continue; 
    }  else
    if(strcmp(cur_string,"DB_NOPANIC")==0) {
      flags_bit = flags_bit | DB_NOPANIC; continue; 
    }  else
    if(strcmp(cur_string,"DB_NO_AUTO_COMMIT")==0) {
      flags_bit = flags_bit | DB_NO_AUTO_COMMIT; continue; 
    }  else
    if(strcmp(cur_string,"DB_ODDFILESIZE")==0) {
      flags_bit = flags_bit | DB_ODDFILESIZE; continue; 
    }  else
    if(strcmp(cur_string,"DB_ORDERCHKONLY")==0) {
      flags_bit = flags_bit | DB_ORDERCHKONLY; continue; 
    }  else
    if(strcmp(cur_string,"DB_OVERWRITE")==0) {
      flags_bit = flags_bit | DB_OVERWRITE; continue; 
    }  else
    if(strcmp(cur_string,"DB_PANIC_ENVIRONMENT")==0) {
      flags_bit = flags_bit | DB_PANIC_ENVIRONMENT; continue; 
    }  else
    if(strcmp(cur_string,"DB_PRINTABLE")==0) {
      flags_bit = flags_bit | DB_PRINTABLE; continue; 
    }  else
    if(strcmp(cur_string,"DB_PRIVATE")==0) {
      flags_bit = flags_bit | DB_PRIVATE; continue; 
    }  else
    if(strcmp(cur_string,"DB_PR_PAGE")==0) {
      flags_bit = flags_bit | DB_PR_PAGE; continue; 
    }  else
    if(strcmp(cur_string,"DB_PR_RECOVERYTEST")==0) {
      flags_bit = flags_bit | DB_PR_RECOVERYTEST; continue; 
    }  else
    if(strcmp(cur_string,"DB_RDONLY")==0) {
      flags_bit = flags_bit | DB_RDONLY; continue; 
    }  else
    if(strcmp(cur_string,"DB_RDWRMASTER")==0) {
      flags_bit = flags_bit | DB_RDWRMASTER; continue; 
    }  else
    if(strcmp(cur_string,"DB_READ_COMMITTED")==0) {
      flags_bit = flags_bit | DB_READ_COMMITTED; continue; 
    }  else
    if(strcmp(cur_string,"DB_READ_UNCOMMITTED")==0) {
      flags_bit = flags_bit | DB_READ_UNCOMMITTED; continue; 
    }  else
    if(strcmp(cur_string,"DB_RECNUM")==0) {
      flags_bit = flags_bit | DB_RECNUM; continue; 
    }  else
    if(strcmp(cur_string,"DB_RECOVER")==0) {
      flags_bit = flags_bit | DB_RECOVER; continue; 
    }  else
    if(strcmp(cur_string,"DB_RECOVER_FATAL")==0) {
      flags_bit = flags_bit | DB_RECOVER_FATAL; continue; 
    }  else
    if(strcmp(cur_string,"DB_REGION_INIT")==0) {
      flags_bit = flags_bit | DB_REGION_INIT; continue; 
    }  else
    if(strcmp(cur_string,"DB_REGISTER")==0) {
      flags_bit = flags_bit | DB_REGISTER; continue; 
    }  else
    if(strcmp(cur_string,"DB_RENUMBER")==0) {
      flags_bit = flags_bit | DB_RENUMBER; continue; 
    }  else
    if(strcmp(cur_string,"DB_REPMGR_CONF_2SITE_STRICT")==0) {
      flags_bit = flags_bit | DB_REPMGR_CONF_2SITE_STRICT; continue; 
    }  else
    if(strcmp(cur_string,"DB_REPMGR_PEER")==0) {
      flags_bit = flags_bit | DB_REPMGR_PEER; continue; 
    }  else
    if(strcmp(cur_string,"DB_REP_ANYWHERE")==0) {
      flags_bit = flags_bit | DB_REP_ANYWHERE; continue; 
    }  else
    if(strcmp(cur_string,"DB_REP_CLIENT")==0) {
      flags_bit = flags_bit | DB_REP_CLIENT; continue; 
    }  else
    if(strcmp(cur_string,"DB_REP_CONF_BULK")==0) {
      flags_bit = flags_bit | DB_REP_CONF_BULK; continue; 
    }  else
    if(strcmp(cur_string,"DB_REP_CONF_DELAYCLIENT")==0) {
      flags_bit = flags_bit | DB_REP_CONF_DELAYCLIENT; continue; 
    }  else
    if(strcmp(cur_string,"DB_REP_CONF_LEASE")==0) {
      flags_bit = flags_bit | DB_REP_CONF_LEASE; continue; 
    }  else
#ifdef DB_REP_CONF_NOAUTOINIT
    if(strcmp(cur_string,"DB_REP_CONF_NOAUTOINIT")==0) {
      flags_bit = flags_bit | DB_REP_CONF_NOAUTOINIT; continue; 
#else
    if(strcmp(cur_string,"DB_REP_CONF_AUTOINIT")==0) {
      flags_bit = flags_bit | DB_REP_CONF_AUTOINIT; continue; /*db-5.0 change*/
#endif
    } else
    if(strcmp(cur_string,"DB_REP_CONF_NOWAIT")==0) {
      flags_bit = flags_bit | DB_REP_CONF_NOWAIT; continue; 
    }  else
    if(strcmp(cur_string,"DB_REP_ELECTION")==0) {
      flags_bit = flags_bit | DB_REP_ELECTION; continue; 
    }  else
    if(strcmp(cur_string,"DB_REP_MASTER")==0) {
      flags_bit = flags_bit | DB_REP_MASTER; continue; 
    }  else
    if(strcmp(cur_string,"DB_REP_NOBUFFER")==0) {
      flags_bit = flags_bit | DB_REP_NOBUFFER; continue; 
    }  else
    if(strcmp(cur_string,"DB_REP_PERMANENT")==0) {
      flags_bit = flags_bit | DB_REP_PERMANENT; continue; 
    }  else
    if(strcmp(cur_string,"DB_REP_REREQUEST")==0) {
      flags_bit = flags_bit | DB_REP_REREQUEST; continue; 
    }  else
    if(strcmp(cur_string,"DB_REVSPLITOFF")==0) {
      flags_bit = flags_bit | DB_REVSPLITOFF; continue; 
    }  else
    if(strcmp(cur_string,"DB_RMW")==0) {
      flags_bit = flags_bit | DB_RMW; continue; 
    }  else
    if(strcmp(cur_string,"DB_RPCCLIENT")==0) {
#ifdef DB_RPCCLIENT
      flags_bit = flags_bit | DB_RPCCLIENT; continue; 
#else
      warning("DB_RPCCLIENT flag not supported");
#endif
    }  else
    if(strcmp(cur_string,"DB_SALVAGE")==0) {
      flags_bit = flags_bit | DB_SALVAGE; continue; 
    }  else
    if(strcmp(cur_string,"DB_SA_SKIPFIRSTKEY")==0) {
      flags_bit = flags_bit | DB_SA_SKIPFIRSTKEY; continue; 
    }  else
    if(strcmp(cur_string,"DB_SEQ_DEC")==0) {
      flags_bit = flags_bit | DB_SEQ_DEC; continue; 
    }  else
    if(strcmp(cur_string,"DB_SEQ_INC")==0) {
      flags_bit = flags_bit | DB_SEQ_INC; continue; 
    }  else
    if(strcmp(cur_string,"DB_SEQ_RANGE_SET")==0) {
      flags_bit = flags_bit | DB_SEQ_RANGE_SET; continue; 
    }  else
    if(strcmp(cur_string,"DB_SEQ_WRAP")==0) {
      flags_bit = flags_bit | DB_SEQ_WRAP; continue; 
    }  else
    if(strcmp(cur_string,"DB_SEQ_WRAPPED")==0) {
      flags_bit = flags_bit | DB_SEQ_WRAPPED; continue; 
    }  else
    if(strcmp(cur_string,"DB_SET_LOCK_TIMEOUT")==0) {
      flags_bit = flags_bit | DB_SET_LOCK_TIMEOUT; continue; 
    }  else
    if(strcmp(cur_string,"DB_SET_TXN_NOW")==0) {
      flags_bit = flags_bit | DB_SET_TXN_NOW; continue; 
    }  else
    if(strcmp(cur_string,"DB_SET_TXN_TIMEOUT")==0) {
      flags_bit = flags_bit | DB_SET_TXN_TIMEOUT; continue; 
    }  else
    if(strcmp(cur_string,"DB_SNAPSHOT")==0) {
      flags_bit = flags_bit | DB_SNAPSHOT; continue; 
    }  else
    if(strcmp(cur_string,"DB_STAT_ALL")==0) {
      flags_bit = flags_bit | DB_STAT_ALL; continue; 
    }  else
    if(strcmp(cur_string,"DB_STAT_CLEAR")==0) {
      flags_bit = flags_bit | DB_STAT_CLEAR; continue; 
    }  else
    if(strcmp(cur_string,"DB_STAT_LOCK_CONF")==0) {
      flags_bit = flags_bit | DB_STAT_LOCK_CONF; continue; 
    }  else
    if(strcmp(cur_string,"DB_STAT_LOCK_LOCKERS")==0) {
      flags_bit = flags_bit | DB_STAT_LOCK_LOCKERS; continue; 
    }  else
    if(strcmp(cur_string,"DB_STAT_LOCK_OBJECTS")==0) {
      flags_bit = flags_bit | DB_STAT_LOCK_OBJECTS; continue; 
    }  else
    if(strcmp(cur_string,"DB_STAT_LOCK_PARAMS")==0) {
      flags_bit = flags_bit | DB_STAT_LOCK_PARAMS; continue; 
    }  else
    if(strcmp(cur_string,"DB_STAT_MEMP_HASH")==0) {
      flags_bit = flags_bit | DB_STAT_MEMP_HASH; continue; 
    }  else
    if(strcmp(cur_string,"DB_STAT_MEMP_NOERROR")==0) {
      flags_bit = flags_bit | DB_STAT_MEMP_NOERROR; continue; 
    }  else
    if(strcmp(cur_string,"DB_STAT_SUBSYSTEM")==0) {
      flags_bit = flags_bit | DB_STAT_SUBSYSTEM; continue; 
    }  else
    if(strcmp(cur_string,"DB_ST_DUPOK")==0) {
      flags_bit = flags_bit | DB_ST_DUPOK; continue; 
    }  else
    if(strcmp(cur_string,"DB_ST_DUPSET")==0) {
      flags_bit = flags_bit | DB_ST_DUPSET; continue; 
    }  else
    if(strcmp(cur_string,"DB_ST_IS_RECNO")==0) {
      flags_bit = flags_bit | DB_ST_IS_RECNO; continue; 
    }  else
    if(strcmp(cur_string,"DB_ST_OVFL_LEAF")==0) {
      flags_bit = flags_bit | DB_ST_OVFL_LEAF; continue; 
    }  else
    if(strcmp(cur_string,"DB_ST_RECNUM")==0) {
      flags_bit = flags_bit | DB_ST_RECNUM; continue; 
    }  else
    if(strcmp(cur_string,"DB_ST_RELEN")==0) {
      flags_bit = flags_bit | DB_ST_RELEN; continue; 
    }  else
    if(strcmp(cur_string,"DB_ST_TOPLEVEL")==0) {
      flags_bit = flags_bit | DB_ST_TOPLEVEL; continue; 
    }  else
    if(strcmp(cur_string,"DB_SYSTEM_MEM")==0) {
      flags_bit = flags_bit | DB_SYSTEM_MEM; continue; 
    }  else
    if(strcmp(cur_string,"DB_THREAD")==0) {
      flags_bit = flags_bit | DB_THREAD; continue; 
    }  else
    if(strcmp(cur_string,"DB_TIME_NOTGRANTED")==0) {
      flags_bit = flags_bit | DB_TIME_NOTGRANTED; continue; 
    }  else
    if(strcmp(cur_string,"DB_TRUNCATE")==0) {
      flags_bit = flags_bit | DB_TRUNCATE; continue; 
    }  else
    if(strcmp(cur_string,"DB_TXN_NOSYNC")==0) {
      flags_bit = flags_bit | DB_TXN_NOSYNC; continue; 
    }  else
    if(strcmp(cur_string,"DB_TXN_NOT_DURABLE")==0) {
      flags_bit = flags_bit | DB_TXN_NOT_DURABLE; continue; 
    }  else
    if(strcmp(cur_string,"DB_TXN_NOWAIT")==0) {
      flags_bit = flags_bit | DB_TXN_NOWAIT; continue; 
    }  else
    if(strcmp(cur_string,"DB_TXN_SNAPSHOT")==0) {
      flags_bit = flags_bit | DB_TXN_SNAPSHOT; continue; 
    }  else
    if(strcmp(cur_string,"DB_TXN_SYNC")==0) {
      flags_bit = flags_bit | DB_TXN_SYNC; continue; 
    }  else
    if(strcmp(cur_string,"DB_TXN_WAIT")==0) {
      flags_bit = flags_bit | DB_TXN_WAIT; continue; 
    }  else
    if(strcmp(cur_string,"DB_TXN_WRITE_NOSYNC")==0) {
      flags_bit = flags_bit | DB_TXN_WRITE_NOSYNC; continue; 
    }  else
    if(strcmp(cur_string,"DB_UNREF")==0) {
      flags_bit = flags_bit | DB_UNREF; continue; 
    }  else
    if(strcmp(cur_string,"DB_UPGRADE")==0) {
      flags_bit = flags_bit | DB_UPGRADE; continue; 
    }  else
    if(strcmp(cur_string,"DB_USE_ENVIRON")==0) {
      flags_bit = flags_bit | DB_USE_ENVIRON; continue; 
    }  else
    if(strcmp(cur_string,"DB_USE_ENVIRON_ROOT")==0) {
      flags_bit = flags_bit | DB_USE_ENVIRON_ROOT; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_DEADLOCK")==0) {
      flags_bit = flags_bit | DB_VERB_DEADLOCK; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_FILEOPS")==0) {
      flags_bit = flags_bit | DB_VERB_FILEOPS; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_FILEOPS_ALL")==0) {
      flags_bit = flags_bit | DB_VERB_FILEOPS_ALL; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_RECOVERY")==0) {
      flags_bit = flags_bit | DB_VERB_RECOVERY; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_REGISTER")==0) {
      flags_bit = flags_bit | DB_VERB_REGISTER; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_REPLICATION")==0) {
      flags_bit = flags_bit | DB_VERB_REPLICATION; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_REPMGR_CONNFAIL")==0) {
      flags_bit = flags_bit | DB_VERB_REPMGR_CONNFAIL; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_REPMGR_MISC")==0) {
      flags_bit = flags_bit | DB_VERB_REPMGR_MISC; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_REP_ELECT")==0) {
      flags_bit = flags_bit | DB_VERB_REP_ELECT; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_REP_LEASE")==0) {
      flags_bit = flags_bit | DB_VERB_REP_LEASE; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_REP_MISC")==0) {
      flags_bit = flags_bit | DB_VERB_REP_MISC; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_REP_MSGS")==0) {
      flags_bit = flags_bit | DB_VERB_REP_MSGS; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_REP_SYNC")==0) {
      flags_bit = flags_bit | DB_VERB_REP_SYNC; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERB_WAITSFOR")==0) {
      flags_bit = flags_bit | DB_VERB_WAITSFOR; continue; 
    }  else
    if(strcmp(cur_string,"DB_VERIFY")==0) {
      flags_bit = flags_bit | DB_VERIFY; continue; 
    }  else
    if(strcmp(cur_string,"DB_WRITEOPEN")==0) {
      flags_bit = flags_bit | DB_WRITEOPEN; continue; 
    }  else
#ifdef DB_XA_CREATE /* removed in 4.8 */
    if(strcmp(cur_string,"DB_XA_CREATE")==0) {
      flags_bit = flags_bit | DB_XA_CREATE; continue; 
    }  else
#endif
    if(strcmp(cur_string,"DB_YIELDCPU")==0) {
      flags_bit = flags_bit | DB_YIELDCPU; continue; 
    }  else
    if(strcmp(cur_string,"DB_CURRENT")==0) {
      flags_bit = flags_bit | DB_CURRENT; continue; 
    }  else
    if(strcmp(cur_string,"DB_FIRST")==0) {
      flags_bit = flags_bit | DB_FIRST; continue; 
    }  else
    if(strcmp(cur_string,"DB_GET_BOTH")==0) {
      flags_bit = flags_bit | DB_GET_BOTH; continue; 
    }  else
    if(strcmp(cur_string,"DB_GET_BOTH_RANGE")==0) {
      flags_bit = flags_bit | DB_GET_BOTH_RANGE; continue; 
    }  else
    if(strcmp(cur_string,"DB_GET_RECNO")==0) {
      flags_bit = flags_bit | DB_GET_RECNO; continue; 
    }  else
    if(strcmp(cur_string,"DB_JOIN_ITEM")==0) {
      flags_bit = flags_bit | DB_JOIN_ITEM; continue; 
    }  else
    if(strcmp(cur_string,"DB_LAST")==0) {
      flags_bit = flags_bit | DB_LAST; continue; 
    }  else
    if(strcmp(cur_string,"DB_NEXT")==0) {
      flags_bit = flags_bit | DB_NEXT; continue; 
    }  else
    if(strcmp(cur_string,"DB_NEXT_DUP")==0) {
      flags_bit = flags_bit | DB_NEXT_DUP; continue; 
    }  else
    if(strcmp(cur_string,"DB_NEXT_NODUP")==0) {
      flags_bit = flags_bit | DB_NEXT_NODUP; continue; 
    }  else
    if(strcmp(cur_string,"DB_PREV")==0) {
      flags_bit = flags_bit | DB_PREV; continue; 
    }  else
    if(strcmp(cur_string,"DB_PREV_DUP")==0) {
      flags_bit = flags_bit | DB_PREV_DUP; continue; 
    }  else
    if(strcmp(cur_string,"DB_PREV_NODUP")==0) {
      flags_bit = flags_bit | DB_PREV_NODUP; continue; 
    }  else
    if(strcmp(cur_string,"DB_SET")==0) {
      flags_bit = flags_bit | DB_SET; continue; 
    }  else
    if(strcmp(cur_string,"DB_SET_RANGE")==0) {
      flags_bit = flags_bit | DB_SET_RANGE; continue; 
    }  else
    if(strcmp(cur_string,"DB_SET_RECNO")==0) {
      flags_bit = flags_bit | DB_SET_RECNO; continue; 
    }  else
    if(strcmp(cur_string,"DB_IGNORE_LEASE")==0) {
      flags_bit = flags_bit | DB_IGNORE_LEASE; continue; 
    }  else
    if(strcmp(cur_string,"DB_READ_UNCOMMITTED")==0) {
      flags_bit = flags_bit | DB_READ_UNCOMMITTED; continue; 
    }  else
    if(strcmp(cur_string,"DB_MULTIPLE")==0) {
      flags_bit = flags_bit | DB_MULTIPLE; continue; 
    }  else
    if(strcmp(cur_string,"DB_MULTIPLE_KEY")==0) {
      flags_bit = flags_bit | DB_MULTIPLE_KEY; continue; 
    }  else
    if(strcmp(cur_string,"DB_RMW")==0) {
      flags_bit = flags_bit | DB_RMW; continue; 
    }  else
    /* CURSOR FLAGS */
    if(strcmp(cur_string,"DB_AFTER")==0) {
      flags_bit = flags_bit | DB_AFTER; continue; 
    }  else
    if(strcmp(cur_string,"DB_BEFORE")==0) {
      flags_bit = flags_bit | DB_BEFORE; continue; 
    }  else
    if(strcmp(cur_string,"DB_CURRENT")==0) {
      flags_bit = flags_bit | DB_CURRENT; continue; 
    }  else
    if(strcmp(cur_string,"DB_KEYFIRST")==0) {
      flags_bit = flags_bit | DB_KEYFIRST; continue; 
    }  else
    if(strcmp(cur_string,"DB_KEYLAST")==0) {
      flags_bit = flags_bit | DB_KEYLAST; continue; 
    }  else
    if(strcmp(cur_string,"DB_NODUPDATA")==0) {
      flags_bit = flags_bit | DB_NODUPDATA; continue; 
    }  else
    if(strcmp(cur_string,"DB_PRIORITY_VERY_LOW")==0) {
      flags_bit = flags_bit | DB_PRIORITY_VERY_LOW; continue; 
    }  else
    if(strcmp(cur_string,"DB_PRIORITY_LOW")==0) {
      flags_bit = flags_bit | DB_PRIORITY_LOW; continue; 
    }  else
    if(strcmp(cur_string,"DB_PRIORITY_DEFAULT")==0) {
      flags_bit = flags_bit | DB_PRIORITY_DEFAULT; continue; 
    }  else
    if(strcmp(cur_string,"DB_PRIORITY_HIGH")==0) {
      flags_bit = flags_bit | DB_PRIORITY_HIGH; continue; 
    }  else
    if(strcmp(cur_string,"DB_PRIORITY_VERY_HIGH")==0) {
      flags_bit = flags_bit | DB_PRIORITY_VERY_HIGH; continue; 
    } else 
    if(strcmp(cur_string,"DB_DBT_MALLOC")==0) {
      flags_bit = flags_bit | DB_DBT_MALLOC; continue; 
    } else
    if(strcmp(cur_string,"DB_DBT_REALLOC")==0) {
      flags_bit = flags_bit | DB_DBT_REALLOC; continue; 
    } else
    if(strcmp(cur_string,"DB_DBT_USERMEM")==0) {
      flags_bit = flags_bit | DB_DBT_USERMEM; continue; 
    } else
    if(strcmp(cur_string,"DB_DBT_PARTIAL")==0) {
      flags_bit = flags_bit | DB_DBT_PARTIAL; continue; 
    } else
    if(strcmp(cur_string,"DB_DBT_APPMALLOC")==0) {
      flags_bit = flags_bit | DB_DBT_APPMALLOC; continue; 
    } else
    if(strcmp(cur_string,"DB_DBT_MULTIPLE")==0) {
      flags_bit = flags_bit | DB_DBT_MULTIPLE; continue; 
    } else {
      warning("unknown constant %s", cur_string);
    }

  }
  return ScalarInteger(flags_bit);  
}
