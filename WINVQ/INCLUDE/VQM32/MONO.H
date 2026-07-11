/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMMONO_H
#define VQMMONO_H

/* Prototypes */

#ifdef __cplusplus
extern "C" {
#endif

void __cdecl Mono_Enable(void);
void __cdecl Mono_Disable(void);
void __cdecl Mono_Set_Cursor(long x, long y);
void __cdecl Mono_Clear_Screen(void);
void __cdecl Mono_Scroll(long lines);
void __cdecl Mono_Put_Char(long character, long attrib);
void __cdecl Mono_Draw_Rect(long x, long y, long w, long h, long attrib,
		long thick);

void __cdecl Mono_Text_Print(void const *text, long x, long y, long attrib);
void __cdecl Mono_Print(void const *text);
short __cdecl Mono_View_Page(long page);
short __cdecl Mono_X(void);
short __cdecl Mono_Y(void);

#ifdef __cplusplus
}
#endif

#endif /* VQMMONO_H */
