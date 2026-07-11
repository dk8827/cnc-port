/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMCRC_H
#define VQMCRC_H

#ifdef __cplusplus
extern "C" {
#endif

long cdecl Calculate_CRC(void const *buffer, long length);

#ifdef __cplusplus
}
#endif

#endif /* VQMCRC_H */
