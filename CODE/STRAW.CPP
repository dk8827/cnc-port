/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include	"straw.h"
#include	<stddef.h>
#include	<string.h>


/***********************************************************************************************
 * Straw::~Straw -- Destructor for a straw segment.                                            *
 *                                                                                             *
 *    This destructor will remove this segment from the straw chain. If there were any         *
 *    connected segments to either side, they will be joined so that the straw chain will      *
 *    still remain linked.                                                                     *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/03/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
Straw::~Straw(void)
{
	if (ChainTo != NULL) {
		ChainTo->ChainFrom = ChainFrom;
	}
	if (ChainFrom != NULL) {
		ChainFrom->Get_From(ChainTo);
	}

	ChainFrom = NULL;
	ChainTo = NULL;
}


/***********************************************************************************************
 * Straw::Get_From -- Connect one straw segment to another.                                    *
 *                                                                                             *
 *    Use this routine to connect straw segments together. The straw segment specified as the  *
 *    parameter will be linked to the chain such that when data is requested, it will be       *
 *    fetched from the specified link before being processed by this link.                     *
 *                                                                                             *
 * INPUT:   straw -- Pointer to the straw segment that data will be fetched from.              *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/03/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void Straw::Get_From(Straw * straw)
{
	if (ChainTo != straw) {
		if (straw != NULL && straw->ChainFrom != NULL) {
			straw->ChainFrom->Get_From(NULL);
			straw->ChainFrom = NULL;
		}

		if (ChainTo != NULL) {
			ChainTo->ChainFrom = NULL;
		}

		ChainTo = straw;
		if (ChainTo != NULL) {
			ChainTo->ChainFrom = this;
		}
	}
}


/***********************************************************************************************
 * Straw::Get -- Fetch some data from the straw chain.                                         *
 *                                                                                             *
 *    Use this routine to fetch some data from the straw. It is presumed that this routine     *
 *    will be overridden to provide some useful functionality. At this level, the straw chain  *
 *    merely passes the request on to the next straw in the chain.                             *
 *                                                                                             *
 * INPUT:   source   -- Pointer to the buffer to hold the requested data.                      *
 *                                                                                             *
 *          length   -- The number of bytes requested.                                         *
 *                                                                                             *
 * OUTPUT:  Returns with the number of bytes stored into the buffer. If the number returned    *
 *          is less than the number requested, then this indicates that the straw data has     *
 *          been exhausted.                                                                    *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/03/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int Straw::Get(void * source, int slen)
{
	if (ChainTo != NULL) {
		return(ChainTo->Get(source, slen));
	}
	return(0);
}


