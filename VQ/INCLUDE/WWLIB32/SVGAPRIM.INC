;
; Copyright 2025 Electronic Arts Inc.
;
; Derived from Electronic Arts Inc.'s public source release for
; Command & Conquer: Red Alert.
; Licensed under GPLv3-or-later with additional Electronic Arts terms.
; Modified for the macOS port, 2026.
; See LICENSE.md.
;

; Externs from VIDEO.CPP module of the VIDEO library
GLOBAL BankTable			:DWORD
GLOBAL VesaFunc			:DWORD
GLOBAL XRes					:DWORD
GLOBAL YRes					:DWORD
GLOBAL CurrentMode		:DWORD
global cpu_video_page	:dword
global cpu_page_limit   :dword


; Externs from VESA.ASM module of the SVGAPRIM library
GLOBAL Vesa_Asm_Set_Win		:NEAR
GLOBAL Vesa_Asm_Next_Win		:NEAR

; Externs from VGETPIX.ASM module of the SVGA/MCGAPRIM library
GLOBAL Vesa_Get_Pixel          	:NEAR

; Externs from VPUTTPIX.ASM module of the SVGA/MCGAPRIM library
GLOBAL Vesa_Put_Pixel 		:NEAR


; Externs from VCLEAR.ASM module of the MCGA/SVGAPRIM library
GLOBAL Vesa_Clear			:NEAR

; Externs from VBITBLIT.ASM module of the MCGA/SVGAPRIM library
GLOBAL Linear_Blit_To_Vesa		:NEAR
GLOBAL Vesa_Blit_To_Linear		:NEAR
GLOBAL Vesa_Blit_To_Vesa		:NEAR

; Externs from VTOBUFF.ASM module of the SVGA/MCGAPRIM library
GLOBAL Vesa_To_Buffer		:NEAR

; Externs from VTOPAGE.ASM module of the SVGA/MCGAPRIM library
GLOBAL Vesa_Buffer_To_Page		:NEAR

; Externs from VSCALE.ASM module of the SVGA/MCGAPRIM library
GLOBAL Linear_Scale_To_Vesa 		:NEAR
GLOBAL Vesa_Scale_To_Linear		:NEAR
GLOBAL Vesa_Scale_To_Vesa 		:NEAR


; Externs from VSCALE.ASM module of the SVGA/MCGAPRIM library
GLOBAL Vesa_Print	 		:NEAR
