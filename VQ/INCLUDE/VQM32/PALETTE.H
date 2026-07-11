/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMPALETTE_H
#define VQMPALETTE_H

/* Prototypes */

#ifdef __cplusplus
extern "C" {
#endif

void cdecl SetPalette(unsigned char *palette,long numbytes,unsigned long slowpal);
void cdecl ReadPalette(void *palette);
void cdecl SetDAC(long color, long red, long green, long blue);
void cdecl TranslatePalette(void *pal24, void *pal15, long numbytes);

#ifdef __cplusplus
}
#endif

void SortPalette(unsigned char *pal, long numcolors);

#endif /* VQMPALETTE_H */

