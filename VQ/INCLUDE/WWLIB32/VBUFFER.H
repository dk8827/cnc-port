/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VBUFFER_H
#define VBUFFER_H

/*=========================================================================*/
/* If we have not already loaded the standard library header, than we can	*/
/*		load it.																					*/
/*=========================================================================*/
#ifndef WWSTD_H
#include "wwstd.h"
#endif


/*=========================================================================*/
/* The video buffer class is dependant on a buffer class so we need to		*/
/*		include the definitions for that as well.										*/
/*=========================================================================*/
#ifndef BUFFER_H
#include "buffer.h"
#endif

/*=========================================================================*/
/* The video buffer class is dependant on a buffer class so we need to		*/
/*		include the definitions for that as well.										*/
/*=========================================================================*/
#ifndef GBUFFER_H
#include "gbuffer.h"
#endif

/*=========================================================================*/
/* Define external assembly funcs which deals with buffers and viewports.	*/
/*=========================================================================*/
long Buffer_To_Page(int x, int y, int w, int h, void *Buffer, VideoViewPortClass &view);

/*=========================================================================*/
/* Define the screen width and height to make portability to other modules	*/
/*		easier.																					*/
/*=========================================================================*/
#define	DEFAULT_SCREEN_WIDTH		320
#define	DEFAULT_SCREEN_HEIGHT	200

/*=========================================================================*/
/* Define functions which have not under-gone name mangling						*/
/*=========================================================================*/
#ifdef __cplusplus
extern "C" {
	extern UWORD Get_MCGA_Selector(VOID);
}
#endif

/*=========================================================================*/
/* Let the compiler know that a VideoBufferClass exists so that it can		*/
/*		keep a pointer to it in a VideoViewPortClass.								*/
/*=========================================================================*/
class VideoBufferClass;


/*=========================================================================*/
/* VideoViewPortClass - Holds viewport information which has been attached	*/
/*		to a VideoBuffer.  A viewport is effectively a	rectangular subset   */
/*    of the full buffer which is used for clipping and the like.				*/
/*																									*/
/*			int 		Selector	-		is the selector to view port buffer			*/
/*			char	  	*Buffer	-		is the offset to view port buffer			*/
/*			int	  	Width		-		is the width of view port						*/
/*			int	  	Height	-		is the height of view port						*/
/*			int	  	XAdd		-		is add value to go from the end of a line	*/
/*											to the beginning of the next line			*/
/*			int		XPos;		- 		x offset into its associated VideoBuffer	*/
/*			int		YPos;		-		y offset into its associated VideoBuffer	*/
/*=========================================================================*/
class VideoViewPortClass {
	public:
		/*===================================================================*/
		/* Define the base constructor and destructors for the class			*/
		/*===================================================================*/
		VideoViewPortClass(VideoBufferClass* graphic_buff, int x, int y, int w, int h);
		VideoViewPortClass();
		~VideoViewPortClass();
		/*===================================================================*/
		/* Define functions to get at the private data members					*/
		/*===================================================================*/
		long	Get_Offset(void);
		int	Get_Height(void);
		int	Get_Width(void);
		int	Get_XAdd(void);
		int	Get_XPos(void);
		int	Get_YPos(void);
		VideoBufferClass *Get_Video_Buffer(void);

		/*===================================================================*/
		/* Define a function which allows us to change a video viewport on	*/
		/*		the fly.																			*/
		/*===================================================================*/
		BOOL Change(int x, int y, int w, int h);

		/*===================================================================*/
		/* Define the set of graphic functions that are members of a Video   */
		/*		ViewPort class.																*/
		/*===================================================================*/
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
		unsigned long  Print(char const *string, int x, int y, int fcolor, int bcolor);
		unsigned long	Print(int num, int x, int y, int fcol, int bcol);
		unsigned long	Print(short num, int x, int y, int fcol, int bcol);
		unsigned long	Print(long num, int x, int y, int fcol, int bcol);

	protected:
		/*===================================================================*/
		/* Define functions to attach the viewport to a graphicbuffer			*/
		/*===================================================================*/
		void Attach(VideoBufferClass *video_buff, int x, int y, int w, int h);
		void Attach(VideoBufferClass *video_buff, int w, int h);

		/*===================================================================*/
		/* Define the data used by a GraphicViewPortClass							*/
		/*===================================================================*/
		long						Offset;					// offset to graphic page
		int						Width;					// width of graphic page
		int						Height;					// height of graphic page
		int						XAdd;						// xadd for graphic page (0)
		int						XPos;						// x offset in relation to graphicbuff
		int						YPos;						// y offset in relation to graphicbuff
		VideoBufferClass	   *VideoBuff;				// related graphic buff
};


/*=========================================================================*/
/* VideoBufferClass - A VideoBuffer refers to an actual instance of a		*/
/*		physcial device which has been mapped to a memory address like a 		*/
/*		video card.  The VideoBuffer can be drawn to directly because it		*/
/*		inherits a Video ViewPort which represent its full size.					*/
/*		size.																						*/
/*																									*/
/*			int	  	Selector	-		is now the selector to graphic buffer		*/
/*			char	  	*Buffer	-		is now the offset to graphic buffer			*/
/*			int	  	Width		-		is now the width of graphic buffer			*/
/*			int	  	Height	-		is now the height of graphic buffer			*/
/*			int	  	XAdd		-		is now the xadd of graphic buffer			*/
/*			int		XPos;		- 		will be 0 because it is graphicbuff			*/
/*			int		YPos;		-		will be 0 because it is graphicbuff			*/
/*=========================================================================*/
class VideoBufferClass: public VideoViewPortClass {
	public:
		/*===================================================================*/
		/* Define the base constructor and destructors for the class			*/
		/*===================================================================*/
		VideoBufferClass(unsigned short selector, long offset, int w, int h);
		VideoBufferClass(int w = DEFAULT_SCREEN_WIDTH, int h = DEFAULT_SCREEN_HEIGHT);
		~VideoBufferClass();
};

/***************************************************************************
 * VVPC::GET_OFFSET -- Get offset for virtual view port class instance     *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     long the offset for the virtual viewport instance           *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/07/1994 PWG : Created.                                             *
 *=========================================================================*/
inline long VideoViewPortClass::Get_Offset(void)
{
	return(Offset);
}

/***************************************************************************
 * VVPC::GET_HEIGHT -- Gets the height of a virtual viewport instance      *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     int the height of the virtual viewport instance             *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/07/1994 PWG : Created.                                             *
 *=========================================================================*/
inline int VideoViewPortClass::Get_Height(void)
{
	return(Height);
}

/***************************************************************************
 * VVPC::GET_WIDTH -- Get the width of a virtual viewport instance			*
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     int the width of the virtual viewport instance              *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/07/1994 PWG : Created.                                             *
 *=========================================================================*/
inline int VideoViewPortClass::Get_Width(void)
{
	return(Width);
}


/***************************************************************************
 * VVPC::GET_XADD -- Get the X add offset for virtual viewport instance    *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     int the xadd for a virtual viewport instance                *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/07/1994 PWG : Created.                                             *
 *=========================================================================*/
inline int VideoViewPortClass::Get_XAdd(void)
{	
	return(XAdd);
}
/***************************************************************************
 * VVPC::GET_XPOS -- Get the x pos of the VP on the Video                  *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     int the x offset to VideoBufferClass								*
 *                                                                         *
 * HISTORY:                                                                *
;*   08/22/1994 SKB : Created.                                             *
 *=========================================================================*/
inline int VideoViewPortClass::Get_XPos(void)
{
	return(XPos);
}


/***************************************************************************
 * VVPC::GET_YPOS -- Get the y pos of the VP on the video                  *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     int the x offset to VideoBufferClass								*
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
;*   08/22/1994 SKB : Created.                                             *
 *=========================================================================*/
inline int VideoViewPortClass::Get_YPos(void)
{
	return(YPos);
}

/***************************************************************************
 * VVPC::GET_GRAPHIC_BUFFER -- Get the graphic buffer of the VP.           *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * HISTORY:                                                                *
 *   08/22/1994 SKB : Created.                                             *
 *=========================================================================*/
inline VideoBufferClass *VideoViewPortClass::Get_Video_Buffer(void)
{
 	return (VideoBuff);
}

/***************************************************************************
 * VVPC::PUT_PIXEL -- stub to call curr graphic mode Put_Pixel					*
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
inline void	VideoViewPortClass::Put_Pixel(int x, int y, unsigned char color)
{
	VVPC_Put_Pixel_Func(this, x, y, color);
}

/***************************************************************************
 * VVPC::GET_PIXEL -- stub to call curr graphic mode Get_Pixel          	*
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
inline int	VideoViewPortClass::Get_Pixel(int x, int y)
{
	return(VVPC_Get_Pixel_Func(this, x, y));
}

/***************************************************************************
 * VVPC::CLEAR -- stub to call curr graphic mode Clear	                  *
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
inline void	VideoViewPortClass::Clear(unsigned char color)
{
	VVPC_Clear_Func(this, color);
}

/***************************************************************************
 * VVPC::TO_BUFFER -- stub 1 to call curr graphic mode To_Buffer				*
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
inline long	VideoViewPortClass::To_Buffer(int x, int y, int w, int h, void *buff, long size)
{
	return(VVPC_To_Buffer_Func(this, x, y, w, h, buff, size));
}

/***************************************************************************
 * VVPC::TO_BUFFER -- stub 2 to call curr graphic mode To_Buffer 				*
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
inline long	VideoViewPortClass::To_Buffer(int x, int y, int w, int h, BufferClass *buff)
{
	return(VVPC_To_Buffer_Func(this, x, y, w, h, buff->Get_Buffer(), buff->Get_Size()));
}

/***************************************************************************
 * VVPC::TO_BUFFER -- stub 3 to call curr graphic mode To_Buffer 				*
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
inline long	VideoViewPortClass::To_Buffer(BufferClass *buff)
{
	return(VVPC_To_Buffer_Func(this, 0, 0, Width, Height, buff->Get_Buffer(), buff->Get_Size()));
}

/***************************************************************************
 * VVPC::BLIT -- stub 1 to call curr graphic mode Blit to GVPC					*
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
inline BOOL	VideoViewPortClass::Blit(	GraphicViewPortClass& dest, int x_pixel, int y_pixel, int dx_pixel, 
				int dy_pixel, int pixel_width, int pixel_height, BOOL trans)
{
	return(VVPC_Blit_to_GVPC_Func(this, &dest, x_pixel, y_pixel, dx_pixel, dy_pixel, pixel_width, pixel_height, trans));
}

/***************************************************************************
 * VVPC::BLIT -- Stub 2 to call curr graphic mode Blit to GVPC					*
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
inline BOOL	VideoViewPortClass::Blit(	GraphicViewPortClass& dest, int dx, int dy, BOOL trans)
{
	return(VVPC_Blit_to_GVPC_Func(this, &dest, 0, 0, dx, dy, Width, Height, trans));
}

/***************************************************************************
 * VVPC::BLIT -- stub 3 to call curr graphic mode Blit to GVPC					*
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
inline BOOL	VideoViewPortClass::Blit(	GraphicViewPortClass& dest, BOOL trans)
{
	return(VVPC_Blit_to_GVPC_Func(this, &dest, 0, 0, 0, 0, Width, Height, trans));
}

/***************************************************************************
 * VVPC::BLIT -- stub 1 to call curr graphic mode Blit to VVPC					*
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
inline BOOL	VideoViewPortClass::Blit(	VideoViewPortClass& dest, int x_pixel, int y_pixel, int dx_pixel, 
				int dy_pixel, int pixel_width, int pixel_height, BOOL trans)
{
	return(VVPC_Blit_to_VVPC_Func(this, &dest, x_pixel, y_pixel, dx_pixel, dy_pixel, pixel_width, pixel_height, trans));
}

/***************************************************************************
 * VVPC::BLIT -- stub 2 to call curr graphic mode Blit to VVPC					*
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
inline BOOL	VideoViewPortClass::Blit(	VideoViewPortClass& dest, int dx, int dy, BOOL trans)
{
	return(VVPC_Blit_to_VVPC_Func(this, &dest, 0, 0, dx, dy, Width, Height, trans));
}

/***************************************************************************
 * VVPC::BLIT -- stub 3 to call curr graphic mode Blit to VVPC					*
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
inline BOOL	VideoViewPortClass::Blit(	VideoViewPortClass& dest, BOOL trans)
{
	return(VVPC_Blit_to_VVPC_Func(this, &dest, 0, 0, 0, 0, Width, Height, trans));
}

/***************************************************************************
 * VVPC::SCALE -- stub 1 to call curr graphic mode Scale to GVPC				*
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
inline BOOL	VideoViewPortClass::Scale(	GraphicViewPortClass &dest, int src_x, int src_y, int dst_x, 
					int dst_y, int src_w, int src_h, int dst_w, int dst_h, BOOL trans, char *remap)
{
	return(VVPC_Scale_To_GVPC(	this, &dest, src_x, src_y, dst_x, dst_y, src_w, src_h, dst_w, dst_h, trans, remap));
}

/***************************************************************************
 * VVPC::SCALE -- stub 2 to call curr graphic mode Scale to GVPC				*
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
inline BOOL	VideoViewPortClass::Scale(	GraphicViewPortClass &dest, int src_x, int src_y, int dst_x, 
					int dst_y, int src_w, int src_h, int dst_w, int dst_h, char *remap)
{
	return(VVPC_Scale_To_GVPC(	this, &dest, src_x, src_y, dst_x, dst_y, src_w, src_h, dst_w, dst_h, FALSE, remap));
}

/***************************************************************************
 * VVPC::SCALE -- stub 3 to call curr graphic mode Scale to GVPC				*
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
inline BOOL	VideoViewPortClass::Scale(	GraphicViewPortClass &dest, BOOL trans, char *remap)
{
	return(VVPC_Scale_To_GVPC(	this, &dest, 0, 0, 0, 0, Width, Height, dest.Get_Width(), dest.Get_Height(), trans, remap));
}

/***************************************************************************
 * VVPC::SCALE -- stub 4 to call curr graphic mode Scale to GVPC				*
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
inline BOOL	VideoViewPortClass::Scale(	GraphicViewPortClass &dest, char *remap)
{
	return(VVPC_Scale_To_GVPC(	this, &dest, 0, 0, 0, 0, Width, Height, dest.Get_Width(), dest.Get_Height(), FALSE, remap));
}
/***************************************************************************
 * VVPC::SCALE -- stub 1 to call curr graphic mode Scale to VVPC				*
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
inline BOOL	VideoViewPortClass::Scale(	VideoViewPortClass &dest, int src_x, int src_y, int dst_x, 
					int dst_y, int src_w, int src_h, int dst_w, int dst_h, BOOL trans, char *remap)
{
	return(VVPC_Scale_To_VVPC(	this, &dest, src_x, src_y, dst_x, dst_y, src_w, src_h, dst_w, dst_h, trans, remap));
}

/***************************************************************************
 * VVPC::SCALE -- stub 2 to call curr graphic mode Scale to VVPC				*
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
inline BOOL	VideoViewPortClass::Scale(	VideoViewPortClass &dest, int src_x, int src_y, int dst_x, 
					int dst_y, int src_w, int src_h, int dst_w, int dst_h, char *remap)
{
	return(VVPC_Scale_To_VVPC(	this, &dest, src_x, src_y, dst_x, dst_y, src_w, src_h, dst_w, dst_h, FALSE, remap));
}

/***************************************************************************
 * VVPC::SCALE -- stub 3 to call curr graphic mode Scale to VVPC				*
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
inline BOOL	VideoViewPortClass::Scale(	VideoViewPortClass &dest, BOOL trans, char *remap)
{
	return(VVPC_Scale_To_VVPC(	this, &dest, 0, 0, 0, 0, Width, Height, dest.Get_Width(), dest.Get_Height(), trans, remap));
}

/***************************************************************************
 * VVPC::SCALE -- stub 4 to call curr graphic mode Scale to VVPC				*
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
inline BOOL	VideoViewPortClass::Scale(	VideoViewPortClass &dest, char *remap)
{
	return(VVPC_Scale_To_VVPC(	this, &dest, 0, 0, 0, 0, Width, Height, dest.Get_Width(), dest.Get_Height(), FALSE, remap));
}

/***************************************************************************
 * VVPC::PRINT -- Stub function to print string on a Video View Port       *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *=========================================================================*/
inline unsigned long	VideoViewPortClass::Print(char const *str, int x, int y, int fcol, int bcol)
{
	return(VVPC_Print_Func(this, str, x, y, fcol, bcol));
}

/***************************************************************************
 * VVPC::PRINT -- Stub function to print an int on a Video Viewport			*
 *                                                                         *
 *                                                                         *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *=========================================================================*/
inline unsigned long	VideoViewPortClass::Print(int num, int x, int y, int fcol, int bcol)
{
	BYTE str[17];

	return(VVPC_Print_Func(this, itoa(num, str, 10), x, y, fcol, bcol));
}


/***************************************************************************
 * VVPC::PRINT -- Stub function to print a short on a Video Viewport       *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *=========================================================================*/
inline unsigned long	VideoViewPortClass::Print(short num, int x, int y, int fcol, int bcol)
{
	BYTE str[17];

	
	return(VVPC_Print_Func(this, itoa(num, str, 10), x, y, fcol, bcol));
}

/***************************************************************************
 * VVPC::PRINT -- Stub function to print long on a Video Viewport				*
 *                                                                         *
 * INPUT:																						*
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/17/1995 PWG : Created.                                             *
 *=========================================================================*/
inline unsigned long	VideoViewPortClass::Print(long num, int x, int y, int fcol, int bcol)
{
	BYTE str[33];

	return(VVPC_Print_Func(this, ltoa(num, str, 10), x, y, fcol, bcol));
}


/*=========================================================================*/
/*= The following BufferClass functions are defined here because they act =*/
/*=	on video viewports.																  =*/
/*=========================================================================*/


/***************************************************************************
 * BC::TO_PAGE -- Copys a buffer class to a page with definable w, h 		*
 *                                                                         *
 * INPUT:		int	width		- the width of copy region							*
 *					int	height	- the height of copy region						*
 *					VIVC&	dest		- virtual viewport to copy to						*
 *                                                                         *
 * OUTPUT:		none                                                        *
 *																									*
 * WARNINGS:	x and y position are the upper left corner of the dest		*
 *						viewport																	*
 *                                                                         *
 * HISTORY:                                                                *
 *   07/01/1994 PWG : Created.                                             *
 *=========================================================================*/
inline long BufferClass::To_Page(int w, int h, VideoViewPortClass &view)
{
	return(VVPC_Buffer_To_Page(0, 0, w, h, Buffer, &view));
}
/***************************************************************************
 * BC::TO_PAGE -- Copys a buffer class to a page with definable w, h 		*
 *                                                                         *
 * INPUT:		VIVC&	dest		- virtual viewport to copy to						*
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
inline long BufferClass::To_Page(VideoViewPortClass &view)
{
	return(VVPC_Buffer_To_Page(0, 0, view.Get_Width(), view.Get_Height(), Buffer, &view));
}
/***************************************************************************
 * BC::TO_PAGE -- Copys a buffer class to a page with definable x, y, w, h *
 *                                                                         *
 * INPUT:	int	x			- x pixel on viewport to copy from					*
 *				int	y			- y pixel on viewport to copy from					*
 *				int	width		- the width of copy region								*
 *				int	height	- the height of copy region							*
 *				VIVC&	dest		- virtual viewport to copy to							*
 *                                                                         *
 * OUTPUT:	none                                                           *
 *                                                                         *
 * HISTORY:                                                                *
 *   07/01/1994 PWG : Created.                                             *
 *=========================================================================*/
inline long BufferClass::To_Page(int x, int y, int w, int h, VideoViewPortClass &view)
{
	return(VVPC_Buffer_To_Page(x, y, w, h, Buffer, &view));
}

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
inline long Buffer_To_Page(int x, int y, int w, int h, void *Buffer, VideoViewPortClass &view)
{
	return(VVPC_Buffer_To_Page(x, y, w, h, Buffer, &view));
}

/*=========================================================================*/
/* The following GraphicBufferClass functions are defined here because 		*/
/* they act	on graphic viewports.														*/
/*=========================================================================*/
/***************************************************************************
 * GVPC::BLIT -- stub 1 to call curr graphic mode Blit to VVPC					*
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
inline BOOL	GraphicViewPortClass::Blit(	VideoViewPortClass& dest, int x_pixel, int y_pixel, int dx_pixel, 
				int dy_pixel, int pixel_width, int pixel_height, BOOL trans)
{
	return(GVPC_Blit_to_VVPC_Func(this, &dest, x_pixel, y_pixel, dx_pixel, dy_pixel, pixel_width, pixel_height, trans));
}

/***************************************************************************
 * GVPC::BLIT -- stub 2 to call curr graphic mode Blit to VVPC					*
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
inline BOOL	GraphicViewPortClass::Blit(	VideoViewPortClass& dest, int dx, int dy, BOOL trans)
{
	return(GVPC_Blit_to_VVPC_Func(this, &dest, 0, 0, dx, dy, Width, Height, trans));
}

/***************************************************************************
 * GVPC::BLIT -- stub 3 to call curr graphic mode Blit to VVPC					*
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
inline BOOL	GraphicViewPortClass::Blit(	VideoViewPortClass& dest, BOOL trans)
{
	return(GVPC_Blit_to_VVPC_Func(this, &dest, 0, 0, 0, 0, Width, Height, trans));
}
/***************************************************************************
 * GVPC::SCALE -- stub 1 to call curr graphic mode Scale to VVPC				*
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
inline BOOL	GraphicViewPortClass::Scale(	VideoViewPortClass &dest, int src_x, int src_y, int dst_x, 
					int dst_y, int src_w, int src_h, int dst_w, int dst_h, BOOL trans, char *remap)
{
	return(GVPC_Scale_To_VVPC(	this, &dest, src_x, src_y, dst_x, dst_y, src_w, src_h, dst_w, dst_h, trans, remap));
}

/***************************************************************************
 * GVPC::SCALE -- stub 2 to call curr graphic mode Scale to VVPC				*
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
inline BOOL	GraphicViewPortClass::Scale(	VideoViewPortClass &dest, int src_x, int src_y, int dst_x, 
					int dst_y, int src_w, int src_h, int dst_w, int dst_h, char *remap)
{
	return(GVPC_Scale_To_VVPC(	this, &dest, src_x, src_y, dst_x, dst_y, src_w, src_h, dst_w, dst_h, FALSE, remap));
}

/***************************************************************************
 * GVPC::SCALE -- stub 3 to call curr graphic mode Scale to VVPC				*
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
inline BOOL	GraphicViewPortClass::Scale(	VideoViewPortClass &dest, BOOL trans, char *remap)
{
	return(GVPC_Scale_To_VVPC(	this, &dest, 0, 0, 0, 0, Width, Height, dest.Get_Width(), dest.Get_Height(), trans, remap));
}

/***************************************************************************
 * GVPC::SCALE -- stub 4 to call curr graphic mode Scale to VVPC				*
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
inline BOOL	GraphicViewPortClass::Scale(	VideoViewPortClass &dest, char *remap)
{
	return(GVPC_Scale_To_VVPC(	this, &dest, 0, 0, 0, 0, Width, Height, dest.Get_Width(), dest.Get_Height(), FALSE, remap));
}

#endif // VBUFFER_H
