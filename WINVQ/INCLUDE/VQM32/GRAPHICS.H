/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMGRAPHICS_H
#define VQMGRAPHICS_H

/* Prototypes */

#ifdef __cplusplus
extern "C" {
#endif

void __cdecl Eor_Region(long sx, long sy, long dx, long dy, long color);
void __cdecl Fill_Rect(long x1, long y1, long x2, long y2, long color);

#ifdef __cplusplus
}
#endif

#endif /* VQMGRAPHICS_H */

