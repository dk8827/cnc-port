/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include <stdlib.h>
#include <time.h>
#include "misc.h"






/* IRANDOM ----------------------------------------------------------

   IRandom returns a random value between min and max inclusive.

   INPUTS:	int min and int max

   RETURNS:	int random number
*/

int IRandom(int minval, int maxval)
{
	int num,mask;

	// Keep minval and maxval straight.
	if (minval > maxval) {
		minval ^= maxval;
		maxval ^= minval;
		minval ^= maxval;
	}

	mask = Get_Random_Mask(maxval - minval);

	while( (num = (rand() & mask) + minval) > maxval ) ;
	return(num);
}

