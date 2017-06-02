/*
	This file is part of Warzone 2100.
	Copyright (C) 1999-2004  Eidos Interactive
	Copyright (C) 2005-2017  Warzone 2100 Project

	Warzone 2100 is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	Warzone 2100 is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Warzone 2100; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/
/** @file
 *  Common functions for the scriptvals loader
 */

#ifndef __INCLUDED_SRC_SCRIPTVALS_H__
#define __INCLUDED_SRC_SCRIPTVALS_H__

#include "lib/script/interpreter.h"
#include <physfs.h>

struct SCRIPT_CONTEXT;

// The possible types of initialisation values
enum INIT_TYPE
{
	IT_BOOL,
	IT_INDEX,
	IT_STRING,
};


// All the possible values that may be used to initialise a variable
struct VAR_INIT
{
	INIT_TYPE	type;
	SDWORD		index;
	char		*pString;
};


// store array access data
struct ARRAY_INDEXES
{
	SDWORD		dimensions;
	SDWORD		elements[VAR_MAX_DIMENSIONS];
};

/* A simple error reporting routine */

void scrv_error(const char *fmt, ...);

// Lookup a type
bool scrvLookUpType(const char *pIdent, INTERP_TYPE *pType);

// Lookup a variable identifier
bool scrvLookUpVar(const char *pIdent, UDWORD *pIndex);

// Lookup an array identifier
bool scrvLookUpArray(const char *pIdent, UDWORD *pIndex);

// Whether the script is run immediately or stored for later use
enum SCRV_TYPE
{
	SCRV_EXEC,
	SCRV_NOEXEC,
};

// Add a new context to the list
bool scrvAddContext(char *pID, SCRIPT_CONTEXT *psContext, SCRV_TYPE type);

// Get a context from the list
bool scrvGetContext(char *pID, SCRIPT_CONTEXT **ppsContext);

// Add a new base pointer variable
bool scrvAddBasePointer(INTERP_VAL *psVal);

// Check all the base pointers to see if they have died
void scrvUpdateBasePointers();

// remove a base pointer from the list
void scrvReleaseBasePointer(INTERP_VAL *psVal);

// create a group structure for a ST_GROUP variable
bool scrvNewGroup(INTERP_VAL *psVal);

// release a ST_GROUP variable
void scrvReleaseGroup(INTERP_VAL *psVal);

// Initialise the script value module
bool scrvInitialise();

// Shut down the script value module
void scrvShutDown();

// reset the script value module
void scrvReset();

// Load a script value file
bool scrvLoad(PHYSFS_file *fileHandle);

#endif // __INCLUDED_SRC_SCRIPTVALS_H__
