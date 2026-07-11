;
; Copyright 2025 Electronic Arts Inc.
;
; Derived from Electronic Arts Inc.'s public source release for
; Command & Conquer: Red Alert.
; Licensed under GPLv3-or-later with additional Electronic Arts terms.
; Modified for the macOS port, 2026.
; See LICENSE.md.
;

;USE_PROFILER	=1


macro	prologue
Ifdef USE_PROFILER
		global	__PRO:near

		call		__PRO
endif ;USE_PROFILER
endm



macro epilogue
ifdef USE_PROFILER
		global	__EPI:near

		push		ebp
		call		__EPI
		pop			ebp
endif ;USE_PROFILER
endm



