/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef DESCMGMT_H
#define DESCMGMT_H


#ifndef WWSTD_H
#include "wwstd.h"
#endif	   

//=====================================================================
// C type include files
#ifdef __cplusplus
extern "C" {
#endif

#include <dos.h>
#include <bios.h>

#ifdef __cplusplus
}
#endif

// ====================================================================


// types
// These where taken from dos.h
//==========================================

// external functions
// ===================================================
extern ULONG Map_Segment_To_Address(ULONG address, ULONG length);

extern "C" {
	// Assemble functions
	extern UWORD FixSelector(UWORD sel);
	extern UWORD GetDs(void);
	extern UWORD GetCs(void);
	extern VOID  GetDefaultSelectors(VOID);
	extern UWORD Get_Standard_Selector(void);

	
	// Assembly data variables
	extern UWORD CodeSelector;
	extern UWORD DataSelector;
	extern UWORD ScreenSelector;
	extern UWORD GraphicsSelector;
	extern UWORD PspSelector;
	extern UWORD EnvSelector;
	extern UWORD DosMemSelector;
	extern UWORD Fp1167Selector;
	extern UWORD FpWeitekSelector;
	extern UWORD FpCyrixSelector;
}

#endif  // DESCMGMT_H


