/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include "wwstd.h"



PRIVATE char *version = "Westwood Studios - 32 Bit Library Version "
	__DATE__
	"\r\n";

/***************************************************************************
 * VERSION -- Returns with current library version text.                   *
 *                                                                         *
 *    Use this routine to determine the current library version.  The      *
 *    version text contains the date that it was created.                  *
 *                                                                         *
 * INPUT:   none                                                           *
 *                                                                         *
 * OUTPUT:  Returns pointer to version text.                               *
 *                                                                         *
 * WARNINGS:   none                                                        *
 *                                                                         *
 * HISTORY:                                                                *
 *   07/26/1991 JLB : Created.                                             *
 *=========================================================================*/
char * __cdecl Version(void)
{
	return(version);
}
