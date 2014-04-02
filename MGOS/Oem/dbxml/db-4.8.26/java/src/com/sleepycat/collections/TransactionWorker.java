/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 2000-2009 Oracle.  All rights reserved.
 *
 * $Id: TransactionWorker.java 5336 2010-10-26 22:52:27Z brucedechant $
 */

package com.sleepycat.collections;

/**
 * The interface implemented to perform the work within a transaction.
 * To run a transaction, an instance of this interface is passed to the
 * {@link TransactionRunner#run} method.
 *
 * @author Mark Hayes
 */
public interface TransactionWorker {

    /**
     * Perform the work for a single transaction.
     *
     * @see TransactionRunner#run
     */
    void doWork()
        throws Exception;
}
