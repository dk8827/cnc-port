/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQAUNVQ_H
#define VQAUNVQ_H

#ifdef PHARLAP_TNT
#include <pltypes.h>
#endif

/*---------------------------------------------------------------------------
 * FUNCTION PROTOTYPES
 *-------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/* unvqbuff.asm */
#ifndef PHARLAP_TNT
void __cdecl UnVQ_2x2(unsigned char *codebook, unsigned char *pointers,
		unsigned char *buffer, unsigned long blocksperrow,
		unsigned long numrows, unsigned long bufwidth);

void __cdecl UnVQ_2x3(unsigned char *codebook, unsigned char *pointers,
		unsigned char *buffer, unsigned long blocksperrow,
		unsigned long numrows, unsigned long bufwidth);

void __cdecl UnVQ_4x2(unsigned char *codebook, unsigned char *pointers,
		unsigned char *buffer, unsigned long blocksperrow,
		unsigned long numrows, unsigned long bufwidth);

void __cdecl UnVQ_4x4(unsigned char *codebook, unsigned char *pointers,
		unsigned char *buffer, unsigned long blocksperrow,
		unsigned long numrows, unsigned long bufwidth);

void __cdecl UnVQ_4x2_Woofer(unsigned char *codebook, unsigned char *pointers,
		unsigned char *buffer, unsigned long blocksperrow,
		unsigned long numrows, unsigned long bufwidth);

/* unvqvesa.asm */
void __cdecl UnVQ_4x2_VESA320_32K(unsigned char *codebook,
		unsigned char *pointers, unsigned char *palette,
		unsigned long grains_per_win,unsigned long dummy1,unsigned long dummy2);

#else /* PHARLAP_TNT */

void __cdecl UnVQ_2x2(unsigned char *codebook, unsigned char *pointers,
		FARPTR buffer, unsigned long blocksperrow, unsigned long numrows,
		unsigned long bufwidth);

void __cdecl UnVQ_2x3(unsigned char *codebook, unsigned char *pointers,
		FARPTR buffer, unsigned long blocksperrow, unsigned long numrows,
		unsigned long bufwidth);

void __cdecl UnVQ_4x2(unsigned char *codebook, unsigned char *pointers,
		FARPTR buffer, unsigned long blocksperrow, unsigned long numrows,
		unsigned long bufwidth);

void __cdecl UnVQ_4x4(unsigned char *codebook, unsigned char *pointers,
		FARPTR buffer, unsigned long blocksperrow, unsigned long numrows,
		unsigned long bufwidth);

/* unvqvesa.asm */
void __cdecl UnVQ_4x2_VESA320_32K(unsigned char *codebook,
		unsigned char *pointers, FARPTR palette, unsigned long grains_per_win,
		unsigned long dummy1, unsigned long dummy2);

#endif /* PHARLAP_TNT */

/* unvqxmde.asm */
void __cdecl UnVQ_4x2_Xmode(unsigned char *codebook, unsigned char *pointers,
		unsigned char *buffer, unsigned long blocksperrow,
		unsigned long numrows, unsigned long dummy);

void __cdecl UnVQ_4x2_XmodeCB(unsigned char *cbdummy, unsigned char *pointers,
		unsigned char *buffer, unsigned long blocksperrow,
		unsigned long numrows, unsigned long dummy);

void __cdecl Upload_4x2CB(unsigned char *codebook, unsigned long numentries);
void __cdecl XlatePointers(unsigned char *pointers, unsigned long numpointers);

#ifdef __cplusplus
}
#endif

#endif /* VQAUNVQ_H */
