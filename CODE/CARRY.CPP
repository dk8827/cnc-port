/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include	"function.h"


/***********************************************************************************************
 * CarryoverClass::CarryoverClass -- Constructor for carry over objects.                       *
 *                                                                                             *
 *    This is the constructor for a carry over object. Such an object is used to record the    *
 *    object that will be "carried over" into a new scenario at some future time.              *
 *                                                                                             *
 * INPUT:   techno   -- Pointer to the object that will be carried over.                       *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/10/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
CarryoverClass::CarryoverClass(TechnoClass * techno) :
	RTTI(RTTI_NONE),
	Cell(0),
	Strength(0),
	House(HOUSE_NONE)
{
	if (techno) {
		RTTI = techno->What_Am_I();

		switch (RTTI) {
			case RTTI_UNIT:
				Type.Unit = ((UnitClass *)techno)->Class->Type;
				break;

			case RTTI_BUILDING:
				Type.Building = ((BuildingClass *)techno)->Class->Type;
				break;

			case RTTI_INFANTRY:
				Type.Infantry = ((InfantryClass *)techno)->Class->Type;
				break;

			case RTTI_VESSEL:
				Type.Vessel = ((VesselClass *)techno)->Class->Type;
				break;

			default:
				break;
		}

		House = techno->Owner();
		Strength = techno->Strength;
		Cell = Coord_Cell(techno->Coord);
	}
}


/***********************************************************************************************
 * CarryoverClass::Create -- Creates a carried over object.                                    *
 *                                                                                             *
 *    Use this routine to convert a carried over object into an actual object that will be     *
 *    placed on the map.                                                                       *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  bool; Was the object successfully created and placed on the map?                   *
 *                                                                                             *
 * WARNINGS:   This routine might not place the object if the old map location was invalid     *
 *             or there are other barriers to the object's creation and placement.             *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/10/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool CarryoverClass::Create(void) const
{
	TechnoClass * techno = 0;
	TechnoTypeClass const * ttype = 0;

	switch (RTTI) {
		case RTTI_UNIT:
			ttype = &UnitTypeClass::As_Reference(Type.Unit);
			techno = new UnitClass(Type.Unit, House);
			break;

		case RTTI_INFANTRY:
			ttype = &InfantryTypeClass::As_Reference(Type.Infantry);
			techno = new InfantryClass(Type.Infantry, House);
			break;

		case RTTI_BUILDING:
			ttype = &BuildingTypeClass::As_Reference(Type.Building);
			techno = new BuildingClass(Type.Building, House);
			break;

		case RTTI_VESSEL:
			ttype = &VesselTypeClass::As_Reference(Type.Vessel);
			techno = new VesselClass(Type.Vessel, House);
			break;
	}

	if (techno) {
		bool oldscen = ScenarioInit;
		techno->Strength = Strength;
		if (RTTI == RTTI_INFANTRY) {
			ScenarioInit = 0;
		}
		techno->Unlimbo(Cell_Coord(Cell));
		if (RTTI == RTTI_INFANTRY) {
			ScenarioInit = oldscen;
		}
	}

	return(false);
}

