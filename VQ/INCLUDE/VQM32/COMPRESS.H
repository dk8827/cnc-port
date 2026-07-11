/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMCOMP_H
#define VQMCOMP_H

/* Prototypes */

#ifdef __cplusplus
extern "C" {
#endif

unsigned long cdecl LCW_Compress(char const *source, char *dest,
		unsigned long length);
unsigned long cdecl LCW_Uncompress(char const *source, char *dest,
		unsigned long length);
long AudioZap(void *source, void *dest, long size);
long cdecl AudioUnzap(void *source, void *dest, long);

#ifdef __cplusplus
}
#endif

#endif /* VQMCOMP_H */

