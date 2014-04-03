/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.38
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.sleepycat.db.internal;

class db_javaJNI {

	static {
		/* An alternate library name can be specified via a property. */
		String libname;
		int v_major, v_minor, v_patch;

		v_major = DbConstants.DB_VERSION_MAJOR;
		v_minor = DbConstants.DB_VERSION_MINOR;
		v_patch = DbConstants.DB_VERSION_PATCH;

		if ((libname =
		    System.getProperty("sleepycat.db.libfile")) != null)
			System.load(libname);
		else if ((libname =
		    System.getProperty("sleepycat.db.libname")) != null)
			System.loadLibrary(libname);
		else {
			String os = System.getProperty("os.name");
			if (os != null && os.startsWith("Windows")) {
				/*
				 * On Windows, library name is something like
				 * "libdb_java42.dll" or "libdb_java42d.dll".
				 */
				libname = "libdb_java" + v_major + v_minor;

				try {
					System.loadLibrary(libname);
				} catch (UnsatisfiedLinkError e) {
					try {
						libname += "d";
						System.loadLibrary(libname);
					} catch (UnsatisfiedLinkError e2) {
						throw e;
					}
				}
			} else {
				/*
				 * On UNIX, library name is something like
				 * "libdb_java-3.0.so".
				 */
				System.loadLibrary("db_java-" +
				    v_major + "." + v_minor);
			}
		}

		initialize();

		if (DbEnv_get_version_major() != v_major ||
		    DbEnv_get_version_minor() != v_minor ||
		    DbEnv_get_version_patch() != v_patch)
			throw new RuntimeException(
		      "Berkeley DB library version " + 
		      DbEnv_get_version_major() + "." +
		      DbEnv_get_version_minor() + "." + 
		      DbEnv_get_version_patch() +
		      " doesn't match Java class library version " + 
		      v_major + "." + v_minor + "." + v_patch);
	}

	static native final void initialize();

  public final static native void DbEnv_lock_vec(long jarg1, DbEnv jarg1_, int jarg2, int jarg3, com.sleepycat.db.LockRequest[] jarg4, int jarg5, int jarg6) throws com.sleepycat.db.DatabaseException;
  /* package */ final static native long initDbEnvRef0(long jarg1, DbEnv jarg1_, Object jarg2);
  /* package */ final static native long initDbRef0(long jarg1, Db jarg1_, Object jarg2);
  /* package */ final static native void deleteRef0(long jarg1);
  /* package */ final static native long getDbEnv0(long jarg1, Db jarg1_);
  public final static native long new_Db(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_associate(long jarg1, Db jarg1_, long jarg2, DbTxn jarg2_, long jarg3, Db jarg3_, boolean jarg4, int jarg5) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_associate_foreign(long jarg1, Db jarg1_, long jarg2, Db jarg2_, boolean jarg3, int jarg4) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_compact(long jarg1, Db jarg1_, long jarg2, DbTxn jarg2_, com.sleepycat.db.DatabaseEntry jarg3, com.sleepycat.db.DatabaseEntry jarg4, com.sleepycat.db.CompactStats jarg5, int jarg6, com.sleepycat.db.DatabaseEntry jarg7) throws com.sleepycat.db.DatabaseException;
  /* package */ final static native int Db_close0(long jarg1, Db jarg1_, int jarg2);
  public final static native long Db_cursor(long jarg1, Db jarg1_, long jarg2, DbTxn jarg2_, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_del(long jarg1, Db jarg1_, long jarg2, DbTxn jarg2_, com.sleepycat.db.DatabaseEntry jarg3, int jarg4) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_err(long jarg1, Db jarg1_, int jarg2, String jarg3) /* no exception */;
  public final static native void Db_errx(long jarg1, Db jarg1_, String jarg2) /* no exception */;
  public final static native int Db_exists(long jarg1, Db jarg1_, long jarg2, DbTxn jarg2_, com.sleepycat.db.DatabaseEntry jarg3, int jarg4) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get(long jarg1, Db jarg1_, long jarg2, DbTxn jarg2_, com.sleepycat.db.DatabaseEntry jarg3, com.sleepycat.db.DatabaseEntry jarg4, int jarg5) throws com.sleepycat.db.DatabaseException;
  public final static native boolean Db_get_byteswapped(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native long Db_get_cachesize(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_cachesize_ncache(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native String Db_get_create_dir(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native String Db_get_filename(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native String Db_get_dbname(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_encrypt_flags(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_flags(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_lorder(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native long Db_get_mpf(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_open_flags(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_pagesize(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_bt_minkey(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_h_ffactor(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_h_nelem(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_re_delim(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_priority(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native String[] Db_get_partition_dirs(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native com.sleepycat.db.DatabaseEntry Db_get_partition_keys(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_partition_parts(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_re_len(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_re_pad(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native String Db_get_re_source(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_q_extentsize(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native boolean Db_get_multiple(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native boolean Db_get_transactional(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_get_type(long jarg1, Db jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native long Db_join(long jarg1, Db jarg1_, Dbc[] jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_key_range(long jarg1, Db jarg1_, long jarg2, DbTxn jarg2_, com.sleepycat.db.DatabaseEntry jarg3, com.sleepycat.db.KeyRange jarg4, int jarg5) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_open(long jarg1, Db jarg1_, long jarg2, DbTxn jarg2_, String jarg3, String jarg4, int jarg5, int jarg6, int jarg7) throws com.sleepycat.db.DatabaseException, java.io.FileNotFoundException;
  public final static native int Db_pget(long jarg1, Db jarg1_, long jarg2, DbTxn jarg2_, com.sleepycat.db.DatabaseEntry jarg3, com.sleepycat.db.DatabaseEntry jarg4, com.sleepycat.db.DatabaseEntry jarg5, int jarg6) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_put(long jarg1, Db jarg1_, long jarg2, DbTxn jarg2_, com.sleepycat.db.DatabaseEntry jarg3, com.sleepycat.db.DatabaseEntry jarg4, int jarg5) throws com.sleepycat.db.DatabaseException;
  /* package */ final static native void Db_remove0(long jarg1, Db jarg1_, String jarg2, String jarg3, int jarg4);
  /* package */ final static native void Db_rename0(long jarg1, Db jarg1_, String jarg2, String jarg3, String jarg4, int jarg5);
  public final static native void Db_set_append_recno(long jarg1, Db jarg1_, boolean jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_bt_compare(long jarg1, Db jarg1_, boolean jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_bt_minkey(long jarg1, Db jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_bt_compress(long jarg1, Db jarg1_, boolean jarg2, boolean jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_bt_prefix(long jarg1, Db jarg1_, boolean jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_cachesize(long jarg1, Db jarg1_, long jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_create_dir(long jarg1, Db jarg1_, String jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_dup_compare(long jarg1, Db jarg1_, boolean jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_encrypt(long jarg1, Db jarg1_, String jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_feedback(long jarg1, Db jarg1_, boolean jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_flags(long jarg1, Db jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_h_compare(long jarg1, Db jarg1_, boolean jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_h_ffactor(long jarg1, Db jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_h_hash(long jarg1, Db jarg1_, boolean jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_h_nelem(long jarg1, Db jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_lorder(long jarg1, Db jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_pagesize(long jarg1, Db jarg1_, long jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_partition(long jarg1, Db jarg1_, int jarg2, com.sleepycat.db.DatabaseEntry jarg3, boolean jarg4) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_partition_dirs(long jarg1, Db jarg1_, String[] jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_priority(long jarg1, Db jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_re_delim(long jarg1, Db jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_re_len(long jarg1, Db jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_re_pad(long jarg1, Db jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_re_source(long jarg1, Db jarg1_, String jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_set_q_extentsize(long jarg1, Db jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_sort_multiple(long jarg1, Db jarg1_, com.sleepycat.db.DatabaseEntry jarg2, com.sleepycat.db.DatabaseEntry jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native Object Db_stat(long jarg1, Db jarg1_, long jarg2, DbTxn jarg2_, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_sync(long jarg1, Db jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native int Db_truncate(long jarg1, Db jarg1_, long jarg2, DbTxn jarg2_, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void Db_upgrade(long jarg1, Db jarg1_, String jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  /* package */ final static native boolean Db_verify0(long jarg1, Db jarg1_, String jarg2, String jarg3, java.io.OutputStream jarg4, int jarg5);
  /* package */ final static native void Dbc_close0(long jarg1, Dbc jarg1_);
  public final static native int Dbc_cmp(long jarg1, Dbc jarg1_, long jarg2, Dbc jarg2_, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native int Dbc_count(long jarg1, Dbc jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native int Dbc_del(long jarg1, Dbc jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native long Dbc_dup(long jarg1, Dbc jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native int Dbc_get(long jarg1, Dbc jarg1_, com.sleepycat.db.DatabaseEntry jarg2, com.sleepycat.db.DatabaseEntry jarg3, int jarg4) throws com.sleepycat.db.DatabaseException;
  public final static native int Dbc_get_priority(long jarg1, Dbc jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int Dbc_pget(long jarg1, Dbc jarg1_, com.sleepycat.db.DatabaseEntry jarg2, com.sleepycat.db.DatabaseEntry jarg3, com.sleepycat.db.DatabaseEntry jarg4, int jarg5) throws com.sleepycat.db.DatabaseException;
  public final static native int Dbc_put(long jarg1, Dbc jarg1_, com.sleepycat.db.DatabaseEntry jarg2, com.sleepycat.db.DatabaseEntry jarg3, int jarg4) throws com.sleepycat.db.DatabaseException;
  public final static native void Dbc_set_priority(long jarg1, Dbc jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native long new_DbEnv(int jarg1) throws com.sleepycat.db.DatabaseException;
  /* package */ final static native void DbEnv_close0(long jarg1, DbEnv jarg1_, int jarg2);
  public final static native void DbEnv_dbremove(long jarg1, DbEnv jarg1_, long jarg2, DbTxn jarg2_, String jarg3, String jarg4, int jarg5) throws com.sleepycat.db.DatabaseException, java.io.FileNotFoundException;
  public final static native void DbEnv_dbrename(long jarg1, DbEnv jarg1_, long jarg2, DbTxn jarg2_, String jarg3, String jarg4, String jarg5, int jarg6) throws com.sleepycat.db.DatabaseException, java.io.FileNotFoundException;
  public final static native void DbEnv_err(long jarg1, DbEnv jarg1_, int jarg2, String jarg3) /* no exception */;
  public final static native void DbEnv_errx(long jarg1, DbEnv jarg1_, String jarg2) /* no exception */;
  public final static native long DbEnv_cdsgroup_begin(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_fileid_reset(long jarg1, DbEnv jarg1_, String jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native String[] DbEnv_get_data_dirs(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_encrypt_flags(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_flags(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native String DbEnv_get_home(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native String DbEnv_get_intermediate_dir_mode(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_open_flags(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native long DbEnv_get_shm_key(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native String DbEnv_get_tmp_dir(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native boolean DbEnv_get_verbose(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native boolean DbEnv_is_bigendian(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_lsn_reset(long jarg1, DbEnv jarg1_, String jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_open(long jarg1, DbEnv jarg1_, String jarg2, int jarg3, int jarg4) throws com.sleepycat.db.DatabaseException, java.io.FileNotFoundException;
  /* package */ final static native void DbEnv_remove0(long jarg1, DbEnv jarg1_, String jarg2, int jarg3);
  public final static native void DbEnv_set_cachesize(long jarg1, DbEnv jarg1_, long jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_cache_max(long jarg1, DbEnv jarg1_, long jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_create_dir(long jarg1, DbEnv jarg1_, String jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_data_dir(long jarg1, DbEnv jarg1_, String jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_intermediate_dir_mode(long jarg1, DbEnv jarg1_, String jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_encrypt(long jarg1, DbEnv jarg1_, String jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_errcall(long jarg1, DbEnv jarg1_, boolean jarg2) /* no exception */;
  public final static native void DbEnv_set_flags(long jarg1, DbEnv jarg1_, int jarg2, boolean jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_feedback(long jarg1, DbEnv jarg1_, boolean jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_mp_max_openfd(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_mp_max_write(long jarg1, DbEnv jarg1_, int jarg2, long jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_mp_mmapsize(long jarg1, DbEnv jarg1_, long jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_mp_pagesize(long jarg1, DbEnv jarg1_, long jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_mp_tablesize(long jarg1, DbEnv jarg1_, long jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_msgcall(long jarg1, DbEnv jarg1_, boolean jarg2) /* no exception */;
  public final static native void DbEnv_set_paniccall(long jarg1, DbEnv jarg1_, boolean jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_rpc_server(long jarg1, DbEnv jarg1_, String jarg2, long jarg3, long jarg4, int jarg5) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_shm_key(long jarg1, DbEnv jarg1_, long jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_timeout(long jarg1, DbEnv jarg1_, long jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_tmp_dir(long jarg1, DbEnv jarg1_, String jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_tx_max(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_app_dispatch(long jarg1, DbEnv jarg1_, boolean jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_event_notify(long jarg1, DbEnv jarg1_, boolean jarg2) throws com.sleepycat.db.DatabaseException;
  /* package */ final static native void DbEnv_set_tx_timestamp0(long jarg1, DbEnv jarg1_, long jarg2);
  public final static native void DbEnv_set_verbose(long jarg1, DbEnv jarg1_, int jarg2, boolean jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native byte[][] DbEnv_get_lk_conflicts(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_lk_detect(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_lk_max_locks(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_lk_max_lockers(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_lk_max_objects(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_lk_partitions(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_lock_detect(long jarg1, DbEnv jarg1_, int jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native long DbEnv_lock_get(long jarg1, DbEnv jarg1_, int jarg2, int jarg3, com.sleepycat.db.DatabaseEntry jarg4, int jarg5) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_lock_id(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_lock_id_free(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_lock_put(long jarg1, DbEnv jarg1_, long jarg2, DbLock jarg2_) throws com.sleepycat.db.DatabaseException;
  public final static native com.sleepycat.db.LockStats DbEnv_lock_stat(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_lk_conflicts(long jarg1, DbEnv jarg1_, byte[][] jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_lk_detect(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_lk_max_lockers(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_lk_max_locks(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_lk_max_objects(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_lk_partitions(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_lg_bsize(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native String DbEnv_get_lg_dir(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_lg_filemode(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_lg_max(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_lg_regionmax(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native String[] DbEnv_log_archive(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_log_compare(com.sleepycat.db.LogSequenceNumber jarg1, com.sleepycat.db.LogSequenceNumber jarg2) /* no exception */;
  public final static native long DbEnv_log_cursor(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native String DbEnv_log_file(long jarg1, DbEnv jarg1_, com.sleepycat.db.LogSequenceNumber jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_log_flush(long jarg1, DbEnv jarg1_, com.sleepycat.db.LogSequenceNumber jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native boolean DbEnv_log_get_config(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_log_put(long jarg1, DbEnv jarg1_, com.sleepycat.db.LogSequenceNumber jarg2, com.sleepycat.db.DatabaseEntry jarg3, int jarg4) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_log_print(long jarg1, DbEnv jarg1_, long jarg2, DbTxn jarg2_, String jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_log_set_config(long jarg1, DbEnv jarg1_, int jarg2, boolean jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native com.sleepycat.db.LogStats DbEnv_log_stat(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_lg_bsize(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_lg_dir(long jarg1, DbEnv jarg1_, String jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_lg_filemode(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_lg_max(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_set_lg_regionmax(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native long DbEnv_get_cachesize(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_cachesize_ncache(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native long DbEnv_get_cache_max(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native String DbEnv_get_create_dir(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_mp_max_openfd(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_mp_max_write(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native long DbEnv_get_mp_max_write_sleep(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native long DbEnv_get_mp_mmapsize(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_mp_pagesize(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_mp_tablesize(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native com.sleepycat.db.CacheStats DbEnv_memp_stat(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native com.sleepycat.db.CacheFileStats[] DbEnv_memp_fstat(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_memp_sync(long jarg1, DbEnv jarg1_, com.sleepycat.db.LogSequenceNumber jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_memp_trickle(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_mutex_get_align(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_mutex_get_increment(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_mutex_get_max(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_mutex_get_tas_spins(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_mutex_set_align(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_mutex_set_increment(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_mutex_set_max(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_mutex_set_tas_spins(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native com.sleepycat.db.MutexStats DbEnv_mutex_stat(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_get_tx_max(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native long DbEnv_get_tx_timestamp(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native long DbEnv_get_timeout(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native long DbEnv_txn_begin(long jarg1, DbEnv jarg1_, long jarg2, DbTxn jarg2_, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_txn_checkpoint(long jarg1, DbEnv jarg1_, int jarg2, int jarg3, int jarg4) throws com.sleepycat.db.DatabaseException;
  public final static native com.sleepycat.db.PreparedTransaction[] DbEnv_txn_recover(long jarg1, DbEnv jarg1_, int jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native com.sleepycat.db.TransactionStats DbEnv_txn_stat(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native long DbEnv_rep_get_limit(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_rep_elect(long jarg1, DbEnv jarg1_, int jarg2, int jarg3, int jarg4) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_rep_process_message(long jarg1, DbEnv jarg1_, com.sleepycat.db.DatabaseEntry jarg2, com.sleepycat.db.DatabaseEntry jarg3, int jarg4, com.sleepycat.db.LogSequenceNumber jarg5) /* no exception */;
  public final static native void DbEnv_rep_flush(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_rep_set_config(long jarg1, DbEnv jarg1_, int jarg2, boolean jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_rep_set_clockskew(long jarg1, DbEnv jarg1_, int jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_rep_get_clockskew_fast(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_rep_get_clockskew_slow(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_rep_start(long jarg1, DbEnv jarg1_, com.sleepycat.db.DatabaseEntry jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_rep_sync(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native boolean DbEnv_rep_get_config(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native com.sleepycat.db.ReplicationStats DbEnv_rep_stat(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_rep_set_limit(long jarg1, DbEnv jarg1_, long jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_rep_get_request_min(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_rep_get_request_max(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_rep_set_request(long jarg1, DbEnv jarg1_, int jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_rep_set_transport(long jarg1, DbEnv jarg1_, int jarg2, boolean jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_rep_get_nsites(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_rep_get_priority(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_rep_get_timeout(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_rep_set_nsites(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_rep_set_priority(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_rep_set_timeout(long jarg1, DbEnv jarg1_, int jarg2, long jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native int DbEnv_repmgr_add_remote_site(long jarg1, DbEnv jarg1_, String jarg2, int jarg3, int jarg4) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_repmgr_get_ack_policy(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_repmgr_set_ack_policy(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_repmgr_set_local_site(long jarg1, DbEnv jarg1_, String jarg2, int jarg3, int jarg4) throws com.sleepycat.db.DatabaseException;
  public final static native com.sleepycat.db.ReplicationManagerSiteInfo[] DbEnv_repmgr_site_list(long jarg1, DbEnv jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbEnv_repmgr_start(long jarg1, DbEnv jarg1_, int jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native com.sleepycat.db.ReplicationManagerStats DbEnv_repmgr_stat(long jarg1, DbEnv jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native String DbEnv_strerror(int jarg1) /* no exception */;
  public final static native int DbEnv_get_version_major() /* no exception */;
  public final static native int DbEnv_get_version_minor() /* no exception */;
  public final static native int DbEnv_get_version_patch() /* no exception */;
  public final static native String DbEnv_get_version_string() /* no exception */;
  /* package */ final static native void delete_DbLock(long jarg1);
  /* package */ final static native void DbLogc_close0(long jarg1, DbLogc jarg1_, int jarg2);
  public final static native int DbLogc_get(long jarg1, DbLogc jarg1_, com.sleepycat.db.LogSequenceNumber jarg2, com.sleepycat.db.DatabaseEntry jarg3, int jarg4) throws com.sleepycat.db.DatabaseException;
  public final static native int DbLogc_version(long jarg1, DbLogc jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native int DbMpoolFile_get_priority(long jarg1, DbMpoolFile jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbMpoolFile_set_priority(long jarg1, DbMpoolFile jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native int DbMpoolFile_get_flags(long jarg1, DbMpoolFile jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbMpoolFile_set_flags(long jarg1, DbMpoolFile jarg1_, int jarg2, boolean jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native long DbMpoolFile_get_maxsize(long jarg1, DbMpoolFile jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbMpoolFile_set_maxsize(long jarg1, DbMpoolFile jarg1_, long jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native long new_DbSequence(long jarg1, Db jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  /* package */ final static native void DbSequence_close0(long jarg1, DbSequence jarg1_, int jarg2);
  public final static native long DbSequence_get(long jarg1, DbSequence jarg1_, long jarg2, DbTxn jarg2_, int jarg3, int jarg4) throws com.sleepycat.db.DatabaseException;
  public final static native int DbSequence_get_cachesize(long jarg1, DbSequence jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native long DbSequence_get_db(long jarg1, DbSequence jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbSequence_get_flags(long jarg1, DbSequence jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbSequence_get_key(long jarg1, DbSequence jarg1_, com.sleepycat.db.DatabaseEntry jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native long DbSequence_get_range_min(long jarg1, DbSequence jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native long DbSequence_get_range_max(long jarg1, DbSequence jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbSequence_initial_value(long jarg1, DbSequence jarg1_, long jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbSequence_open(long jarg1, DbSequence jarg1_, long jarg2, DbTxn jarg2_, com.sleepycat.db.DatabaseEntry jarg3, int jarg4) throws com.sleepycat.db.DatabaseException;
  /* package */ final static native void DbSequence_remove0(long jarg1, DbSequence jarg1_, long jarg2, DbTxn jarg2_, int jarg3);
  public final static native void DbSequence_set_cachesize(long jarg1, DbSequence jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbSequence_set_flags(long jarg1, DbSequence jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbSequence_set_range(long jarg1, DbSequence jarg1_, long jarg2, long jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native com.sleepycat.db.SequenceStats DbSequence_stat(long jarg1, DbSequence jarg1_, int jarg2) throws com.sleepycat.db.DatabaseException;
  /* package */ final static native void DbTxn_abort0(long jarg1, DbTxn jarg1_);
  /* package */ final static native void DbTxn_commit0(long jarg1, DbTxn jarg1_, int jarg2);
  /* package */ final static native void DbTxn_discard0(long jarg1, DbTxn jarg1_, int jarg2);
  public final static native String DbTxn_get_name(long jarg1, DbTxn jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native int DbTxn_id(long jarg1, DbTxn jarg1_) throws com.sleepycat.db.DatabaseException;
  public final static native void DbTxn_prepare(long jarg1, DbTxn jarg1_, byte[] jarg2) throws com.sleepycat.db.DatabaseException;
  public final static native void DbTxn_set_timeout(long jarg1, DbTxn jarg1_, long jarg2, int jarg3) throws com.sleepycat.db.DatabaseException;
  public final static native void DbTxn_set_name(long jarg1, DbTxn jarg1_, String jarg2) throws com.sleepycat.db.DatabaseException;
}
