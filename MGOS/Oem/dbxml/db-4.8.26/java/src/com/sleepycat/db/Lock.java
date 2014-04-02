/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 2001-2009 Oracle.  All rights reserved.
 *
 * $Id: Lock.java 5336 2010-10-26 22:52:27Z brucedechant $
 */

package com.sleepycat.db;

import com.sleepycat.db.internal.DbLock;

/**
 * The locking interfaces for the database environment are methods of the
 * {@link com.sleepycat.db.Environment Environment} handle.  The {@link
 * com.sleepycat.db.Lock Lock} object is the handle for a single lock, and has
 * no methods of its own.
 */
public final class Lock {
    private DbLock dbLock;

    private Lock(final DbLock inLock) {
        this.dbLock = inLock;
        inLock.wrapper = this;
    }

    /* package */
    static Lock wrap(final DbLock dblock) {
        return (dblock == null) ? null : new Lock(dblock);
    }

    /* package */
    DbLock unwrap() {
        return dbLock;
    }
}
