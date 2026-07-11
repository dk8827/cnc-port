/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQAMEM_H
#define VQAMEM_H

/* Definitions */
#define DPMI_INT    0x0031
#define DPMI_LOCK   0x0600
#define DPMI_UNLOCK 0x0601

/* Prototypes */
#ifdef __WATCOMC__
void DPMI_Lock(void const *ptr, long const size);
void DPMI_Unlock(void const *ptr, long const size);
#else
#define DPMI_Lock(a,b)
#define DPMI_Unlock(a,b)
#endif

#endif /* VQAMEM_H */
