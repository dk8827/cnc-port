/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMREALMODE_H
#define VQMREALMODE_H

/* REALPTR: Real-mode pointer (segment:offset16).
 *
 * The REALPTR data type is used in protected mode to hold real-mode
 * pointers. The type is an unsigned long value, were the upper 16 bits
 * are the segment number and the lower 16 bit are an offset. This type
 * and the associated macros are identical to that of the PHARLAP "pltypes.h"
 * definitions for easy of conversion to WATCOM/4GW.
 */
typedef unsigned long REALPTR;

#define RP_OFF(rp) ((unsigned short)(((unsigned long)(rp)) & 0xFFFF))
#define RP_SEG(rp) ((unsigned short)(((unsigned long)(rp)) >> 16))
#define RP_SET(rp, off, seg) (rp = ((unsigned long)(seg) << 16) + (off))
#define RP_INCR(rp, incr) (rp += ((unsigned long)(incr)) & 0xFFFF)

#define MK_PTR(off, seg) (void *)((((unsigned long)seg&0xFFFF)<<4)+off)

/* RMInfo: Real-mode interrupt call structure.
 *
 * Information that needs to be passed down to the real-mode interrupt is
 * transfered using this structure. The address to this protected-mode
 * structure (allocated by user) is passed into DPMI function 0x300. DOS/4GW
 * will then use this information to set up the real-mode registers, switch
 * to real-mode and then execute the interrupt in real-mode.
 */
typedef struct _RMInfo {
	long  edi;
	long  esi;
	long  ebp;
	long  reservedbysystem;
	long  ebx;
	long  edx;
	long  ecx;
	long  eax;
	short flags;
	short es,ds,fs,gs,ip,cs,sp,ss;
} RMInfo;

#endif /* VQMREALMODE_H */

