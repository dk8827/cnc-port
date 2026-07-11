/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef FILETEMP_H
#define FILETEMP_H

/////////////////////////////////////////////////////////////////////
// THIS DOES NOT BELONG HERE.  IT WAS PUT HERE JUST TO GET THE THING
// TO COMPILE.  ONCE THE BUFFER AND PAGE SYSTEMS ARE PUT IN, THESE
// WILL NEED TO BE TAKEN OUT AND MODS MADE TO ANY FUNCTION USING BuffType.
// SKB 4/20/94.



/*=========================================================================*/
/* Defines and such that must go into wwstd.h										*/
/*=========================================================================*/
// Look at FileErrorType below for the IO_Error function.
//extern WORD cdecl (*cdecl IO_Error)(FileErrorType error, BYTE const *filename);
VOID cdecl Prog_End(VOID);
extern WORD Hard_Error_Occured;



//////////////////////// END OF DON'T BELONG //////////////////////////////////

#endif //FILETEMP_H
