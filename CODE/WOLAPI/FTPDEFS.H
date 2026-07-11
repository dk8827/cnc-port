/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef __FTPDEFS_H_INCLUDED__
#define __FTPDEFS_H_INCLUDED__


// CFtp return codes.

#define FTP_SUCCEEDED		S_OK
#define	FTP_FAILED			MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 1 )
#define FTP_TRYING			MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 2 )


#endif