/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#define	MAX_PROFILE_TIME	60*1		//1 minute(s) @ 14.4 Mb per hour
#define	PROFILE_RATE		1000	//samples per sec (max 1000)


/*
 * Defines for choosing between the old and new profiler system
 *
*/

#define	OLD_PROFILE_SYSTEM	1
#define	NEW_PROFILE_SYSTEM	2

//#define	PROFILE_SYSTEM			OLD_PROFILE_SYSTEM
#define	PROFILE_SYSTEM			NEW_PROFILE_SYSTEM



extern "C"{
	void __cdecl Profile_Init(void);
	void __cdecl Profile_End(void);
	void __cdecl Start_Profiler(void);
	void __cdecl Stop_Profiler(void);
}

