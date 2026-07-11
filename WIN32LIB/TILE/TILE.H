/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef TILE_H
#define TILE_H

#include <stdint.h>

/*=========================================================================*/
/* The following prototypes are for the file: ICONSET.CPP						*/
/*=========================================================================*/
void * Load_Icon_Set(char const *filename, void *iconsetptr, long buffsize);
void Free_Icon_Set(void const *iconset);
long Get_Icon_Set_Size(void const *iconset);
int Get_Icon_Set_Width(void const *iconset);
int Get_Icon_Set_Height(void const *iconset);
void * Get_Icon_Set_Icondata(void const *iconset);
void * Get_Icon_Set_Trans(void const *iconset);
void * Get_Icon_Set_Remapdata(void const *iconset);
void * Get_Icon_Set_Palettedata(void const *iconset);
int Get_Icon_Set_Count(void const *iconset);
void * Get_Icon_Set_Map(void const *iconset);
#if (0)
/*
** This is the control structure at the start of a loaded icon set.  It must match
** the structure in WWLIB.I!  This structure MUST be a multiple of 16 bytes long.
*/
typedef struct {
	short	Width;			// Width of icons (pixels).
	short	Height;			// Height of icons (pixels).
	short	Count;			// Number of (logical) icons in this set.
//	BOOL	Allocated;		// Was this iconset allocated?
	short	Allocated;		// Was this iconset allocated?
	int32_t	Size;				// Size of entire iconset memory block.
	unsigned char *Icons;			// Offset from buffer start to icon data.
	int32_t	Palettes;		// Offset from buffer start to palette data.
	int32_t	Remaps;			// Offset from buffer start to remap index data.
	int32_t	TransFlag;		// Offset for transparency flag table.
	unsigned char *Map;				// Icon map offset (if present).
} IControl_Type;
#endif	//(0)

typedef struct {
	short	Width;			// Width of icons (pixels).
	short	Height;			// Height of icons (pixels).
	short	Count;			// Number of (logical) icons in this set.
	short	Allocated;		// Was this iconset allocated?
	int32_t	Size;				// Size of entire iconset memory block.
	int32_t	Icons;			// Offset from buffer start to icon data.
	int32_t	Palettes;		// Offset from buffer start to palette data.
	int32_t	Remaps;			// Offset from buffer start to remap index data.
	int32_t	TransFlag;		// Offset for transparency flag table.
	int32_t	Map;				// Icon map offset (if present).
} IControl_Type;

static_assert(sizeof(IControl_Type) == 32, "Tiberian Dawn icon-set header must remain 32 bytes");


#endif //TILE_H
