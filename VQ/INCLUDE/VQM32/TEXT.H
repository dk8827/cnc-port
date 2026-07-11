/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMTEXT_H
#define VQMTEXT_H

/* Prototypes */

#ifdef __cplusplus
extern "C" {
#endif

long cdecl Text_Print(char *string, long x, long y, long fcol, long bcol);
void cdecl Draw_Char(long character, long x, long y);
void cdecl Set_Font_Palette_Range(void *palette, long start, long end);

#ifdef __cplusplus
}
#endif

#endif /* VQMTEXT_H */

