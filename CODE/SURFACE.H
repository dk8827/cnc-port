/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef SURFACE_H
#define SURFACE_H

#include	"buff.h"
#include	"rect.h"

/*
**	This class is used to represent an arbitrary rectangle in a graphic memory space. Typically,
**	this represents what could be called a graphic buffer or even a portion of a graphic buffer.
**	It can also represent a piece of artwork (such as a shape image) to be used to construct a
**	display image. This wide range of use is possible, because this class is a very minimal
**	representation of the graphic data. It holds only the information is absolutely needs and
**	has the minimum member functions possible.
*/
class Surface
{
	public:
		Surface(void) : Width(0), Height(0), Pitch(0) {}
		Surface(int w, int h, Buffer const * buffer=NULL, int pitch=0);
		Surface(Surface const & surface, int x, int y, int w, int h);
		virtual ~Surface(void) {}

		/*
		**	Basic manipulation routines for copying entire surfaces or
		**	a sub-region.
		*/
		void Copy_To(Rect const & fromrect, Surface & tosurface, Rect const & torect) const;
		void Copy_To(Rect const & fromrect, Buffer & tobuffer) const;

		/*
		**	Convenience routines that make presumptions on what is desired so that a
		**	minimum of parameters can be specified. These routine ultimately map to the
		**	basic copy routines.
		*/
		void Copy_To(Buffer & buffer, int x=0, int y=0, int w=-1, int h=-1) const;
		void Copy_From(Buffer const & buffer, int x=0, int y=0, int w=-1, int h=-1);

		/*
		**	Basic query functions. Support routines that will manipulate the underlying
		**	image data will require access to this information.
		*/
		void * Get_Buffer(void) const {return(SurfaceData.Get_Buffer());}
		int Get_Size(void) const {return(Bytes_Per_Line() * Height);}
		int Get_Width(void) const {return(Width);}
		int Get_Height(void) const {return(Height);}
		int Get_Pitch(void) const {return(Pitch);}

	protected:
		int Bytes_Per_Line(void) const {return(Width+Pitch);}

		/*
		**	This is the pointer to the surface memory. Sometimes this could be allocated memory
		**	managed by this class but more likely, it is memory that is merely referred to by
		**	this class.
		*/
		Buffer SurfaceData;

		/*
		**	This is the width (columns) of the surface (in pixels).
		*/
		int Width;

		/*
		**	This ithe height (rows) of the surface (in pixels).
		*/
		int Height;

		/*
		**	This is the modulus of the surface underlying memory 'display surface' width
		**	divided by this surface's width. For a surface that is full width, this value
		**	will be 0. This value will be non-zero if this surface is referring to a
		**	sub-region within another surface.
		*/
		int Pitch;
};


#endif
