;
; Copyright 2025 Electronic Arts Inc.
;
; Derived from Electronic Arts Inc.'s public source release for
; Command & Conquer: Red Alert.
; Licensed under GPLv3-or-later with additional Electronic Arts terms.
; Modified for the macOS port, 2026.
; See LICENSE.md.
;

;******************************************************************************
; Much testing was done to determine that only when there are 14 or more bytes
; being copied does it speed the time it takes to do copies in this algorithm.
; For this reason and because 1 and 2 byte copies crash, is the special case
; used.  SKB 4/21/94.  Tested on 486 66mhz.  Copied by PWG 6/7/04.
OPTIMAL_BYTE_COPY	equ	14

STRUC GraphicViewPort
GVPOffset		DD		?		; offset to virtual viewport
GVPWidth			DD		?		; width of virtual viewport
GVPHeight		DD		?		; height of virtual viewport
GVPXAdd			DD		?		; x mod to get to next line
GVPXPos			DD		?		; x pos relative to Graphic Buff
GVPYPos			DD		?		; y pos relative to Graphic Buff
GVPPitch		dd		?		; modulo of graphic view port
GVPBuffPtr		DD		?		; ptr to associated Graphic Buff
ENDS