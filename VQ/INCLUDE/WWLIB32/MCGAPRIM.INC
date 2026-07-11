;
; Copyright 2025 Electronic Arts Inc.
;
; Derived from Electronic Arts Inc.'s public source release for
; Command & Conquer: Red Alert.
; Licensed under GPLv3-or-later with additional Electronic Arts terms.
; Modified for the macOS port, 2026.
; See LICENSE.md.
;

; Externs from REGIONSZ.ASM module of the MCGAPRIM library
GLOBAL MCGA_Size_Of_Region	:NEAR

; Externs from GETPIX.ASM module of the MCGAPRIM library
GLOBAL MCGA_Get_Pixel          	:NEAR

; Externs from VGETPIX.ASM module of the SVGA/MCGAPRIM library
GLOBAL Vesa_Get_Pixel          	:NEAR

; Externs from PUTPIX.ASM module of the MCGAPRIM library
GLOBAL MCGA_Put_Pixel 		:NEAR

; Externs from VPUTTPIX.ASM module of the SVGA/MCGAPRIM library
GLOBAL Vesa_Put_Pixel 		:NEAR

; Externs from CLEAR.ASM module of the MCGAPRIM library
GLOBAL MCGA_Clear	          	:NEAR

; Externs from VCLEAR.ASM module of the MCGA/SVGAPRIM library
GLOBAL Vesa_Clear			:NEAR
; Externs from BITBLIT.ASM module of the MCGAPRIM library
GLOBAL Linear_Blit_To_Linear		:NEAR

; Externs from VBITBLIT.ASM module of the MCGA/SVGAPRIM library
GLOBAL Linear_Blit_To_Vesa		:NEAR
GLOBAL Vesa_Blit_To_Linear		:NEAR
GLOBAL Vesa_Blit_To_Vesa		:NEAR

; Externs from TOBUFF.ASM module of the MCGAPRIM library
GLOBAL MCGA_To_Buffer		:NEAR

; Externs from VTOBUFF.ASM module of the SVGA/MCGAPRIM library
GLOBAL Vesa_To_Buffer		:NEAR

; Externs from TOPAGE.ASM module of the MCGAPRIM library
GLOBAL MCGA_Buffer_To_Page		:NEAR

; Externs from VTOPAGE.ASM module of the SVGA/MCGAPRIM library
GLOBAL Vesa_Buffer_To_Page		:NEAR

; Externs from SCALE.ASM module of the MCGAPRIM library
GLOBAL Linear_Scale_To_Linear 	:NEAR

; Externs from VSCALE.ASM module of the SVGA/MCGAPRIM library
GLOBAL Linear_Scale_To_Vesa 		:NEAR
GLOBAL Vesa_Scale_To_Linear		:NEAR
GLOBAL Vesa_Scale_To_Vesa 		:NEAR

; Externs from TXTPRNT.ASM module of the MCGAPRIM library
GLOBAL MCGA_Print			:NEAR

; Externs from VTXTPRNT.ASM module of the SVGA/MCGAPRIM library
GLOBAL Vesa_Print			:NEAR

;*-------------------------------------------------------------------------*
;* Define MCGA only assembly GLOBALS					   *
;*-------------------------------------------------------------------------*

; Externs from DRAWLINE.ASM module of the MCGAPRIM library
GLOBAL MCGA_Draw_Line 		:NEAR

; Externs from FILLQUAD.ASM module of the MCGAPRIM library
GLOBAL MCGA_Fill_Quad 		:NEAR

; Externs from FILLRECT.ASM module of the MCGAPRIM library
GLOBAL MCGA_Fill_Rect 		:NEAR

; Externs from REMAP.ASM module of the MCGAPRIM library
GLOBAL MCGA_Remap      		:NEAR

; Externs from STAMP.ASM module of the MCGAPRIM library
GLOBAL MCGA_Draw_Stamp 		:NEAR

GLOBAL get_clip	 	   : NEAR

struc  RECTANGLE
		  x0	dd	?
		  y0 dd	?
		  x1	dd	?
		  y1 dd ?
ends 	 RECTANGLE




