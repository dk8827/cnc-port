/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef SHAPE_H
#define SHAPE_H

#ifndef GBUFFER_H
#include "gbuffer.h"
#endif
/*
*********************************** Types ***********************************
*/
/*
--------------------------- Shape creation flags ----------------------------
*/
typedef enum {
	MAKESHAPE_NORMAL	 = 0x0000,	// 256-color compressed shape
	MAKESHAPE_COMPACT  = 0x0001,	// 16-color shape (with built-in color table)
	MAKESHAPE_NOCOMP	 = 0x0002,	// Uncompressed shape
	MAKESHAPE_VARIABLE =	0x0004	// <16-color shape
} MakeShapeFlags_Type;

/*---------------------------------------------------------------------------
Shape drawing flags:
- The low byte is for coordinate transformations.
- The high byte is for drawing effects.
---------------------------------------------------------------------------*/
typedef enum {
	SHAPE_NORMAL 			= 0x0000,		// Standard shape
	SHAPE_HORZ_REV 		= 0x0001,		// Flipped horizontally
	SHAPE_VERT_REV 		= 0x0002,		// Flipped vertically
	SHAPE_SCALING 			= 0x0004,		// Scaled (WORD scale_x, WORD scale_y)
	SHAPE_VIEWPORT_REL 	= 0x0010,		// Coords are window-relative 
	SHAPE_WIN_REL 			= 0x0010,		// Coordinates are window relative instead of absolute.
	SHAPE_CENTER 			= 0x0020,		// Coords are based on shape's center pt
	SHAPE_FADING 			= 0x0100,		// Fading effect (VOID * fading_table, 
													//  WORD fading_num)
	SHAPE_PREDATOR 		= 0x0200,		// Transparent warping effect
	SHAPE_COMPACT 			= 0x0400,		// Never use this bit 
	SHAPE_PRIORITY 		= 0x0800,		// Use priority system when drawing
	SHAPE_GHOST				= 0x1000,		// Shape is drawn ghosted
	SHAPE_SHADOW			= 0x2000,
	SHAPE_PARTIAL  		= 0x4000,
	SHAPE_COLOR 			= 0x8000			// Remap the shape's colors 
													//  (VOID * color_table)
} ShapeFlags_Type;

/*
------------------------------- Shape header --------------------------------
*/
typedef struct {
	UWORD		ShapeType;			// 0 = normal, 1 = 16 colors, 
										//  2 = uncompressed, 4 = 	<16 colors
	UBYTE		Height;				// Height of the shape in scan lines
	UWORD		Width;				// Width of the shape in bytes
	UBYTE		OriginalHeight;	// Original height of shape in scan lines
	UWORD		ShapeSize;			// Size of the shape, including header
	UWORD		DataLength;			// Size of the uncompressed shape (just data)
	UBYTE		Colortable[16];	// Optional color table for compact shape
} Shape_Type;

/*
------------------------------- Shape block ---------------------------------
*/
typedef struct {
	UWORD		NumShapes;			// number of shapes in the block
	LONG		Offsets[];			// array of offsets to shape data
										//  (offsets within the shape block, with
										//  0 being the first offset value, not the
										//  start of the shape block)
} ShapeBlock_Type;


/*
******************************** Prototypes *********************************
*/

/*
-------------------------------- prioinit.c ---------------------------------
*/

extern "C" {
extern VOID  *MaskPage;
extern VOID  *BackGroundPage;
extern LONG  _ShapeBufferSize;
extern BYTE  *_ShapeBuffer;
}


VOID cdecl Init_Priority_System (GraphicBufferClass *mask,
											GraphicBufferClass *back);


/*
-------------------------------- drawshp.asm --------------------------------
*/

extern "C" {
WORD Draw_Shape(GraphicViewPortClass *gvp, VOID const *shape, LONG x, LONG y, LONG flags, ...);
}

/*
---------------------------------- shape.c ----------------------------------
*/
short cdecl Get_Shape_Data(VOID const *shape, WORD data);
int cdecl Extract_Shape_Count(VOID const *buffer);
void * cdecl Extract_Shape(VOID const *buffer, int shape);
int cdecl Restore_Shape_Height(VOID *shape);
int cdecl Set_Shape_Height(VOID const *shape, WORD newheight);

extern "C" {
int Get_Shape_Width(VOID const *shape);
int Get_Shape_Height(VOID const *shape);
int Get_Shape_Original_Height(VOID const *shape);
int Get_Shape_Uncomp_Size(VOID const *shape);
}


/*
------------------------------- setshape.asm --------------------------------
*/
extern "C" {
VOID Set_Shape_Buffer(void const *buffer, int size);
}
/*
------------------------------- shapeinf.asm --------------------------------
*/
WORD cdecl Get_Shape_Flags(VOID const *shape);
int  cdecl Get_Shape_Size(VOID const *shape);
int  cdecl Get_Shape_Scaled_Width(VOID const *shape, WORD scale);
int  cdecl Get_Shape_Scaled_Height(VOID const *shape, WORD scale);

#endif // SHAPE_H

/****************************** End of shape.h *****************************/


