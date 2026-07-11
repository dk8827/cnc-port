/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef SOUND_H
#define SOUND_H

#define	HMI_DRIVER	TRUE
#include	"sos.h"
#include	"soscomp.h"

/*
**	Maximum number of sound effects that may run at once.
*/
#define	MAX_SFX		5

/*
** Size of temp HMI low memory staging buffer.
*/
#define	SFX_MINI_STAGE_BUFFER_SIZE		(1024*4)

#endif
