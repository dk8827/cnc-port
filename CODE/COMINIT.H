/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef COMINIT_HEADER
#define COMINIT_HEADER

//
// Link with this to automatically initialize COM at startup
//  - See cominit.cpp for more info
//

class ComInit
{
 public:
         ComInit();
        ~ComInit();
};

#endif
