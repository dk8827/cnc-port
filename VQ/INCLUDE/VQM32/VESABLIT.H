/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMVESABLIT_H
#define VQMVESABLIT_H

#include <vqm32/video.h>

/*---------------------------------------------------------------------------
 * FUNCTION PROTOTYPES
 *-------------------------------------------------------------------------*/

void VESA_Blit_640x480(DisplayInfo *disp,unsigned char *buf,long x1,
		long y1,long width,long height);

#ifdef __cplusplus
extern "C" {
#endif

void cdecl Blit_VESA640x480(DisplayInfo *disp,unsigned char *buf,long x1,
		long y1,long width,long height);

void cdecl Buf_320x200_To_VESA_320x200(unsigned char *buffer, long grain);
void cdecl Buf_320x200_To_VESA_640x400(unsigned char *buffer, long grain);
void cdecl Buf_320x200_To_VESA_32K(unsigned char *buffer,
		unsigned char *palette, long grain);

void cdecl Copy_Row(char *, char *, long);
void cdecl Copy_Word_Row(char *source, char *dest, char *palette,
		long numbytes);

#ifdef __cplusplus
}
#endif

#endif /* VQMVESABLIT_H */

