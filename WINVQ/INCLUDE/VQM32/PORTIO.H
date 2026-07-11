/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMPORTIO_H
#define VQMPORTIO_H

#ifdef __BORLANDC__

#ifdef __cplusplus
extern "C" {
#endif

short __cdecl inp(unsigned short portid);
void __cdecl outp(unsigned short portid, short value);

#ifdef __cplusplus
}
#endif

#endif /* __BORLANDC__ */

#endif /* VQMPORTIO_H */

