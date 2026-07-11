/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef NETUTILDEFS_HEADER
#define NETUTILDEFS_HEADER


#define NETUTIL_E_ERROR       MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 100)
#define NETUTIL_E_BUSY        MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 101)

#define NETUTIL_S_FINISHED    MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 500)

#endif