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

#endif //TILE_H

