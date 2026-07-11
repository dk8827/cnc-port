;
; Copyright 2025 Electronic Arts Inc.
;
; Derived from Electronic Arts Inc.'s public source release for
; Command & Conquer: Red Alert.
; Licensed under GPLv3-or-later with additional Electronic Arts terms.
; Modified for the macOS port, 2026.
; See LICENSE.md.
;

; Externs from REGIONSZ.ASM module of the DRAWBUFF library
GLOBAL C Buffer_Size_Of_Region	:NEAR

; Externs from GETPIX.ASM module of the DRAWBUFF library
GLOBAL C Buffer_Get_Pixel          	:NEAR

; Externs from PUTPIX.ASM module of the DRAWBUFF library
GLOBAL C Buffer_Put_Pixel 		:NEAR

; Externs from CLEAR.ASM module of the DRAWBUFF library
GLOBAL C Buffer_Clear	          	:NEAR

; Externs from BITBLIT.ASM module of the DRAWBUFF library
GLOBAL C Linear_Blit_To_Linear		:NEAR

; Externs from TOBUFF.ASM module of the DRAWBUFF library
GLOBAL C Buffer_To_Buffer		:NEAR

; Externs from TOPAGE.ASM module of the DRAWBUFF library
GLOBAL C Buffer_To_Page		:NEAR

; Externs from SCALE.ASM module of the DRAWBUFF library
GLOBAL C Linear_Scale_To_Linear 	:NEAR

; Externs from TXTPRNT.ASM module of the DRAWBUFF library
GLOBAL C Buffer_Print			:NEAR


;*-------------------------------------------------------------------------*
;* Define Buffer only assembly GLOBALS					   *
;*-------------------------------------------------------------------------*

; Externs from DRAWLINE.ASM module of the DRAWBUFF library
GLOBAL C Buffer_Draw_Line:NEAR

; Externs from FILLQUAD.ASM module of the DRAWBUFF library
GLOBAL C Buffer_Fill_Quad 		:NEAR

; Externs from FILLRECT.ASM module of the DRAWBUFF library
GLOBAL C Buffer_Fill_Rect 		:NEAR

; Externs from REMAP.ASM module of the DRAWBUFF library
GLOBAL C Buffer_Remap      		:NEAR

; Externs from STAMP.ASM module of the DRAWBUFF library
GLOBAL C Buffer_Draw_Stamp 		:NEAR

GLOBAL C get_clip	 	   : NEAR

struc  RECTANGLE
		  x0	dd	?
		  y0 dd	?
		  x1	dd	?
		  y1 dd ?
ends 	 RECTANGLE

