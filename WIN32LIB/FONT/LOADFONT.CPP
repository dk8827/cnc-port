/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include "font.h"
#include <file.h>
#include <wwmem.h>
#include <wwstd.h>

#if(IBM)
#include <fcntl.h>
#include <io.h>

#include <errno.h>

int FontXSpacing = 0;
int FontYSpacing = 0;
void const *FontPtr = NULL;
char FontWidth  = 8;
char FontHeight = 8;

// only font.c and set_font.c use the following
char *FontWidthBlockPtr = NULL;



/***************************************************************************
 * LOAD_FONT -- Loads a font from disk.                                    *
 *                                                                         *
 *    This loads a font from disk.  This function must be called as a    	*
 *    precursor to calling Set_Font().  You need only call this function 	*
 *    once per desired font at the beginning of your code, but AFTER     	*
 *    Prog_Init() is called.                                             	*
 *                                                                         *
 * INPUT:      name  - Pointer to font name to use (eg. "topaz.font")    	*
 *                                                                       	*
 *             fontsize - Size in points of the font loaded.             	*
 *                                                                       	*
 * OUTPUT:     Pointer to font data or NULL if unable to load.           	*
 *                                                                       	*
 * WARNINGS:   Some system memory is grabbed by this routine.            	*
 *                                                                       	*
 * HISTORY:                                                                *
 *   4/10/91    BS  : 2.0 compatibily                                     	*
 *   6/09/91    JLB : IBM and Amiga compatability.                        	*
 *   11/27/1991 JLB : Uses file I/O routines for disk access.              *
 *   01/29/1992 DRD : Modified to use new font format.                     *
 *   02/01/1992 DRD : Added font file verification.                        *
 *   06/29/1994 SKB : modified for 32 bit library                          *
 *=========================================================================*/
void * __cdecl Load_Font(char const *name)
{
	char	valid;
	int		fh;		// DOS file handle for font file.
	unsigned short	size;		// Size of the data in the file (-2);
	char	*ptr = NULL;		// Pointer to newly loaded font.



	fh=Open_File(name,READ);
	if ( fh>=0 ){
		if ( Read_File(fh, (char *) &size, 2) != 2) return(NULL);

		ptr = (char *) Alloc(size , MEM_NORMAL );
		*(short *)ptr = size;
		Read_File(fh, ptr + 2, size - 2);
		Close_File(fh);
	} else {
		return ((void*)errno);
	}



#ifdef cuts
	if (Find_File(name)) {
		fh = Open_File(name, READ);
		if (Read_File(fh, (char *) &size, 2) != 2) return(NULL);

		ptr = (char *) Alloc(size, MEM_NORMAL);
		*(short *)ptr = size;
		Read_File(fh, ptr + 2, size - 2);
		Close_File(fh);
	} else {
		return (NULL);
	}
#endif

	//
	// verify that the file loaded is a valid font file.
	//

	valid = FALSE;
	if (*(ptr + 2) == 0) {		// no compression
		if (*(ptr + 3) == 5) {		// currently only 5 data blocks are used.
			valid = TRUE;
		}
	}

	if ( !valid ) {
		return (NULL);
	}

   return(ptr);
}

#endif
