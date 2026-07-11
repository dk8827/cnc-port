/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef LCW_H
#define LCW_H


int LCW_Uncomp(void const * source, void * dest, unsigned long length=0);

extern "C" {
int __cdecl LCW_Comp(void const * source, void * dest, int length);
}

#endif
