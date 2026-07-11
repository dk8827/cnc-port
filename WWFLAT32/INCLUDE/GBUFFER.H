/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include "window.h"

#ifndef GBUFFER_H
#define GBUFFER_H

/*=========================================================================*/
/* If we have not already loaded the standard library header, than we can	*/
/*		load it.																					*/
/*=========================================================================*/

#ifndef WWSTD_H
#include "wwstd.h"
#endif

#ifndef MCGAPRIM_H
#include "mcgaprim.h"
#endif

#ifndef BUFFER_H
#include "buffer.h"
#endif

#include <stdlib.h>


/*=========================================================================*/
/* Define the screen width and height to make portability to other modules	*/
/*		easier.																					*/
/*=========================================================================*/
#define	DEFAULT_SCREEN_WIDTH		320
#define	DEFAULT_SCREEN_HEIGHT	200

/*=========================================================================*/
/* Let the compiler know that a GraphicBufferClass exists so that it can	*/
/*		keep a pointer to it in a VideoViewPortClass.								*/
/*=========================================================================*/
class GraphicViewPortClass;
class GraphicBufferClass;
class VideoViewPortClass;
class VideoBufferClass;

GraphicBufferClass *Set_Logic_Page(GraphicBufferClass *ptr);
GraphicBufferClass *Set_Logic_Page(GraphicBufferClass &ptr);

/*=========================================================================*/
/* GraphicViewPortClass - Holds viewport information on a viewport which	*/
/*		has been attached to a GraphicBuffer.  A viewport is effectively a	*/
/*		rectangular subset of the full buffer which is used for clipping and	*/
/*		the like.																				*/
/*																									*/
/*			char	  	*Buffer	-		is the offset to view port buffer			*/
/*			int	  	Width		-		is the width of view port						*/
/*			int	  	Height	-		is the height of view port						*/
/*			int	  	XAdd		-		is add value to go from the end of a line	*/
/*											to the beginning of the next line			*/
/*			int		XPos;		- 		x offset into its associated VideoBuffer	*/
/*			int		YPos;		-		y offset into its associated VideoBuffer	*/
/*=========================================================================*/
class GraphicViewPortClass {
	public:
		/*===================================================================*/
		/* Define the base constructor and destructors for the class			*/
		/*===================================================================*/
		GraphicViewPortClass(GraphicBufferClass* graphic_buff, int x, int y, int w, int h);
		GraphicViewPortClass();
		~GraphicViewPortClass();

		/*===================================================================*/
		/* define functions to get at the private data members					*/
		/*===================================================================*/
		long	Get_Offset(void);
		int	Get_Height(void);
		int	Get_Width(void);
		int	Get_XAdd(void);
		int	Get_XPos(void);
		int	Get_YPos(void);
		GraphicBufferClass	*Get_Graphic_Buffer(void);

		int Lock(void) const {return(TRUE);}
		void Unlock(void) const {}

		/*===================================================================*/
		/* Define a function which allows us to change a video viewport on	*/
		/*		the fly.																			*/
		/*===================================================================*/
		BOOL Change(int x, int y, int w, int h);

		/*===================================================================*/
		/* Define the set of common graphic functions that are supported by	*/
		/*		both Graphic ViewPorts and VideoViewPorts.							*/
		/*===================================================================*/
		long	Size_Of_Region(int w, int h);
		void	Put_Pixel(int x, int y, unsigned char color);
		int	Get_Pixel(int x, int y);
		void	Clear(unsigned char color = 0);
		long	To_Buffer(int x, int y, int w, int h, void *buff, long size);
		long	To_Buffer(int x, int y, int w, int h, BufferClass *buff);
		long	To_Buffer(BufferClass *buff);
		BOOL	Blit(	GraphicViewPortClass& dest, int x_pixel, int y_pixel, int dx_pixel,
						int dy_pixel, int pixel_width, int pixel_height, BOOL trans = FALSE);
		BOOL	Blit(	GraphicViewPortClass& dest, int dx, int dy, BOOL trans = FALSE);
		BOOL	Blit(	GraphicViewPortClass& dest, BOOL trans = FALSE);
		BOOL	Blit(	VideoViewPortClass& dest, int x_pixel, int y_pixel, int dx_pixel,
						int dy_pixel, int pixel_width, int pixel_height, BOOL trans = FALSE);
		BOOL	Blit(	VideoViewPortClass& dest, int dx, int dy, BOOL trans = FALSE);
		BOOL	Blit(	VideoViewPortClass& dest, BOOL trans = FALSE);
		BOOL	Scale(	GraphicViewPortClass &dest, int src_x, int src_y, int dst_x,
							int dst_y, int src_w, int src_h, int dst_w, int dst_h, BOOL trans = FALSE, char *remap = NULL);
		BOOL	Scale(	GraphicViewPortClass &dest, int src_x, int src_y, int dst_x,
							int dst_y, int src_w, int src_h, int dst_w, int dst_h, char *remap);
		BOOL	Scale(	GraphicViewPortClass &dest, BOOL trans = FALSE, char *remap = NULL);
		BOOL	Scale(	GraphicViewPortClass &dest, char *remap);
		BOOL	Scale(	VideoViewPortClass &dest, int src_x, int src_y, int dst_x,
							int dst_y, int src_w, int src_h, int dst_w, int dst_h, BOOL trans = FALSE, char *remap = NULL);
		BOOL	Scale(	VideoViewPortClass &dest, int src_x, int src_y, int dst_x,
							int dst_y, int src_w, int src_h, int dst_w, int dst_h, char *remap);
		BOOL	Scale(	VideoViewPortClass &dest, BOOL trans = FALSE, char *remap = NULL);
		BOOL	Scale(	VideoViewPortClass &dest, char *remap);
		unsigned long	Print(char const *string, int x_pixel, int y_pixel, int fcolor, int bcolor);
		unsigned long	Print(short num, int x_pixel, int y_pixel, int fcol, int bcol);
		unsigned long	Print(int num, int x_pixel, int y_pixel, int fcol, int bcol);
		unsigned long	Print(long num, int x_pixel, int y_pixel, int fcol, int bcol);

		/*===================================================================*/
		/* Define the list of graphic functions which work only with a 		*/
		/*		graphic buffer.																*/
		/*===================================================================*/
		VOID Draw_Line(int sx, int sy, int dx, int dy, unsigned char color);
		VOID Draw_Rect(int sx, int sy, int dx, int dy, unsigned char color);
		VOID Fill_Rect(int sx, int sy, int dx, int dy, unsigned char color);
		VOID Fill_Quad(VOID *span_buff, int x0, int y0, int x1, int y1,
							int x2, int y2, int x3, int y3, int color);
		VOID Remap(int sx, int sy, int width, int height, VOID *remap);
		VOID Remap(VOID *remap);
		void Draw_Stamp(void const *icondata, int icon, int x_pixel, int y_pixel, void const *remap);
		void Draw_Stamp(void const *icondata, int icon, int x_pixel, int y_pixel, void const *remap, int clip_window);
		VOID Grey_Out_Region(int x, int y, int width, int height, int color);
	protected:
		/*===================================================================*/
		/* Define functions to attach the viewport to a graphicbuffer			*/
		/*===================================================================*/
		VOID Attach(GraphicBufferClass *graphic_buff, int x, int y, int w, int h);
		void Attach(GraphicBufferClass *video_buff, int w, int h);

		/*===================================================================*/
		/* Define the data used by a GraphicViewPortClass							*/
		/*===================================================================*/
		long						Offset;					// offset to graphic page
		int						Width;					// width of graphic page
		int						Height;					// height of graphic page
		int						XAdd;						// xadd for graphic page (0)
		int						XPos;						// x offset in relation to graphicbuff
		int						YPos;						// y offset in relation to graphicbuff
		GraphicBufferClass	*GraphicBuff;			// related graphic buff
};

/*=========================================================================*/
/* GraphicBufferClass - A GraphicBuffer refers to an actual instance of an	*/
/*		allocated buffer.  The GraphicBuffer may be drawn to directly 			*/
/*		becuase it inherits a ViewPort which represents its physcial size.	*/
/*																									*/
/*			BYTE	  	*Buffer	-		is the offset to graphic buffer				*/
/*			int	  	Width		-		is the width of graphic buffer				*/
/*			int	  	Height	-		is the height of graphic buffer				*/
/*			int	  	XAdd		-		is the xadd of graphic buffer					*/
/*			int		XPos;		- 		will be 0 because it is graphicbuff			*/
/*			int		YPos;		-		will be 0 because it is graphicbuff			*/
/*=========================================================================*/
class GraphicBufferClass : public GraphicViewPortClass, public BufferClass {
	public:
		GraphicBufferClass(	long size = 64500, int w = DEFAULT_SCREEN_WIDTH, int h = DEFAULT_SCREEN_HEIGHT,
									VOID *buffer = 0);
		GraphicBufferClass(int w, int h, void *buffer = 0);
		~GraphicBufferClass();

		void Scale_Rotate(BitmapClass &bmp,const TPoint2D &pt,long scale=0x0100,unsigned char angle=0);
};

/***************************************************************************
 * GVPC::GET_OFFSET -- Get offset for virtual view port class instance     *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     long the offset for the virtual viewport instance           *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/07/1994 PWG : Created.                                             *
 *=========================================================================*/
inline long GraphicViewPortClass::Get_Offset(void)
{
	return(Offset);
}

/***************************************************************************
 * GVPC::GET_HEIGHT -- Gets the height of a virtual viewport instance      *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     WORD the height of the virtual viewport instance            *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/07/1994 PWG : Created.                                             *
 *=========================================================================*/
inline int GraphicViewPortClass::Get_Height(void)
{
	return(Height);
}

/***************************************************************************
 * GVPC::GET_WIDTH -- Get the width of a virtual viewport instance			*
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     WORD the width of the virtual viewport instance             *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/07/1994 PWG : Created.                                             *
 *=========================================================================*/
inline int GraphicViewPortClass::Get_Width(void)
{
	return(Width);
}


/***************************************************************************
 * GVPC::GET_XADD -- Get the X add offset for virtual viewport instance    *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     WORD the xadd for a virtual viewport instance               *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/07/1994 PWG : Created.                                             *
 *=========================================================================*/
inline int GraphicViewPortClass::Get_XAdd(void)
{
	return(XAdd);
}
/***************************************************************************
 * GVPC::GET_XPOS -- Get the x pos of the VP on the Video                  *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     WORD the x offset to VideoBufferClass								*
 *                                                                         *
 * HISTORY:                                                                *
;*   08/22/1994 SKB : Created.                                             *
 *=========================================================================*/
inline int GraphicViewPortClass::Get_XPos(void)
{
	return(XPos);
}


/***************************************************************************
 * GVPC::GET_YPOS -- Get the y pos of the VP on the video                  *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     WORD the x offset to VideoBufferClass								*
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
;*   08/22/1994 SKB : Created.                                             *
 *=========================================================================*/
inline int GraphicViewPortClass::Get_YPos(void)
{
	return(YPos);
}

/***************************************************************************
 * GVPC::GET_GRAPHIC_BUFFER -- Get the graphic buffer of the VP.            *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * HISTORY:                                                                *
 *   08/22/1994 SKB : Created.                                             *
 *=========================================================================*/
inline GraphicBufferClass *GraphicViewPortClass::Get_Graphic_Buffer(void)
{
 	return (GraphicBuff);
}

/***************************************************************************
 * GVPC::SIZE_OF_REGION -- stub to call curr graphic mode Size_Of_Region	*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   03/01/1995 BWG : Created.                                             *
 *=========================================================================*/
inline long	GraphicViewPortClass::Size_Of_Region(int w, int h)
{
	return MCGA_Size_Of_Region(this, w, h);
}

/***************************************************************************
 * GVPC::PUT_PIXEL -- stub to call curr graphic mode Put_Pixel					*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline void	GraphicViewPortClass::Put_Pixel(int x, int y, unsigned char color)
{
	MCGA_Put_Pixel(this, x, y, color);
}

/***************************************************************************
 * GVPC::GET_PIXEL -- stub to call curr graphic mode Get_Pixel          	*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline int	GraphicViewPortClass::Get_Pixel(int x, int y)
{
	return(MCGA_Get_Pixel(this, x, y));
}

/***************************************************************************
 * GVPC::CLEAR -- stub to call curr graphic mode Clear	                  *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline void	GraphicViewPortClass::Clear(unsigned char color)
{
	MCGA_Clear(this, color);
}

/***************************************************************************
 * GVPC::TO_BUFFER -- stub 1 to call curr graphic mode To_Buffer				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline long	GraphicViewPortClass::To_Buffer(int x, int y, int w, int h, void *buff, long size)
{
	return(MCGA_To_Buffer(this, x, y, w, h, buff, size));
}

/***************************************************************************
 * GVPC::TO_BUFFER -- stub 2 to call curr graphic mode To_Buffer 				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline long	GraphicViewPortClass::To_Buffer(int x, int y, int w, int h, BufferClass *buff)
{
	return(MCGA_To_Buffer(this, x, y, w, h, buff->Get_Buffer(), buff->Get_Size()));
}

/***************************************************************************
 * GVPC::TO_BUFFER -- stub 3 to call curr graphic mode To_Buffer 				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline long	GraphicViewPortClass::To_Buffer(BufferClass *buff)
{
	return(MCGA_To_Buffer(this, 0, 0, Width, Height, buff->Get_Buffer(), buff->Get_Size()));
}

/***************************************************************************
 * GVPC::BLIT -- stub 1 to call curr graphic mode Blit to GVPC					*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline BOOL	GraphicViewPortClass::Blit(	GraphicViewPortClass& dest, int x_pixel, int y_pixel, int dx_pixel,
				int dy_pixel, int pixel_width, int pixel_height, BOOL trans)
{
	return(Linear_Blit_To_Linear(this, &dest, x_pixel, y_pixel, dx_pixel, dy_pixel, pixel_width, pixel_height, trans));
}

/***************************************************************************
 * GVPC::BLIT -- Stub 2 to call curr graphic mode Blit to GVPC					*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline BOOL	GraphicViewPortClass::Blit(	GraphicViewPortClass& dest, int dx, int dy, BOOL trans)
{
	return(Linear_Blit_To_Linear(this, &dest, 0, 0, dx, dy, Width, Height, trans));
}

/***************************************************************************
 * GVPC::BLIT -- stub 3 to call curr graphic mode Blit to GVPC					*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline BOOL	GraphicViewPortClass::Blit(	GraphicViewPortClass& dest, BOOL trans)
{
	return(Linear_Blit_To_Linear(this, &dest, 0, 0, 0, 0, Width, Height, trans));
}


/***************************************************************************
 * GVPC::SCALE -- stub 1 to call curr graphic mode Scale to GVPC				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline BOOL	GraphicViewPortClass::Scale(	GraphicViewPortClass &dest, int src_x, int src_y, int dst_x,
					int dst_y, int src_w, int src_h, int dst_w, int dst_h, BOOL trans, char *remap)
{
	return(Linear_Scale_To_Linear(this, &dest, src_x, src_y, dst_x, dst_y, src_w, src_h, dst_w, dst_h, trans, remap));
}

/***************************************************************************
 * GVPC::SCALE -- stub 2 to call curr graphic mode Scale to GVPC				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline BOOL	GraphicViewPortClass::Scale(	GraphicViewPortClass &dest, int src_x, int src_y, int dst_x,
					int dst_y, int src_w, int src_h, int dst_w, int dst_h, char *remap)
{
	return(Linear_Scale_To_Linear(this, &dest, src_x, src_y, dst_x, dst_y, src_w, src_h, dst_w, dst_h, FALSE, remap));
}

/***************************************************************************
 * GVPC::SCALE -- stub 3 to call curr graphic mode Scale to GVPC				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline BOOL	GraphicViewPortClass::Scale(	GraphicViewPortClass &dest, BOOL trans, char *remap)
{
	return(Linear_Scale_To_Linear(this,	&dest, 0, 0, 0, 0, Width, Height, dest.Get_Width(), dest.Get_Height(), trans, remap));
}

/***************************************************************************
 * GVPC::SCALE -- stub 4 to call curr graphic mode Scale to GVPC				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline BOOL	GraphicViewPortClass::Scale(	GraphicViewPortClass &dest, char *remap)
{
	return(Linear_Scale_To_Linear(this, &dest, 0, 0, 0, 0, Width, Height, dest.Get_Width(), dest.Get_Height(), FALSE, remap));
}
/***************************************************************************
 * GVPC::PRINT -- stub func to print a text string                         *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/17/1995 PWG : Created.                                             *
 *=========================================================================*/
inline unsigned long	GraphicViewPortClass::Print(char const *str, int x, int y, int fcol, int bcol)
{
	return(MCGA_Print(this, str, x, y, fcol, bcol));
}

/***************************************************************************
 * GVPC::PRINT -- Stub function to print an integer                        *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *=========================================================================*/
inline unsigned long	GraphicViewPortClass::Print(int num, int x, int y, int fcol, int bcol)
{
	char str[17];


	return(MCGA_Print(this, itoa(num, str, 10), x, y, fcol, bcol));
}

/***************************************************************************
 * GVPC::PRINT -- Stub function to print a short to a graphic viewport     *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *=========================================================================*/
inline unsigned long	GraphicViewPortClass::Print(short num, int x, int y, int fcol, int bcol)
{
	char str[17];

	return(MCGA_Print(this, itoa(num, str, 10), x, y, fcol, bcol));
}

/***************************************************************************
 * GVPC::PRINT -- stub function to print a long on a graphic view port     *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *=========================================================================*/
inline unsigned long	GraphicViewPortClass::Print(long num, int x, int y, int fcol, int bcol)
{
	char str[33];

	return(MCGA_Print(this, ltoa(num, str,10), x, y, fcol, bcol));
}

/***************************************************************************
 * GVPC::DRAW_STAMP -- stub function to draw a tile on a graphic view port *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *=========================================================================*/
inline void GraphicViewPortClass::Draw_Stamp(void const *icondata, int icon, int x_pixel, int y_pixel, void const *remap)
{
	MCGA_Draw_Stamp(this, icondata, icon, x_pixel, y_pixel, remap);
}

/***************************************************************************
 * GVPC::DRAW_STAMP -- stub function to draw a tile on a graphic view port *
 *                     This version clips the tile to a window             *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *    07/31/1995 BWG : Created.                                            *
 *=========================================================================*/
inline void GraphicViewPortClass::Draw_Stamp(void const *icondata, int icon, int x_pixel, int y_pixel, void const *remap, int clip_window)
{
	MCGA_Draw_Stamp_Clip(this, icondata, icon, x_pixel, y_pixel, remap, WindowList[clip_window][WINDOWX], WindowList[clip_window][WINDOWY], WindowList[clip_window][WINDOWWIDTH], WindowList[clip_window][WINDOWHEIGHT]);
}

/***************************************************************************
 * GVPC::DRAW_LINE -- Stub function to draw line in Graphic Viewport Class *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/16/1995 PWG : Created.                                             *
 *=========================================================================*/
inline VOID GraphicViewPortClass::Draw_Line(int sx, int sy, int dx, int dy, unsigned char color)
{
	MCGA_Draw_Line(this, sx, sy, dx, dy, color);
}

/***************************************************************************
 * GVPC::FILL_RECT -- Stub function to fill rectangle in a GVPC            *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/16/1995 PWG : Created.                                             *
 *=========================================================================*/
inline VOID GraphicViewPortClass::Fill_Rect(int sx, int sy, int dx, int dy, unsigned char color)
{
	MCGA_Fill_Rect(this, sx, sy, dx, dy, color);
}


/***************************************************************************
 * GVPC::REMAP -- Stub function to remap a GVPC                            *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/16/1995 PWG : Created.                                             *
 *=========================================================================*/
inline VOID GraphicViewPortClass::Remap(int sx, int sy, int width, int height, VOID *remap)
{
	MCGA_Remap(this, sx, sy, width, height, remap);
}
inline VOID GraphicViewPortClass::Fill_Quad(VOID *span_buff, int x0, int y0, int x1, int y1,
							int x2, int y2, int x3, int y3, int color)
{
	MCGA_Fill_Quad(this, span_buff, x0, y0, x1, y1, x2, y2, x3, y3, color);
}

/***************************************************************************
 * GVPC::REMAP -- Short form to remap an entire graphic view port          *
 *                                                                         *
 * INPUT:		BYTE * to the remap table to use										*
 *                                                                         *
 * OUTPUT:     none                                                        *
 *                                                                         *
 * HISTORY:                                                                *
 *   07/01/1994 PWG : Created.                                             *
 *=========================================================================*/
inline VOID GraphicViewPortClass::Remap(VOID *remap)
{
	MCGA_Remap(this, 0, 0, Width, Height, remap);
}
/*=========================================================================*/
/* The following BufferClass functions are defined here because they act	*/
/*		on graphic viewports.																*/
/*=========================================================================*/


/***************************************************************************
 * BUFFER_TO_PAGE -- Generic 'c' callable form of Buffer_To_Page           *
 *                                                                         *
 * INPUT: 																						*
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/12/1995 PWG : Created.                                             *
 *=========================================================================*/
inline long Buffer_To_Page(int x, int y, int w, int h, void *Buffer, GraphicViewPortClass &view)
{
	return(MCGA_Buffer_To_Page(x, y, w, h, Buffer, &view));
}

/***************************************************************************
 * BC::TO_PAGE -- Copys a buffer class to a page with definable w, h 		*
 *                                                                         *
 * INPUT:		int	width		- the width of copy region							*
 *					int	height	- the height of copy region						*
 *					GVPC&	dest		- virtual viewport to copy to						*
 *                                                                         *
 * OUTPUT:		none                                                        *
 *																									*
 * WARNINGS:	x and y position are the upper left corner of the dest		*
 *						viewport																	*
 *                                                                         *
 * HISTORY:                                                                *
 *   07/01/1994 PWG : Created.                                             *
 *=========================================================================*/
inline long BufferClass::To_Page(int w, int h, GraphicViewPortClass &view)
{
	return(MCGA_Buffer_To_Page(0, 0, w, h, Buffer, &view));
}
/***************************************************************************
 * BC::TO_PAGE -- Copys a buffer class to a page with definable w, h 		*
 *                                                                         *
 * INPUT:		GVPC&	dest		- virtual viewport to copy to						*
 *                                                                         *
 * OUTPUT:		none                                                        *
 *																									*
 * WARNINGS:	x and y position are the upper left corner of the dest		*
 *						viewport.  width and height are assumed to be the			*
 *						viewport's width and height.										*
 *                                                                         *
 * HISTORY:                                                                *
 *   07/01/1994 PWG : Created.                                             *
 *=========================================================================*/
inline long BufferClass::To_Page(GraphicViewPortClass &view)
{
	return(MCGA_Buffer_To_Page(0, 0, view.Get_Width(), view.Get_Height(), Buffer, &view));
}
/***************************************************************************
 * BC::TO_PAGE -- Copys a buffer class to a page with definable x, y, w, h *
 *                                                                         *
 * INPUT:	int	x			- x pixel on viewport to copy from					*
 *				int	y			- y pixel on viewport to copy from					*
 *				int	width		- the width of copy region								*
 *				int	height	- the height of copy region							*
 *				GVPC&	dest		- virtual viewport to copy to							*
 *                                                                         *
 * OUTPUT:	none                                                           *
 *                                                                         *
 * HISTORY:                                                                *
 *   07/01/1994 PWG : Created.                                             *
 *=========================================================================*/
inline long BufferClass::To_Page(int x, int y, int w, int h, GraphicViewPortClass &view)
{
	return(MCGA_Buffer_To_Page(x, y, w, h, Buffer, &view));
}


#endif
