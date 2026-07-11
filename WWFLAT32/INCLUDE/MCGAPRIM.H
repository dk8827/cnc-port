/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef MCGAPRIM_H
#define MCGAPRIM_H


#ifndef WWSTD_H
#include "wwstd.h"
#endif

class GraphicViewPortClass;
class GraphicBufferClass;
class VideoBufferClass;
/*=========================================================================*/
/* Define functions which have not under-gone name mangling						*/
/*=========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
	/*======================================================================*/
	/* Externs for all of the common functions between the video buffer		*/
	/*		class and the graphic buffer class.											*/
	/*======================================================================*/
	extern long MCGA_Size_Of_Region(void *thisptr, int w, int h);

	extern void	MCGA_Put_Pixel(void * thisptr, int x, int y, unsigned char color);
	extern int	MCGA_Get_Pixel(void * thisptr, int x, int y);
	extern void	MCGA_Clear(void *thisptr, unsigned char color);
	extern long	MCGA_To_Buffer(void *thisptr, int x, int y, int w, int h, void *buff, long size);
	extern long MCGA_Buffer_To_Page(int x, int y, int w, int h, void *Buffer, void *view);
	extern BOOL	Linear_Blit_To_Linear(	void *thisptr, void * dest, int x_pixel, int y_pixel, int dx_pixel, 
													int dy_pixel, int pixel_width, int pixel_height, BOOL trans);
	extern BOOL Linear_Scale_To_Linear(	void *, void *, int, int, int, int, int, int, int, int, BOOL, char *);

	extern void	Vesa_Put_Pixel(void * thisptr, int x, int y, unsigned char color);
	extern int	Vesa_Get_Pixel(void * thisptr, int x, int y);
	extern void	Vesa_Clear(void *thisptr, unsigned char color);
	extern long	Vesa_To_Buffer(void *thisptr, int x, int y, int w, int h, void *buff, long size);
	extern long Vesa_Buffer_To_Page(int x, int y, int w, int h, void *Buffer, void *view);

	extern BOOL	Linear_Blit_To_Vesa(		void *thisptr, void * dest, int x_pixel, int y_pixel, int dx_pixel, 
													int dy_pixel, int pixel_width, int pixel_height, BOOL trans);
	extern BOOL	Vesa_Blit_To_Linear(		void *thisptr, void * dest, int x_pixel, int y_pixel, int dx_pixel, 
													int dy_pixel, int pixel_width, int pixel_height, BOOL trans);
	extern BOOL	Vesa_Blit_To_Vesa(		void *thisptr, void * dest, int x_pixel, int y_pixel, int dx_pixel, 
													int dy_pixel, int pixel_width, int pixel_height, BOOL trans);
	extern BOOL Linear_Scale_To_Vesa(	void *, void *, int, int, int, int, int, int, int, int, BOOL, char *);
	extern BOOL Vesa_Scale_To_Linear(	void *, void *, int, int, int, int, int, int, int, int, BOOL, char *);
	extern BOOL Vesa_Scale_To_Vesa(		void *, void *, int, int, int, int, int, int, int, int, BOOL, char *);
	extern LONG MCGA_Print(					void *thisptr, const char *str, int x, int y, int fcolor, int bcolor);
	extern LONG Vesa_Print(					void *thisptr, const char *str, int x, int y, int fcolor, int bcolor);

	/*======================================================================*/
	/* Externs for all of the graphic buffer class only functions				*/
	/*======================================================================*/
	extern VOID MCGA_Draw_Line(void *thisptr, int sx, int sy, int dx, int dy, unsigned char color);
	extern VOID MCGA_Fill_Rect(void *thisptr, int sx, int sy, int dx, int dy, unsigned char color);
	extern VOID MCGA_Remap(void * thisptr, int sx, int sy, int width, int height, void *remap);	
	extern VOID MCGA_Fill_Quad(void * thisptr, VOID *span_buff, int x0, int y0, int x1, int y1,
							int x2, int y2, int x3, int y3, int color);
	extern void MCGA_Draw_Stamp(void const *thisptr, void const *icondata, int icon, int x_pixel, int y_pixel, void const *remap);
	extern void MCGA_Draw_Stamp_Clip(void const *thisptr, void const *icondata, int icon, int x_pixel, int y_pixel, void const *remap, int min_x, int min_y, int max_x, int max_y);

	extern void Shadow_Blit(long int xpix, long int ypix, long int width, long int height, GraphicViewPortClass &src, VideoBufferClass &dst, void *shadowbuff);

	extern void *Get_Font_Palette_Ptr(void);
//	extern int Get_Standard_Selector(VOID);
//	extern VOID Set_Selector(UWORD sel);
#ifdef __cplusplus
}
#endif

extern BOOL (*VVPC_Blit_to_GVPC_Func)(void *, void *, int, int, int, int, int, int, BOOL);
extern BOOL (*VVPC_Blit_to_VVPC_Func)(void *, void *, int, int, int, int, int, int, BOOL);
extern void (*VVPC_Clear_Func)(void *, unsigned char);
extern long (*VVPC_To_Buffer_Func)(void *,int x, int y, int w, int h, void *buff, long size);
extern void (*VVPC_Put_Pixel_Func)(void *,int x, int y, unsigned char color);
extern int  (*VVPC_Get_Pixel_Func)(void *, int x, int y);
extern long (*VVPC_Buffer_To_Page)(int x, int y, int w, int h, void *buffer, void *view);
extern BOOL (*GVPC_Blit_to_VVPC_Func)(void *, void *, int, int, int, int, int, int, BOOL);
extern BOOL (*VVPC_Blit_to_GVPC_Func)(void *, void *, int, int, int, int, int, int, BOOL);
extern BOOL (*VVPC_Blit_to_VVPC_Func)(void *, void *, int, int, int, int, int, int, BOOL);
extern BOOL (*VVPC_Scale_To_GVPC)(	void *, void *, int, int, int, int, int, int, int, int, BOOL, char *);
extern BOOL (*VVPC_Scale_To_VVPC)(	void *, void *, int, int, int, int, int, int, int, int, BOOL, char *);
extern BOOL (*GVPC_Scale_To_VVPC)(	void *, void *, int, int, int, int, int, int, int, int, BOOL, char *);
extern LONG (*VVPC_Print_Func)(void *, const char *, int, int, int, int);
extern GraphicBufferClass *LogicPage;
#endif
