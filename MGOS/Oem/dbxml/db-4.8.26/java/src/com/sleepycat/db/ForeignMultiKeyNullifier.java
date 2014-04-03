/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 20008-2009 Oracle.  All rights reserved.
 *
 * $Id: ForeignMultiKeyNullifier.java 5336 2010-10-26 22:52:27Z brucedechant $
 */

package com.sleepycat.db;

public interface ForeignMultiKeyNullifier {
    boolean nullifyForeignKey(SecondaryDatabase secondary, DatabaseEntry key, DatabaseEntry data, DatabaseEntry secKey)
	    throws DatabaseException;
}
