/*
**	Command & Conquer(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* $Header:   F:\projects\c&c\vcs\code\anim.h_v   2.20   16 Oct 1995 16:45:40   JOE_BOSTIC  $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : ANIM.H                                                       *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : May 30, 1994                                                 *
 *                                                                                             *
 *                  Last Update : May 30, 1994   [JLB]                                         *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef ANIM_H
#define ANIM_H

#include	"type.h"

/**********************************************************************************************
**	This is the class that controls the shape animation objects. Shape animation objects are
**	displayed over the top of the game map. Typically, they are used for explosion and fire
**	effects.
*/
class AnimClass : public ObjectClass, private StageClass {
	public:

		static void * operator new(size_t size);
		static void operator delete(void *ptr);
		AnimClass(void) : Class(0) {Owner=HOUSE_NONE;Object=0;};		// Default constructor does nothing.
		AnimClass(AnimType animnum, COORDINATE coord, unsigned char timedelay=0, unsigned char loop=1, bool alt=false);
		virtual ~AnimClass(void);
		operator AnimType(void) const {return Class->Type;};
		virtual RTTIType What_Am_I(void) const {return RTTI_ANIM;};

		/*---------------------------------------------------------------------
		**	Member function prototypes.
		*/
		static void Init(void);

		void  Attach_To(ObjectClass *obj);
		void  Make_Invisible(void) {IsInvisible = true;};

		virtual bool Can_Place_Here(COORDINATE ) const {return true;}
		virtual bool Mark(MarkType mark=MARK_CHANGE);
		virtual bool Render(bool forced);
		virtual COORDINATE Center_Coord(void) const;
		virtual COORDINATE Sort_Y(void) const;
		virtual LayerType In_Which_Layer(void) const;
		virtual ObjectTypeClass const & Class_Of(void) const {return *Class;};
		virtual short const * Occupy_List(void) const;
		virtual short const * Overlap_List(void) const;
		virtual void Draw_It(int x, int y, WindowNumberType window);
		virtual void AI(void);
		virtual TARGET As_Target(void) const;
		virtual void Detach(TARGET target, bool all);

		/*
		**	File I/O.
		*/
		bool Load(FileClass & file);
		bool Save(FileClass & file);
		virtual void Code_Pointers(void);
		virtual void Decode_Pointers(void);

		/*
		**	Dee-buggin' support.
		*/
		int Validate(void) const;

		/*
		**	If this animation is attached to an object, then this points to that object. An
		**	animation that is attached will follow that object as it moves. This is important
		**	for animations such as flames and smoke.
		*/
		ObjectClass * Object;

		/*
		**	If this animation has an owner, then it will be recorded here. An owner
		**	is used when damage is caused by this animation during the middle of its
		**	animation.
		*/
		HousesType Owner;

		/*
		**	This counter tells how many more times the animation should loop before it
		**	terminates.
		*/
		unsigned char Loops;

	protected:
		void Middle(void);
		void Start(void);

	private:
		/*
		** Define a function to make adjustments for where special animations
		** are going to render.
		*/
		COORDINATE Adjust_Coord(COORDINATE coord);

		/*
		**	Delete this animation at the next opportunity. This is flagged when the
		**	animation is to be prematurely ended as a result of some outside event.
		*/
		unsigned IsToDelete:1;

		/*
		**	If the animation has just been created, then don't do any animation
		**	processing until it has been through the render loop at least once.
		*/
		unsigned IsBrandNew:1;

		// Use alternate color when drawing?
		unsigned IsAlternate:1;

		/*
		**	If this animation is invisible, then this flag will be true. An invisible
		**	animation is one that is created for the sole purpose of keeping all
		**	machines syncronised. It will not be displayed.
		*/
		unsigned IsInvisible:1;

		/*
		**	This points to the type of animation object this is.
		*/
		AnimTypeClass const * const Class;

		/*
		**	Is this animation in a temporary suspended state?  If so, then it won't
		**	be rendered until this flag is false. The flag will be set to false
		**	after the first countdown timer reaches 0.
		*/
		unsigned char Delay;

		/*
		**	If this is an animation that damages whatever it is attached to, then this
		**	value holds the accumulation of fractional damage points. When the accumulated
		**	fractions reach 256, then one damage point is applied to the attached object.
		*/
		unsigned char Accum;

		/*
		** This contains the value of the Virtual Function Table Pointer
		*/
		static void * VTable;
};



#endif
