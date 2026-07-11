/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef CARRY_H
#define CARRY_H

class CarryoverClass : public LinkClass {
	public:
		CarryoverClass(TechnoClass * techno = 0);
		CarryoverClass(NoInitClass const & x) : LinkClass(x) {}

		bool Create(void) const;

	protected:
		/*
		**	What type of object this is.
		*/
		RTTIType RTTI;

		/*
		**	This is the object type that is to be carried over. The exact nature of
		**	this type depends on the RTTI value. Only certain object types are
		**	recorded.
		*/
		union {
			StructType Building;
			UnitType Unit;
			InfantryType Infantry;
			VesselType Vessel;
		} Type;

		/*
		**	The location of the object.
		*/
		CELL Cell;

		/*
		**	The strength of the object at the time is was recorded.
		*/
		int Strength;

		/*
		**	This is the owner of the object.
		*/
		HousesType House;
};


#endif
