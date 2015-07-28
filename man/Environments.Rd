\name{BerkeleyDB Environments}
\Rdversion{1.1}
\alias{Environments}
\alias{db_get_env}
\alias{dbenv_close}
\alias{dbenv_dbremove}
\alias{dbenv_dbrename}
\alias{dbenv_err}
\alias{dbenv_errx}
\alias{dbenv_failchk}
\alias{dbenv_fileid_reset}
\alias{dbenv_get_home}
\alias{dbenv_get_open_flags}
\alias{dbenv_lsn_reset}
\alias{dbenv_open}
\alias{dbenv_remove}
\alias{dbenv_stat_print}
\alias{dbenv_set_alloc}
\alias{dbenv_set_app_dispatch}
\alias{dbenv_set_cachesize}
\alias{dbenv_get_cachesize}
\alias{dbenv_set_data_dir}
\alias{dbenv_get_data_dirs}
\alias{dbenv_set_encrypt}
\alias{dbenv_set_errcall}
\alias{dbenv_set_msgcall}
\alias{dbenv_set_errfile}
\alias{dbenv_set_msgfile}
\alias{dbenv_set_errpfx}
\alias{dbenv_get_errpfx}
\alias{dbenv_set_event_notify}
\alias{dbenv_set_feedback}
\alias{dbenv_set_flags}
\alias{dbenv_get_flags}
\alias{dbenv_set_isalive}
\alias{dbenv_set_intermediate_dir_mode}
\alias{dbenv_get_intermediate_dir_mode}
\alias{dbenv_set_rpc_server}
\alias{dbenv_set_shm_key}
\alias{dbenv_get_shm_key}
\alias{dbenv_set_thread_id}
\alias{dbenv_set_thread_count}
\alias{dbenv_set_thread_id_string}
\alias{dbenv_set_timeout}
\alias{dbenv_set_tmp_dir}
\alias{dbenv_get_tmp_dir}
\alias{dbenv_set_verbose}
\alias{dbenv_get_verbose}
%really belongs in MemoryPool.Rd
\alias{dbenv_memp_stat_print}
\title{
BerkeleyDB Database Environment Operations
}
\description{
Low-level calls to the BerkeleyDB API. These
functions simply wrap most of the DB functionality
and expose it at the \R level.

Documentation on usage, valid arguments, and
flags from the official Oracle C API should
be all that is required to correctly use this API.

\tabular{ll}{
  \emph{Database Environment Operations} \tab \emph{Description} \cr
  \tab  \cr
  db_env_create    \tab  Create an environment handle \cr
  db_get_env    \tab Return DB's underlying DB_ENV handle \cr
  dbenv_close    \tab  Close an environment \cr
  dbenv_dbremove    \tab   Remove a database \cr
  dbenv_dbrename    \tab   Rename a database \cr
  dbenv_err*    \tab Error message \cr
  dbenv_errx*   \tab Error message \cr
  dbenv_failchk*    \tab Check for thread failure  \cr
  dbenv_fileid_reset*    \tab   Reset database file IDs  \cr
  dbenv_get_home    \tab   Return environment's home directory \cr
  dbenv_get_open_flags    \tab Return flags with which the environment was opened \cr
  dbenv_lsn_reset*    \tab  Reset database file LSNs  \cr
  dbenv_open    \tab   Open an environment \cr
  dbenv_remove    \tab Remove an environment \cr
  dbenv_stat_print    \tab Environment statistics \cr
  \tab \cr
  \emph{Environment Configuration} \tab \emph{Description}\cr
  \tab \cr
  dbenv_set_alloc*    \tab   Set local space allocation functions  \cr
  dbenv_set_app_dispatch*    \tab    Configure application recovery  \cr
  dbenv_set_cachesize    \tab   Set the environment cache size \cr
  dbenv_set_data_dir    \tab    Set the environment data directory \cr
  dbenv_set_encrypt    \tab Set the environment cryptographic key \cr
  dbenv_set_errcall*    \tab Set error and informational message callbacks  \cr
  dbenv_set_msgcall*    \tab Set error and informational message callbacks  \cr
  dbenv_set_errfile    \tab Set error and informational message FILE \cr
  dbenv_set_msgfile    \tab Set error and informational message FILE \cr
  dbenv_set_errpfx     \tab  Set error message prefix \cr
  dbenv_set_event_notify*    \tab    Set event notification callback  \cr
  dbenv_set_feedback*    \tab    Set feedback callback  \cr
  dbenv_set_flags    \tab   Environment configuration \cr
  dbenv_set_isalive*    \tab Set thread is-alive callback  \cr
  dbenv_set_intermediate_dir_mode    \tab   Set intermediate directory creation mode \cr
  dbenv_set_rpc_server*    \tab  Establish an RPC server connection  \cr
  dbenv_set_shm_key    \tab Set system memory shared segment ID \cr
  dbenv_set_thread_id*    \tab   Set thread of control ID function  \cr
  dbenv_set_thread_count*    \tab    Set approximate thread count  \cr
  dbenv_set_thread_id_string*    \tab    Set thread of control ID format function  \cr
  dbenv_set_timeout*    \tab Set lock and transaction timeout  \cr
  dbenv_set_tmp_dir    \tab Set the environment temporary file directory \cr
  dbenv_set_verbose    \tab Set verbose messages \cr
}
}
%- maybe also 'usage' for other objects documented here.
\details{
The user should refer to the official API documentation for the
Berkeley DB database available from Oracle.
}
\value{
Varies by function call.
}
\references{
Oracle Berkeley DB\cr
\url{http://www.oracle.com/technetwork/database/database-technologies/berkeleydb/overview/index.html}\cr\cr
Oracle Berkeley DB C API\cr
\url{http://docs.oracle.com/cd/E17076_04/html/gsg/C/index.html}\cr\cr
Oracle Berkeley DB Reference Guide\cr
\url{http://docs.oracle.com/cd/E17076_04/html/index.html}
}
\author{
Jeffrey A. Ryan for the R API
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ database }
