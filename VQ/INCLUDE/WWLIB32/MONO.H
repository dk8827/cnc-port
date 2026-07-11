/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef MONO_H
#define MONO_H

// C++ Routines
//==================================================================

// Mono Screen routines
//==================================================================
int	Initialize_Mono_Screen ( void );
							   

// C Routines
//==================================================================
#ifdef __cplusplus
extern "C" {
#endif

// Mono Screen routines
//===================================================================
	extern	unsigned	MonoScreen;
	extern	unsigned	MonoEnabled;
			
	extern	void Mono_Set_Cursor(int x, int y);
	extern 	void Mono_Clear_Screen(void); 
	extern 	void Mono_Scroll(int lines);
	extern 	void Mono_Put_Char(char character, int attrib=2);
	extern 	void Mono_Draw_Rect(int x, int y, int w, int h, int attrib=2, int thick=0);
	extern	void Mono_Text_Print(void const *text, int x, int y, int attrib=2);
	extern	void Mono_Print(void const *text);
	extern 	void Mono_View_Page(int page);
	extern	int Mono_Printf(char const *string, ...);
								
#ifdef __cplusplus
}
#endif


#endif

