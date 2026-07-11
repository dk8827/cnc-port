/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include "shape.h"


/*=========================================================================*/
/* The following PRIVATE functions are in this file:                       */
/*=========================================================================*/

/*= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =*/


/***************************************************************************
 * Init_Priority_System -- set the buffer addresses for the priority		   *
 *   								system.                       						*
 *                                                                         *
 * INPUT:																						*
 *		mask - pointer	to priority buffer class										*
 *		back - pointer to background buffer class										*
 *                                                                         *
 * OUTPUT:																						*
 *		none																						*
 *                                                                         *
 * HISTORY:                                                                *
 *   08/09/1994 IML : Created.															*															
 *=========================================================================*/

VOID cdecl Init_Priority_System (GraphicBufferClass *mask,
											GraphicBufferClass *back)
{
 MaskPage = mask->Get_Buffer();
 BackGroundPage = back->Get_Buffer();
}


/************************** end of prioinit.cpp ****************************/
