/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 1997-2009 Oracle.  All rights reserved.
 *
 * $Id: ReplicationLeaseTimeoutException.java 5336 2010-10-26 22:52:27Z brucedechant $
 */
package com.sleepycat.db;

import com.sleepycat.db.internal.DbEnv;

/**
Thrown if a master lease has timed out.
*/
public class ReplicationLeaseTimeoutException extends DatabaseException {
    /* package */ ReplicationLeaseTimeoutException(final String s,
                                   final int errno,
                                   final DbEnv dbenv) {
        super(s, errno, dbenv);
    }
}
