/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef FONT_H
#define FONT_H

#ifndef GBUFFER_H
#include <gbuffer.h>
#endif


//////////////////////////////////////// Defines //////////////////////////////////////////

// defines for font header, offsets to block offsets

#define FONTINFOBLOCK			4
#define FONTOFFSETBLOCK			6
#define FONTWIDTHBLOCK			8
#define FONTDATABLOCK			10
#define FONTHEIGHTBLOCK			12

// defines for font info block

#define FONTINFOMAXHEIGHT		4
#define FONTINFOMAXWIDTH		5

//////////////////////////////////////// Prototypes //////////////////////////////////////////

/*=========================================================================*/
/* The following prototypes are for the file: SET_FONT.CPP						*/
/*=========================================================================*/

void  * __cdecl Set_Font(void const *fontptr);

/*=========================================================================*/
/* The following prototypes are for the file: FONT.CPP							*/
/*=========================================================================*/

int __cdecl Char_Pixel_Width(char chr);
unsigned int __cdecl String_Pixel_Width(char const *string);
void __cdecl Get_Next_Text_Print_XY(GraphicViewPortClass& vp, unsigned long offset, INT *x, INT *y);

/*=========================================================================*/
/* The following prototypes are for the file: LOADFONT.CPP	  					*/
/*=========================================================================*/

void * __cdecl Load_Font(char  const *name);

/*=========================================================================*/
/* The following prototypes are for the file: TEXTPRNT.ASM	  					*/
/*=========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif


void __cdecl Set_Font_Palette_Range(void const *palette, INT start_idx, INT end_idx);


#ifdef __cplusplus
}
#endif

/*=========================================================================*/





//////////////////////////////////////// External varables ///////////////////////////////////////
extern "C" int FontXSpacing;
extern "C" int FontYSpacing;
extern char FontWidth ;
extern char FontHeight;
extern char *FontWidthBlockPtr;


extern "C" void const *FontPtr;




#endif // FONT_H
