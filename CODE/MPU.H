/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef MPU_H
#define MPU_H


/***********************************************************************************************
 * Get_CPU_Clock -- Fetches the current CPU clock time.                                        *
 *                                                                                             *
 *    This routine will return the internal Pentium clock accumulator. This accumulator is     *
 *    incremented every clock tick. Since this clock value can get very very large, the value  *
 *    returned is in 64 bits. The low half is returned directly, the high half is stored in    *
 *    location specified.                                                                      *
 *                                                                                             *
 * INPUT:   high  -- Reference to the high value of the 64 bit clock number.                   *
 *                                                                                             *
 * OUTPUT:  Returns with the low half of the CPU clock value.                                  *
 *                                                                                             *
 * WARNINGS:   This instruction is only available on Pentium or later processors.              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/17/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
unsigned long Get_CPU_Clock(unsigned long & high);
#ifndef __BORLANDC__
#pragma aux Get_CPU_Clock parm [esi] \
	modify [edx] \
	value [eax] = \
	"db 0fh,031h" \
	"mov [esi],edx"
#endif

#endif
