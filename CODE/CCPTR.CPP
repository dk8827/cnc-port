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

/*
**	These member functions for the CCPtr class cannot be declared inside the
**	class definition since they could refer to other objects that themselves
**	contain CCPtr objects. The recursive nature of this type of declaration
**	is not handled by Watcom, hence the body declaration is dislocated here.
*/
template<class T>
CCPtr<T>::CCPtr(T * ptr) : ID(-1)
{
	if (ptr != NULL) {
		ID = ptr->ID;
	}
}


/***********************************************************************************************
 * CCPtr<T>::operator > -- Greater than comparison operator.                                   *
 *                                                                                             *
 *    This will compare two pointer value to see if the left hand value is greater than the    *
 *    right hand. The values are compared by comparing based on their Name() functions.        *
 *                                                                                             *
 * INPUT:   rvalue   -- The right handle CCPtr value.                                          *
 *                                                                                             *
 * OUTPUT:  Is the left hand value greater than the right hand value?                          *
 *                                                                                             *
 * WARNINGS:   The values pointed to by CCPtr must have a Name() function defined.             *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
bool CCPtr<T>::operator > (CCPtr<T> const & rvalue) const
{
	return (stricmp((*this)->Name(), rvalue->Name()) > 0);
}

template class CCPtr<HouseClass>;
template class CCPtr<FactoryClass>;
template class CCPtr<TriggerClass>;
template class CCPtr<AnimTypeClass>;
template class CCPtr<TeamTypeClass>;
template class CCPtr<UnitTypeClass>;
template class CCPtr<HouseTypeClass>;
template class CCPtr<BulletTypeClass>;
template class CCPtr<SmudgeTypeClass>;
template class CCPtr<VesselTypeClass>;
template class CCPtr<OverlayTypeClass>;
template class CCPtr<TerrainTypeClass>;
template class CCPtr<TriggerTypeClass>;
template class CCPtr<AircraftTypeClass>;
template class CCPtr<BuildingTypeClass>;
template class CCPtr<InfantryTypeClass>;
template class CCPtr<TemplateTypeClass>;
template class CCPtr<TeamClass>;
