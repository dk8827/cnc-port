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
#include <dos.h>
#include <stdio.h>
#include <string.h>
#include <process.h>




/***************************************************************************
 * Find_Argv -- Checks to see if string is in arguement                		*
 *                                                                         *
 * INPUT: char *str - string to search for.                                *
 *                                                                         *
 * OUTPUT: NULL if not found else pointer to string.                       *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/14/1993  SB : Created.                                             *
 *=========================================================================*/

//static char command [ 256 ] ;
#pragma on (argsused)
char * __cdecl Find_Argv(char const)
{
	return (NULL);


#ifdef NOT_FOR_WIN95
char * __cdecl Find_Argv(char const *str)
{
	char   * ptr ;
	static   startup_flag = 0 ;

	if ( ! startup_flag )
	{
	  startup_flag = 1 ;
	  getcmd ( command )	;
	}

	if ( ! strlen(str) ) return NULL ;
	return strstr ( command , str ) ;
#endif
}






