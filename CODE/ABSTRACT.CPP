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

/* $Header:   F:\projects\c&c\vcs\code\abstract.cpv   2.20   16 Oct 1995 16:49:04   JOE_BOSTIC  $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : ABSTRACT.CPP                                                 *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 01/26/95                                                     *
 *                                                                                             *
 *                  Last Update : May 22, 1995 [JLB]                                           *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   AbstractClass::Distance -- Determines distance to target.                                 *
 *   AbstractTypeClass::AbstractTypeClass -- Constructor for abstract type objects.            *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include	"function.h"


/***********************************************************************************************
 * AbstractClass::Distance -- Determines distance to target.                                   *
 *                                                                                             *
 *    This will determine the distance (direct line) to the target. The distance is in         *
 *    'leptons'. This routine is typically used for weapon range checks.                       *
 *                                                                                             *
 * INPUT:   target   -- The target to determine range to.                                      *
 *                                                                                             *
 * OUTPUT:  Returns with the range to the specified target (in leptons).                       *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   08/17/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
int AbstractClass::Distance(TARGET target) const
{
	/*
	**	Should subtract a fudge-factor distance for building targets.
	*/
	BuildingClass	*obj = As_Building(target);
	int dist = Distance(As_Coord(target));

	/*
	** If the object is a building the adjust it by the average radius
	** of the object.
	*/
	if (obj) {
		dist -= ((obj->Class->Width() + obj->Class->Height()) * (0x100 / 4));
		if (dist < 0) dist = 0;
	}

	/*
	** Return the distance to the target
	*/
	return(dist);
}


/***********************************************************************************************
 * AbstractTypeClass::AbstractTypeClass -- Constructor for abstract type objects.              *
 *                                                                                             *
 *    This is the constructor for AbstractTypeClass objects. It initializes the INI name and   *
 *    the text name for this object type.                                                      *
 *                                                                                             *
 * INPUT:   name  -- Text number for the full name of the object.                              *
 *                                                                                             *
 *          ini   -- The ini name for this object type.                                        *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/22/1995 JLB : Created.                                                                 *
 *=============================================================================================*/
AbstractTypeClass::AbstractTypeClass(int name, char const * ini)
{
	Name = name;
	strncpy((char *)IniName, ini, sizeof(IniName));
	((char &)IniName[sizeof(IniName)-1]) = '\0';
}

RTTIType AbstractTypeClass::What_Am_I(void) const {return RTTI_ABSTRACTTYPE;};
COORDINATE AbstractTypeClass::Coord_Fixup(COORDINATE coord) const {return coord;}
int AbstractTypeClass::Full_Name(void) const {return Name;};
unsigned short AbstractTypeClass::Get_Ownable(void) const {return 0xffff;};
