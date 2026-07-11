/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include	"wwstd.h"
#include <timer.h>

void Delay(int duration)
{
	unsigned long count;
	TimerClass timer(BT_SYSTEM,TRUE);

	while (duration--) {
		count = timer.Time() + 1L;
		while (count >= timer.Time()) {
			;
		}
	}

#if(FALSE)
	while (duration--)
		Wait_Vert_Blank(VertBlank);
#endif
}

#if(FALSE)
void Vsync()
{
	Wait_Vert_Blank(VertBlank);
}
#endif
