/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 2006-2009 Oracle.  All rights reserved.
 *
 * $Id: os_abs.c 5336 2010-10-26 22:52:27Z brucedechant $
 */

#include "db_config.h"

#include "db_int.h"

/*
 * __os_abspath --
 *	Return if a path is an absolute path.
 */
int
__os_abspath(path)
	const char *path;
{
	return (path[0] == 'f' && path[1] == 's' && path[2] == ':');
}
