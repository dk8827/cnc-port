/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

/*
    declarations for Win95 tracing facility
*/

#ifdef _DEBUG

#ifndef __TRACEW95__
#define __TRACEW95__

#include <windows.h>

// redefine all the MFC macros to point to us

#undef  TRACE
#define TRACE   OutputDebugStringW95

#undef  TRACE0
#define TRACE0   OutputDebugStringW95

#undef  TRACE1
#define TRACE1   OutputDebugStringW95

#undef  TRACE2
#define TRACE2   OutputDebugStringW95

#undef  TRACE3
#define TRACE3   OutputDebugStringW95

// redefine OutputDebugString so that it works with 
// API calls
#undef OutputDebugString
#define OutputDebugString   OutputDebugStringW95


// function declarations
void OutputDebugStringW95( LPCTSTR lpOutputString, ... );

#endif  //__TRACEW95__

#endif  // _DEBUG
