/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef _MPGSETTINGS_H_
#define _MPGSETTINGS_H_

#include "function.h"

#ifdef DVD
#include "mci.h"
#include "rawfile.h"

class MPGSettings
	{
	public:
		MPGSettings(const char* deviceName);
		MPGSettings(FileClass& file);
		virtual ~MPGSettings(void);

		void SetDeviceName(const char* device);
		const char* GetDeviceName(void) const
			{return mDeviceName;}
		bool Save(FileClass& file);
		void Dialog(void);

		char* mDeviceName;

		#ifdef MCIMPEG
		MCI mMCI;
		unsigned int mCount;
		MCIDevice* mMCIDevices;
		#endif
	};

#endif // DVD
#endif // _MPGSETTINGS_H_
