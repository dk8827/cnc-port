/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include <gbuffer.h>
#include <string.h>
#include <buffer.h>
#include	<file.h>

#ifndef PCX_H
#define PCX_H


typedef	struct {
						  char	red ;
						  char	green ;
						  char	blue ;
					} RGB ;

typedef	struct	{
						  char      id ;
						  char	   version ;
						  char	   encoding ;
						  char	   pixelsize ;
						  short 	   x ;
						  short		y ;
						  short     width ;
						  short		height ;
						  short 	   xres ;
						  short		yres ;
						  RGB       ega_palette [ 16 ] ;
						  char	   nothing ;
						  char      color_planes ;
						  short 		byte_per_line ;
						  short 	 	palette_type ;
						  char	   filler [ 58 ] ;
						} PCX_HEADER ;

GraphicBufferClass* Read_PCX_File (char* name, char* palette= NULL,void *buff=NULL, long size=0);
GraphicBufferClass* Read_PCX_File (char* name, BufferClass& Buff,char* palette= NULL) ;
int Write_PCX_File (char* name, GraphicViewPortClass& pic, unsigned char* palette );

#endif
