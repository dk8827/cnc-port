/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

/*=========================================================================*/
/* The following PRIVATE functions are in this file:                       */
/*=========================================================================*/


/*= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =*/


/***************************************************************************
 * SIZE_OF_REGION -- Calculates the size of a given region                 *
 *                                                                         *
 * INPUT:	int width  - the width of the region                           *
 *				int height - the height of the region									*
 *                                                                         *
 * OUTPUT:  long - the size of the region                                  *
 *                                                                         *
 * HISTORY:                                                                *
 *   11/03/1994 PWG : Created.                                             *
 *=========================================================================*/
long Size_Of_Region(int width, int height)                                 
{
	return(width * height);
}
