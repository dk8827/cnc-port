/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#if 0

#define debugprogress
#define _ASSERTE( x )

#else

#define debugprint			OutputDebugString

#define _DEBUG
#include "w95trace.h"

#define debugprogress debugprint( "...%s: %i\n", __FILE__, __LINE__ )
#define _ASSERTE( x )		if( !(x) )	debugprint( "ASSERT FALSE!\n" );

#endif
