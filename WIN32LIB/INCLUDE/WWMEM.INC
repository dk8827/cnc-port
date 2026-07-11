;
; Copyright 2025 Electronic Arts Inc.
;
; Derived from Electronic Arts Inc.'s public source release for
; Command & Conquer: Red Alert.
; Licensed under GPLv3-or-later with additional Electronic Arts terms.
; Modified for the macOS port, 2026.
; See LICENSE.md.
;

MEM_NORMAL EQU 0000h		; Default memory (normal).
MEM_NEW	   EQU 0001h		; Called by the operator new and was overloaded.
MEM_CLEAR  EQU 0002h 		;

GLOBAL		@Alloc$qul14MemoryFlagType:PROC
GLOBAL		@Free$qpv:PROC
