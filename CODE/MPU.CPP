/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include	"mpu.h"


#ifdef __BORLANDC__
unsigned long __cdecl Get_CPU_Clock(unsigned long & high)
{
	__asm db 0fh,031h
	__asm mov [high],edx
	return(_EAX);
}
#endif
