/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef WIN32
#define WIN32
#ifndef _WIN32 // Denzil 6/2/98 Watcom 11.0 complains without this check
#define _WIN32
#endif // _WIN32
#endif	//WIN32
#include <windows.h>



class ModemRegistryEntryClass {

	public:

		ModemRegistryEntryClass (int modem_number);
		~ModemRegistryEntryClass (void);


		char *Get_Modem_Name (void) { return (ModemName); }

		char *Get_Modem_Device_Name (void) { return (ModemDeviceName); }

		char *Get_Modem_Error_Correction_Enable (void) { return (ErrorCorrectionEnable); }

		char *Get_Modem_Error_Correction_Disable (void) { return (ErrorCorrectionDisable); }

		char *Get_Modem_Compression_Enable (void) { return (CompressionEnable); }

		char *Get_Modem_Compression_Disable (void) { return (CompressionDisable); }

		char *Get_Modem_Hardware_Flow_Control (void) { return (HardwareFlowControl); }

		char *Get_Modem_No_Flow_Control (void) { return (HardwareFlowControl); }

	private:

		char *ModemName;
		char *ModemDeviceName;
		char *ErrorCorrectionEnable;
		char *ErrorCorrectionDisable;
		char *CompressionEnable;
		char *CompressionDisable;
		char *HardwareFlowControl;
		char *NoFlowControl;

};







