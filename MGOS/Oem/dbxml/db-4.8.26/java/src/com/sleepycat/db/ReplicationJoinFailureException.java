/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 1997-2009 Oracle.  All rights reserved.
 *
 * $Id: ReplicationJoinFailureException.java 5336 2010-10-26 22:52:27Z brucedechant $
 */
package com.sleepycat.db;

import com.sleepycat.db.internal.DbEnv;

/**
Thrown if a new master has been chosen but the client is unable to synchronize
with the new master (possibly because the client has been configured
with the {@link ReplicationConfig#NOAUTOINIT} setting to turn-off automatic
internal initialization).
*/
public class ReplicationJoinFailureException extends DatabaseException {
    /* package */ ReplicationJoinFailureException(final String s,
                                   final int errno,
                                   final DbEnv dbenv) {
        super(s, errno, dbenv);
    }
}
