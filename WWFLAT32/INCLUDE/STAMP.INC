;
; Copyright 2025 Electronic Arts Inc.
;
; Derived from Electronic Arts Inc.'s public source release for
; Command & Conquer: Red Alert.
; Licensed under GPLv3-or-later with additional Electronic Arts terms.
; Modified for the macOS port, 2026.
; See LICENSE.md.
;

; This is the control structure at the start of a loaded icon set.  It must match
; the structure in ICONSET.C!
	STRUC	IControl_Type
Width		DW	?	; Width in pixels (per icon).
Height		DW	?	; Height in pixels (per icon).
Count		DW	?	; Number of icons in this set.
Allocated	DW	?	; Was this iconset allocated?
MapWidth	DW	?	; Width of icon map (in icons).
MapHeight	DW	?	; Height of icon map (in icons).
Size		DD	?	; Size of entire iconset memory block.
Icons		DD	?	; Offset from buffer start to icon data.
Palettes	DD	?	; Offset from buffer start to palette data.
Remaps		DD	?	; Offset from buffer start to remap index data.
TransFlag	DD	?	; Offset for transparency flag data.
ColorMap	DD	?	; Color control map offset.
Map		DD	?	; Icon map offset.
	ENDS

ICON256	EQU	1

