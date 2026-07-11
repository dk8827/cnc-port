/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>

#include "wwstd.h"
#include "playcd.h"
#include "wwmem.h"


/***************************************************************************
 * GetCDClass -- default constructor													*
 *                                                                         *
 *                                                                         *
 *                                                                         *
 * INPUT:                                                                  *
 *       none 																					*
 * OUTPUT:                                                                 *
 *			none                          												*
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/26/1994 SW   : Created.                                            *
 *   12/4/95    ST   : fixed for Win95                                     *
 *=========================================================================*/

GetCDClass::GetCDClass(VOID)
{
	char	path[]={"a:\\"};

	CDCount = 0;
	CDIndex = 0;

	/*
	** Set all CD drive placeholders to empty
	*/
	memset (CDDrives, NO_CD_DRIVE, MAX_CD_DRIVES);


	for (char i='c' ; i<='z' ; i++){
		path[0]=i;
		if (GetDriveType (path) == DRIVE_CDROM){
			CDDrives[CDCount++] = (int) (i-'a');
		}
	}

	/*
	**	Catch the case when there are NO CD-ROM drives available
	*/
	if (CDCount == 0) {
		for (char i='a' ; i<='b' ; i++){
			path[0]=i;
			if (GetDriveType (path) == DRIVE_CDROM){
				CDDrives[CDCount++] = (int) (i-'a');
			}
		}
	}
}

/***************************************************************************
 * GetCDClass -- destructor                                                *
 *                                                                         *
 *                                                                         *
 *                                                                         *
 * INPUT:                                                                  *
 *    	none																					*
 * OUTPUT:                                                                 *
 *			none																					*
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/26/1994 SW: Created.                                               *
 *   12/4/95    ST: fixed for Win95                                        *
 *=========================================================================*/

GetCDClass::~GetCDClass(VOID)
{
//	if(cdDrive_addrp.seg)
//		DPMI_real_free(cdDrive_addrp);		// free up those conventional buffers
}

/* ==================================================================== */

