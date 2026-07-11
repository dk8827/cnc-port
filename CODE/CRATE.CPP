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
 * CrateClass::Remove_It -- Removes the crate from wherever it is.                             *
 *                                                                                             *
 *    This routine will remove the crate from whereever it happens to be.                      *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  bool; Was the crate found and removed?                                             *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   08/26/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool CrateClass::Remove_It(void)
{
	if (Is_Valid()) {
		Get_Crate(Cell);
		Make_Invalid();
		return(true);
	}
	return(false);
}


/***********************************************************************************************
 * CrateClass::Create_Crate -- Create a crate in the cell specified.                           *
 *                                                                                             *
 *    This will create a crate in the cell specified. If the crate could not be crated there   *
 *    then 'false' will be returned.                                                           *
 *                                                                                             *
 * INPUT:   cell  -- The desired cell to place the crate in.                                   *
 *                                                                                             *
 * OUTPUT:  bool; Was the crate created and placed in the cell?                                *
 *                                                                                             *
 * WARNINGS:   It is quite possible for the crate not to have been placed. Only the most clear *
 *             locations are valid for crate placement.                                        *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   08/26/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool CrateClass::Create_Crate(CELL cell)
{
	/*
	**	Remove any existing crate that this crate class is tracking.
	*/
	Remove_It();

	/*
	**	Try to place a new crate at the cell specified.
	*/
	if (Put_Crate(cell)) {
		Cell = cell;
		Timer = Random_Pick(Rule.CrateTime * (TICKS_PER_MINUTE/2), Rule.CrateTime * (TICKS_PER_MINUTE*2));
		Timer.Start();
		return(true);
	}
	return(false);
}


/***********************************************************************************************
 * CrateClass::Put_Crate -- Generates crate overlay at cell specified.                         *
 *                                                                                             *
 *    This helpter routine will examine the cell and place the appropriate crate type into     *
 *    the cell specified. If the overlay could not be generated, then 'false' is returned.     *
 *                                                                                             *
 * INPUT:   cell  -- The cell to generate the crate overlay in.                                *
 *                                                                                             *
 * OUTPUT:  bool; Was the crate overlay generated?                                             *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   08/26/1996 JLB : Created.                                                                 *
 *   10/14/1996 JLB : Takes reference to cell so that tracking can occur.                      *
 *=============================================================================================*/
bool CrateClass::Put_Crate(CELL & cell)
{
	int old = ScenarioInit;
	ScenarioInit = 0;

	if (Map.In_Radar(cell)) {
		CellClass * cellptr = &Map[cell];

		while (cellptr->Overlay != OVERLAY_NONE && !cellptr->Is_Clear_To_Build(SPEED_FLOAT) && !cellptr->Is_Clear_To_Build(SPEED_FOOT)) {
			cell = Map.Pick_Random_Location();

			if (Percent_Chance(100 * Rule.WaterCrateChance)) {
				cell = Map.Nearby_Location(cell, SPEED_FLOAT);
			} else {
				cell = Map.Nearby_Location(cell, SPEED_TRACK);
			}
			cellptr = &Map[cell];
		}

		if (cellptr->Is_Clear_To_Build(SPEED_FLOAT)) {
			new OverlayClass(OVERLAY_WATER_CRATE, cell);
		} else {
			new OverlayClass(OVERLAY_WOOD_CRATE, cell);
		}
		ScenarioInit = old;
		return(true);
	}

	ScenarioInit = old;
	return(false);
}


/***********************************************************************************************
 * CrateClass::Get_Crate -- Pick up a crate from the cell specified.                           *
 *                                                                                             *
 *    This will remove the crate from the cell specified.                                      *
 *                                                                                             *
 * INPUT:   cell  -- The cell to examine and remove any crate overlays present.                *
 *                                                                                             *
 * OUTPUT:  bool; Was a crate overlay found and removed?                                       *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   08/26/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool CrateClass::Get_Crate(CELL cell)
{
	if (Map.In_Radar(cell)) {
		CellClass * cellptr = &Map[cell];

		if (cellptr->Overlay == OVERLAY_WOOD_CRATE ||
			cellptr->Overlay == OVERLAY_STEEL_CRATE ||
			cellptr->Overlay == OVERLAY_WATER_CRATE) {

			cellptr->Overlay = OVERLAY_NONE;
			cellptr->OverlayData = 0;
			cellptr->Redraw_Objects();
			return(true);
		}
	}
	return(false);
}
