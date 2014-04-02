/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.38
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.sleepycat.db.internal;

import com.sleepycat.db.*;
import java.util.Comparator;

public class DbSequence {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected DbSequence(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(DbSequence obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  /* package */ synchronized void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      throw new UnsupportedOperationException("C++ destructor does not have public access");
    }
    swigCPtr = 0;
  }

	public Sequence wrapper;

	public synchronized void close(int flags) throws DatabaseException {
		try {
			close0(flags);
		} finally {
			swigCPtr = 0;
		}
	}

	public synchronized void remove(DbTxn txn, int flags)
	    throws DatabaseException {
		try {
			remove0(txn, flags);
		} finally {
			swigCPtr = 0;
		}
	}

  public DbSequence(Db db, int flags) throws com.sleepycat.db.DatabaseException {
    this(db_javaJNI.new_DbSequence(Db.getCPtr(db), db, flags), true);
  }

  /* package */ void close0(int flags) { db_javaJNI.DbSequence_close0(swigCPtr, this, flags); }

  public long get(DbTxn txnid, int delta, int flags) throws com.sleepycat.db.DatabaseException { return db_javaJNI.DbSequence_get(swigCPtr, this, DbTxn.getCPtr(txnid), txnid, delta, flags); }

  public int get_cachesize() throws com.sleepycat.db.DatabaseException { return db_javaJNI.DbSequence_get_cachesize(swigCPtr, this); }

  public Db get_db() throws com.sleepycat.db.DatabaseException {
    long cPtr = db_javaJNI.DbSequence_get_db(swigCPtr, this);
    return (cPtr == 0) ? null : new Db(cPtr, false);
  }

  public int get_flags() throws com.sleepycat.db.DatabaseException { return db_javaJNI.DbSequence_get_flags(swigCPtr, this); }

  public void get_key(com.sleepycat.db.DatabaseEntry key) throws com.sleepycat.db.DatabaseException { db_javaJNI.DbSequence_get_key(swigCPtr, this, key); }

  public long get_range_min() throws com.sleepycat.db.DatabaseException { return db_javaJNI.DbSequence_get_range_min(swigCPtr, this); }

  public long get_range_max() throws com.sleepycat.db.DatabaseException { return db_javaJNI.DbSequence_get_range_max(swigCPtr, this); }

  public void initial_value(long val) throws com.sleepycat.db.DatabaseException { db_javaJNI.DbSequence_initial_value(swigCPtr, this, val); }

  public void open(DbTxn txnid, com.sleepycat.db.DatabaseEntry key, int flags) throws com.sleepycat.db.DatabaseException { db_javaJNI.DbSequence_open(swigCPtr, this, DbTxn.getCPtr(txnid), txnid, key, flags); }

  /* package */ void remove0(DbTxn txnid, int flags) { db_javaJNI.DbSequence_remove0(swigCPtr, this, DbTxn.getCPtr(txnid), txnid, flags); }

  public void set_cachesize(int size) throws com.sleepycat.db.DatabaseException { db_javaJNI.DbSequence_set_cachesize(swigCPtr, this, size); }

  public void set_flags(int flags) throws com.sleepycat.db.DatabaseException { db_javaJNI.DbSequence_set_flags(swigCPtr, this, flags); }

  public void set_range(long min, long max) throws com.sleepycat.db.DatabaseException { db_javaJNI.DbSequence_set_range(swigCPtr, this, min, max); }

  public com.sleepycat.db.SequenceStats stat(int flags) throws com.sleepycat.db.DatabaseException { return db_javaJNI.DbSequence_stat(swigCPtr, this, flags); }

}
