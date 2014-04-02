/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 2008-2009 Oracle.  All rights reserved.
 *
 * $Id: SimpleEntityClass.java 5336 2010-10-26 22:52:27Z brucedechant $ 
 */

package persist.gettingStarted;

import com.sleepycat.persist.model.Entity;
import com.sleepycat.persist.model.PrimaryKey;
import static com.sleepycat.persist.model.Relationship.*;
import com.sleepycat.persist.model.SecondaryKey;

@Entity
public class SimpleEntityClass {

    // Primary key is pKey
    @PrimaryKey
    private String pKey;

    // Secondary key is the sKey
    @SecondaryKey(relate=MANY_TO_ONE)
    private String sKey;

    public void setpKey(String data) {
        pKey = data;
    }

    public void setsKey(String data) {
        sKey = data;
    }

    public String getpKey() {
        return pKey;
    }

    public String getsKey() {
        return sKey;
    }
}
