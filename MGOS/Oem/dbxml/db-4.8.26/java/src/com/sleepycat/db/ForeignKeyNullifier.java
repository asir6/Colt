/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 2008-2009 Oracle.  All rights reserved.
 *
 * $Id: ForeignKeyNullifier.java 5336 2010-10-26 22:52:27Z brucedechant $ 
 */

package com.sleepycat.db;

public interface ForeignKeyNullifier {
    boolean nullifyForeignKey(SecondaryDatabase secondary, DatabaseEntry data)
	    throws DatabaseException;
}
