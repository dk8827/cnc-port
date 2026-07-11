#include "../../../CODE/FUNCTION.H"
#include "../../../CODE/DRIVE.H"
#include "../../../CODE/EDIT.H"

#define POST_INC(EnumType) \
	EnumType operator++(EnumType &value, int) { EnumType old = value; value = (EnumType)((int)value + 1); return old; }

#define BITWISE_OPS(EnumType) \
	EnumType operator |(EnumType left, EnumType right) { return (EnumType)((int)left | (int)right); } \
	EnumType operator &(EnumType left, EnumType right) { return (EnumType)((int)left & (int)right); } \
	EnumType operator ~(EnumType value) { return (EnumType)(~(int)value); }

POST_INC(ThemeType)
POST_INC(HousesType)
POST_INC(BulletType)
POST_INC(FacingType)
POST_INC(SmudgeType)
POST_INC(StructType)
POST_INC(VesselType)
POST_INC(OverlayType)
POST_INC(TerrainType)
POST_INC(TheaterType)
POST_INC(AircraftType)
POST_INC(InfantryType)
POST_INC(TemplateType)
POST_INC(ScenarioVarType)
POST_INC(AnimType)
POST_INC(UnitType)
POST_INC(LayerType)

BITWISE_OPS(ThreatType)
BITWISE_OPS(TextPrintType)
BITWISE_OPS(ShapeFlags_Type)
BITWISE_OPS(DriveClass::TrackControlType)
BITWISE_OPS(EditClass::EditStyle)
BITWISE_OPS(GadgetClass::FlagEnum)

#undef BITWISE_OPS
#undef POST_INC
