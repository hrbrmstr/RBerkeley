#' BerkeleyDB Database Operations and Methods
#'
#' Low-level calls to the BerkeleyDB API. These functions simply wrap most of
#' the DB functionality and expose it at the level.
#'
#' Documentation on usage, valid arguments, and flags from the official Oracle
#' C API should be all that is required to correctly use this API.
#'
#' \tabular{ll}{ \emph{Database Cursors} \tab \emph{Description}\cr \tab \cr
#' db_cursor \tab Create a cursor \cr dbcursor_close \tab Close a cursor \cr
#' dbcursor_count \tab Return count of duplicates \cr dbcursor_del \tab Delete
#' by cursor \cr dbcursor_dup \tab Duplicate a cursor \cr dbcursor_get \tab
#' Retrieve by cursor \cr dbcursor_pget \tab Retrieve by cursor \cr
#' dbcursor_put \tab Store by cursor \cr dbcursor_set_priority \tab Set the
#' cursor's cache priority \cr }
#'
#' The user should refer to the official API documentation for the Berkeley DB
#' database available from Oracle.
#'
#' @name Cursors
#' @aliases Cursors DBC db_cursor dbcursor_close dbcursor_count dbcursor_del
#' dbcursor_dup dbcursor_pget dbcursor_set_priority dbcursor_get_priority
#' @return Varies by function call.
#' @author Jeffrey A. Ryan for the R API
#' @references Oracle Berkeley DB\cr
#'     \url{http://www.oracle.com/technetwork/database/database-technologies/berkeleydb/overview/index.html}\cr\cr
#'     Oracle Berkeley DB C API\cr
#'     \url{http://docs.oracle.com/cd/E17076_04/html/gsg/C/index.html}\cr\cr Oracle
#'     Berkeley DB Reference Guide\cr
#'     \url{http://docs.oracle.com/cd/E17076_04/html/index.html}
#' @keywords database
NULL


#' BerkeleyDB Database Operations and Methods
#'
#' Low-level calls to the BerkeleyDB API. These functions simply wrap most of
#' the DB functionality and expose it at the level.
#'
#' Documentation on usage, valid arguments, and flags from the official Oracle
#' C API should be all that is required to correctly use this API.
#'
#' \tabular{ll}{ \emph{Database Operations} \tab \emph{Description}\cr \tab \cr
#' db_create \tab Create a database handle\cr db_associate* \tab Associate a
#' secondary index\cr db_close \tab Close a database\cr db_compact \tab Compact
#' a database\cr db_cursor \tab Create a cursor\cr db_del \tab Delete items
#' from a database\cr db_err* \tab Error message\cr db_errx* \tab Error
#' message\cr db_exists \tab Return if an item appears in a database\cr db_fd
#' \tab Return a file descriptor from a database\cr db_get \tab Get items from
#' a database\cr db_pget* \tab Get items from a database\cr db_get_byteswapped
#' \tab Return if the underlying database is in host order\cr db_get_type \tab
#' Return the database type\cr db_join* \tab Perform a database join on
#' cursors\cr db_key_range \tab Return estimate of key location\cr db_open \tab
#' Open a database\cr db_put \tab Store items into a database\cr db_remove \tab
#' Remove a database\cr db_rename \tab Rename a database\cr db_set_priority
#' \tab Set cache page priority\cr db_stat, \tab db_stat_print Database
#' statistics\cr db_sync \tab Flush a database to stable storage\cr db_truncate
#' \tab Empty a database\cr db_upgrade \tab Upgrade a database\cr db_verify*
#' \tab Verify/salvage a database\cr db_strerror \tab Error strings\cr
#' db_version \tab Return version information\cr \tab \cr \emph{Database
#' Configuration} \tab \emph{Description}\cr \tab \cr db_set_alloc* \tab Set
#' local space allocation functions\cr db_set_cachesize \tab Set the database
#' cache size\cr db_set_dup_compare* \tab Set a duplicate comparison
#' function\cr db_set_encrypt \tab Set the database cryptographic key\cr
#' db_set_errcall* \tab Set error and informational message callback\cr
#' db_set_msgcall* \tab Set error and informational message callback\cr
#' db_set_errfile \tab Set error and informational message FILE\cr
#' db_set_msgfile \tab Set error and informational message FILE\cr
#' db_set_errpfx \tab Set error message prefix\cr db_set_feedback* \tab Set
#' feedback callback\cr db_set_flags \tab General database configuration\cr
#' db_set_lorder \tab Set the database byte order\cr db_set_pagesize \tab Set
#' the underlying database page size\cr }
#'
#' The user should refer to the official API documentation for the Berkeley DB
#' database available from Oracle.
#'
#' @name Databases
#' @aliases Databases DB db_associate db_close db_compact db_del db_err db_errx
#' db_exists db_fd db_pget db_get_byteswapped db_get_type db_join db_key_range
#' db_open db_remove db_rename db_set_priority db_stat, db_sync db_truncate
#' db_upgrade db_verify db_set_alloc db_set_cachesize db_set_dup_compare
#' db_set_encrypt db_set_errcall db_set_msgcall db_set_errfile db_set_msgfile
#' db_set_errpfx db_set_feedback db_set_flags db_set_lorder db_set_pagesize
#' db_set_re_source db_get_cachesize db_get_dbname db_get_encrypt_flags
#' db_get_errpfx db_get_flags db_get_lorder db_get_mpf db_get_pagesize
#' db_get_priority db_stat_print db_strerror db_version
#' @return Varies by function call.
#' @author Jeffrey A. Ryan for the R API
#' @references Oracle Berkeley DB\cr
#' \url{http://www.oracle.com/technetwork/database/database-technologies/berkeleydb/overview/index.html}\cr\cr
#' Oracle Berkeley DB C API\cr
#' \url{http://docs.oracle.com/cd/E17076_04/html/gsg/C/index.html}\cr\cr Oracle
#' Berkeley DB Reference Guide\cr
#' \url{http://docs.oracle.com/cd/E17076_04/html/index.html}
#' @keywords database
NULL


#' BerkeleyDB Database Environment Operations
#'
#' Low-level calls to the BerkeleyDB API. These functions simply wrap most of
#' the DB functionality and expose it at the level.
#'
#' Documentation on usage, valid arguments, and flags from the official Oracle
#' C API should be all that is required to correctly use this API.
#'
#' \tabular{ll}{ \emph{Database Environment Operations} \tab \emph{Description}
#' \cr \tab \cr db_env_create \tab Create an environment handle \cr db_get_env
#' \tab Return DB's underlying DB_ENV handle \cr dbenv_close \tab Close an
#' environment \cr dbenv_dbremove \tab Remove a database \cr dbenv_dbrename
#' \tab Rename a database \cr dbenv_err* \tab Error message \cr dbenv_errx*
#' \tab Error message \cr dbenv_failchk* \tab Check for thread failure \cr
#' dbenv_fileid_reset* \tab Reset database file IDs \cr dbenv_get_home \tab
#' Return environment's home directory \cr dbenv_get_open_flags \tab Return
#' flags with which the environment was opened \cr dbenv_lsn_reset* \tab Reset
#' database file LSNs \cr dbenv_open \tab Open an environment \cr dbenv_remove
#' \tab Remove an environment \cr dbenv_stat_print \tab Environment statistics
#' \cr \tab \cr \emph{Environment Configuration} \tab \emph{Description}\cr
#' \tab \cr dbenv_set_alloc* \tab Set local space allocation functions \cr
#' dbenv_set_app_dispatch* \tab Configure application recovery \cr
#' dbenv_set_cachesize \tab Set the environment cache size \cr
#' dbenv_set_data_dir \tab Set the environment data directory \cr
#' dbenv_set_encrypt \tab Set the environment cryptographic key \cr
#' dbenv_set_errcall* \tab Set error and informational message callbacks \cr
#' dbenv_set_msgcall* \tab Set error and informational message callbacks \cr
#' dbenv_set_errfile \tab Set error and informational message FILE \cr
#' dbenv_set_msgfile \tab Set error and informational message FILE \cr
#' dbenv_set_errpfx \tab Set error message prefix \cr dbenv_set_event_notify*
#' \tab Set event notification callback \cr dbenv_set_feedback* \tab Set
#' feedback callback \cr dbenv_set_flags \tab Environment configuration \cr
#' dbenv_set_isalive* \tab Set thread is-alive callback \cr
#' dbenv_set_intermediate_dir_mode \tab Set intermediate directory creation
#' mode \cr dbenv_set_rpc_server* \tab Establish an RPC server connection \cr
#' dbenv_set_shm_key \tab Set system memory shared segment ID \cr
#' dbenv_set_thread_id* \tab Set thread of control ID function \cr
#' dbenv_set_thread_count* \tab Set approximate thread count \cr
#' dbenv_set_thread_id_string* \tab Set thread of control ID format function
#' \cr dbenv_set_timeout* \tab Set lock and transaction timeout \cr
#' dbenv_set_tmp_dir \tab Set the environment temporary file directory \cr
#' dbenv_set_verbose \tab Set verbose messages \cr }
#'
#' The user should refer to the official API documentation for the Berkeley DB
#' database available from Oracle.
#'
#' @name Environments
#' @aliases Environments db_get_env dbenv_close dbenv_dbremove dbenv_dbrename
#' dbenv_err dbenv_errx dbenv_failchk dbenv_fileid_reset dbenv_get_home
#' dbenv_get_open_flags dbenv_lsn_reset dbenv_open dbenv_remove
#' dbenv_stat_print dbenv_set_alloc dbenv_set_app_dispatch dbenv_set_cachesize
#' dbenv_get_cachesize dbenv_set_data_dir dbenv_get_data_dirs dbenv_set_encrypt
#' dbenv_set_errcall dbenv_set_msgcall dbenv_set_errfile dbenv_set_msgfile
#' dbenv_set_errpfx dbenv_get_errpfx dbenv_set_event_notify dbenv_set_feedback
#' dbenv_set_flags dbenv_get_flags dbenv_set_isalive
#' dbenv_set_intermediate_dir_mode dbenv_get_intermediate_dir_mode
#' dbenv_set_rpc_server dbenv_set_shm_key dbenv_get_shm_key dbenv_set_thread_id
#' dbenv_set_thread_count dbenv_set_thread_id_string dbenv_set_timeout
#' dbenv_set_tmp_dir dbenv_get_tmp_dir dbenv_set_verbose dbenv_get_verbose
#' dbenv_memp_stat_print
#' @return Varies by function call.
#' @author Jeffrey A. Ryan for the R API
#' @references Oracle Berkeley DB\cr
#' \url{http://www.oracle.com/technetwork/database/database-technologies/berkeleydb/overview/index.html}\cr\cr
#' Oracle Berkeley DB C API\cr
#' \url{http://docs.oracle.com/cd/E17076_04/html/gsg/C/index.html}\cr\cr Oracle
#' Berkeley DB Reference Guide\cr
#' \url{http://docs.oracle.com/cd/E17076_04/html/index.html}
#' @keywords database
NULL


#' BerkeleyDB Database Operations and Methods
#'
#' Low-level calls to the BerkeleyDB API. These functions simply wrap most of
#' the DB functionality and expose it at the level.
#'
#' Documentation on usage, valid arguments, and flags from the official Oracle
#' C API should be all that is required to correctly use this API.
#'
#' \tabular{ll}{ \emph{Mutexes} \tab \emph{Description}\cr \tab \cr
#' dbenv_mutex_alloc \tab Allocate a mutex \cr dbenv_mutex_free \tab Free a
#' mutex \cr dbenv_mutex_lock \tab Lock a mutex \cr dbenv_mutex_stat \tab Mutex
#' statistics \cr dbenv_mutex_unlock \tab Unlock a mutex \cr \tab \cr
#' \emph{Mutexes Configuration} \tab \emph{Description}\cr \tab \cr
#' dbenv_mutex_set_align* \tab Configure mutex alignment \cr
#' dbenv_mutex_set_increment* \tab Configure number of additional mutexes \cr
#' dbenv_mutex_set_max* \tab Configure total number of mutexes \cr
#' dbenv_mutex_set_tas_spins* \tab Configure test-and-set mutex spin count \cr
#' }
#'
#' The user should refer to the official API documentation for the Berkeley DB
#' database available from Oracle.
#'
#' @name Mutexes
#' @aliases Mutexes dbenv_mutex_alloc dbenv_mutex_free dbenv_mutex_lock
#' dbenv_mutex_stat dbenv_mutex_stat_print dbenv_mutex_unlock
#' dbenv_mutex_set_align dbenv_mutex_set_increment dbenv_mutex_set_max
#' dbenv_mutex_set_tas_spins
#' @return Varies by function call.
#' @author Jeffrey A. Ryan for the R API
#' @references Oracle Berkeley DB\cr
#' \url{http://www.oracle.com/technetwork/database/database-technologies/berkeleydb/overview/index.html}\cr\cr
#' Oracle Berkeley DB C API\cr
#' \url{http://docs.oracle.com/cd/E17076_04/html/gsg/C/index.html}\cr\cr Oracle
#' Berkeley DB Reference Guide\cr
#' \url{http://docs.oracle.com/cd/E17076_04/html/index.html}
#' @keywords database
NULL


#' R Interface to Embedded Oracle Berkeley DB
#'
#' Package provides a low and high level interface to the C API of the Oracle
#' Berkeley DB embedded database product.
#'
#' Initial implementation will be to provide direct access to the low-level API
#' calls in their entirety.
#'
#' The project will eventually include a higher-level interface to make using
#' the DB from R easier.
#'
#' A large part of the API had been coded, though a much smaller subset is
#' currently documented with respect to differences of design or necessity
#' between \pkg{RBerkleley} and the C-API.
#'
#' Primary difference with respect to design include the automatic
#' serialization of objects via \code{serialize}. This can be bypassed by
#' providing a RAW type vector to the \code{get} and \code{put} operations.
#'
#' From a API perspective, some functions related to threads are not yet
#' implemented, as they are not an absolute priority.  Additionally functions
#' that require C level callback function pointers have also been intentionally
#' skipped until a later time.
#'
#' All functions that appear in the \pkg{RBerkeley} documentation with an
#' asterisk next to them are currently not available in the API.
#'
#' @name RBerkeley-package
#' @aliases RBerkeley rberkeley db_stat dbenv_txn_begin dbenv_txn_stat_print
#' dbtxn_abort dbtxn_id dbtxn_commit RBerkeley-package
#' @docType package
#' @author Jeffrey A. Ryan
#' @seealso \code{\link{Databases}}, \code{\link{Environments}},
#' \code{\link{Cursors}}, \code{\link{Mutexes}}
#' @references Oracle Berkey DB\cr
#' \url{http://www.oracle.com/technetwork/database/database-technologies/berkeleydb/overview/index.html}
#' @keywords package
#' @examples
#'
#' \dontrun{
#' db_version()
#'
#' dbh <- db_create()
#'
#' # set some flags and open new db
#' db_get_flags(dbh)
#' db_set_flags(dbh,mkFlags(DB_DUP))
#' db_open(dbh,flags=mkFlags(DB_CREATE))
#' db_get_flags(dbh)
#'
#' db_get_dbname(dbh)
#'
#' # look for non-existant key
#' db_get(dbh, key="mykey")
#'
#' # add a key=>value
#' db_put(dbh, key=charToRaw("myKey"), data="myValue")
#' x <- matrix(1:10)
#' db_put(dbh, key="myKey2", data=x)
#' db_put(dbh, key="myKey3", data="newValue")
#' db_put(dbh, key="myKey4", data="myValue")
#' db_key_range(dbh, key="myKey2")
#'
#' # add a few hundred keys/values
#' system.time(
#' for(i in 1:1000)
#' {
#'   db_put(dbh, key=i, data=x)
#' }
#' )
#'
#' # get value by key
#' db_get(dbh, key="myKey2")
#' db_set_priority(dbh, priority=mkFlags(DB_PRIORITY_VERY_LOW))
#'
#' xr <- db_get(dbh, key="myKey2")
#'
#' xr
#' unserialize(xr)
#'
#' # cursors
#' dbc <- db_cursor(dbh)
#' dbc2 <- dbcursor_dup(dbc)
#' dbc2
#'
#' dbcursor_get_priority(dbc)
#' dbcursor_set_priority(dbc, flags=mkFlags(DB_PRIORITY_LOW))
#' dbcursor_get_priority(dbc)
#' dbcursor_get(dbc, key=NULL, data=NULL, flags=0L, n=1L)
#'
#' # using mkFlags for bitwise OR operations on DB constants
#' mkFlags(DB_SET);
#'
#' dbcursor_get(dbc2, key="myKey2", data=NULL, flags=mkFlags(DB_SET), n=1L)
#' dbcursor_put(dbc2, key="mynewKey", data="MyNewValue", flags=mkFlags(DB_KEYFIRST))
#' dbcursor_get(dbc2, key="myKey2", data=NULL, flags=mkFlags(DB_PREV), n=1L)
#' dbcursor_get(dbc2, key="myKey2", data=NULL, flags=mkFlags(DB_FIRST), n=1L)
#' dbcursor_get(dbc, key=NULL, data=NULL, flags=0L, n=2L) # get 2 records
#' dbcursor_close(dbc)
#' dbcursor_close(dbc2)
#'
#' dbc <- db_cursor(dbh)
#' dbcursor_get(dbc, key=NULL, data=NULL, flags=0L, n=-1L)
#' db_stat_print(dbh)
#' db_stat_print(dbh, flags=mkFlags(DB_FAST_STAT))
#' dbcursor_close(dbc)
#'
#' db_exists(dbh, NULL, "myKey2", 0L)
#' db_get(dbh,key="myKey")
#'
#' # flush to disk
#' db_sync(dbh)
#'
#' db_get_type(dbh)
#'
#' # close db
#' db_close(dbh)
#'
#' # remove (need new handle)
#' dbh <- db_create()
#' db_remove(dbh, "access.db", NULL)
#' }
#'
NULL



# In the previous version, exports were manually curated by hand in
# the NAMESPACE file.  There's broad overlap between the things that
# are listed in @aliases above and want to be @export'ed but it's
# incomplete enough overlap that it's mostly confusing.  So exports
# are listed in one big list here.
#' @export db_close
#' @export db_compact
#' @export db_cursor
#' @export db_del
#' @export db_exists
#' @export db_get
#' @export db_getP
#' @export db_get_byteswapped
#' @export db_get_byteswapped
#' @export db_get_cachesize
#' @export db_get_dbname
#' @export db_get_encrypt_flags
#' @export db_get_encrypt_flags
#' @export db_get_env
#' @export db_get_errpfx
#' @export db_get_flags
#' @export db_get_lorder
#' @export db_get_lorder
#' @export db_get_mpf
#' @export db_get_pagesize
#' @export db_get_priority
#' @export db_get_type
#' @export db_key_range
#' @export db_open
#' @export db_remove
#' @export db_rename
#' @export db_set_cachesize
#' @export db_set_encrypt
#' @export db_set_encrypt
#' @export db_set_errfile
#' @export db_set_errpfx
#' @export db_set_flags
#' @export db_set_lorder
#' @export db_set_lorder
#' @export db_set_msgfile
#' @export db_set_msgfile
#' @export db_set_pagesize
#' @export db_set_priority
#' @export db_set_re_source
#' @export db_set_re_source
#' @export db_stat
#' @export db_stat
#' @export db_stat_print
#' @export db_stat_print
#' @export db_strerror
#' @export db_sync
#' @export db_truncate
#' @export db_upgrade
#' @export db_version
#' @export dbcursor_close
#' @export dbcursor_count
#' @export dbcursor_del
#' @export dbcursor_dup
#' @export dbcursor_get
#' @export dbcursor_get_priority
#' @export dbcursor_put
#' @export dbcursor_set_priority
#' @export dbenv_close
#' @export dbenv_dbremove
#' @export dbenv_dbrename
#' @export dbenv_get_cachesize
#' @export dbenv_get_data_dirs
#' @export dbenv_get_flags
#' @export dbenv_get_home
#' @export dbenv_get_intermediate_dir_mode
#' @export dbenv_get_open_flags
#' @export dbenv_get_shm_key
#' @export dbenv_get_tmp_dir
#' @export dbenv_get_verbose
#' @export dbenv_memp_stat_print
#' @export dbenv_mutex_alloc
#' @export dbenv_mutex_free
#' @export dbenv_mutex_lock
#' @export dbenv_mutex_stat_print
#' @export dbenv_mutex_unlock
#' @export dbenv_open
#' @export dbenv_remove
#' @export dbenv_set_cachesize
#' @export dbenv_set_data_dir
#' @export dbenv_set_flags
#' @export dbenv_set_intermediate_dir_mode
#' @export dbenv_set_shm_key
#' @export dbenv_set_tmp_dir
#' @export dbenv_set_verbose
#' @export dbenv_stat_print
#' @export dbenv_txn_begin
#' @export dbenv_txn_stat_print
#' @export dbtxn_abort
#' @export dbtxn_commit
#' @export dbtxn_id
NULL
