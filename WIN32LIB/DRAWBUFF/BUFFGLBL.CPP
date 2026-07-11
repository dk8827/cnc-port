/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include "gbuffer.h"

/*=========================================================================*/
/* The following PRIVATE functions are in this file:                       */
/*=========================================================================*/


/*= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =*/

/*=========================================================================*/
/* Globals required by GraphicBufferClass for function pointers.  These		*/
/*   pointers will be set to the proper function when set mode is called.	*/
/*=========================================================================*/
BOOL (*GVPC_Blit_to_VVPC_Func)(void *, void *, int, int, int, int, int, int, BOOL);
BOOL (*GVPC_Scale_To_VVPC)(	void *, void *, int, int, int, int, int, int, int, int, BOOL, char *);

#ifdef not_any_more_it_doesnt
/*=========================================================================*/
/* Globals required by VideoBufferClass for function pointers.  These		*/
/*   pointers will be set to the proper function when set mode is called.	*/
/*=========================================================================*/
void (*VVPC_Clear_Func)(void *, unsigned char);
long (*VVPC_To_Buffer_Func)(void *,int x, int y, int w, int h, void *buff, long size);
void (*VVPC_Put_Pixel_Func)(void *,int x, int y, unsigned char color);
int  (*VVPC_Get_Pixel_Func)(void *, int x, int y);
long (*VVPC_Buffer_To_Page)(int x, int y, int w, int h, void *Buffer, void *view);
BOOL (*VVPC_Blit_to_GVPC_Func)(void *, void *, int, int, int, int, int, int, BOOL);
BOOL (*VVPC_Blit_to_VVPC_Func)(void *, void *, int, int, int, int, int, int, BOOL);
BOOL (*VVPC_Scale_To_GVPC)(	void *, void *, int, int, int, int, int, int, int, int, BOOL, char *);
BOOL (*VVPC_Scale_To_VVPC)(	void *, void *, int, int, int, int, int, int, int, int, BOOL, char *);
LONG (*VVPC_Print_Func)(		void *, const char *, int, int, int, int);
void (*VVPC_Draw_Stamp)(void *, void *, int, int, int, void *);
long (*VVPC_Size_Of_Region)(void *, int, int);

#endif	//not_any_more_it_doesnt

/*=========================================================================*/
/* We need to keep a pointer to the logic page hanging around somewhere		*/
/*=========================================================================*/
GraphicViewPortClass	*LogicPage;

BOOL IconCacheAllowed = TRUE;

/*
** Pointer to a function we will call if we detect loss of focus
*/
void (*Gbuffer_Focus_Loss_Function)(void) = NULL;
