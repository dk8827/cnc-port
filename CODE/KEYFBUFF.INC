;
;	Command & Conquer(tm)
;	Copyright 2025 Electronic Arts Inc.
;
;	This program is free software: you can redistribute it and/or modify
;	it under the terms of the GNU General Public License as published by
;	the Free Software Foundation, either version 3 of the License, or
;	(at your option) any later version.
;
;	This program is distributed in the hope that it will be useful,
;	but WITHOUT ANY WARRANTY; without even the implied warranty of
;	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;	GNU General Public License for more details.
;
;	You should have received a copy of the GNU General Public License
;	along with this program.  If not, see <http://www.gnu.org/licenses/>.
;

;**************************************************************
;
; Macro to fetch the header of the next line and jump to the appropriate routine
;
next_line	macro

		add	edi,[dest_adjust_width]		;add in dest modulo
		dec	edx				;line counter
		jz	real_out			;return
		mov	ecx,[save_ecx]			;ecx is pixel count
		mov	eax,[header_pointer]		;ptr to next header byte
		mov	al,[eax]
		inc	[header_pointer]
		and	eax,BLIT_ALL			;Make sure we dont jump to some spurious address
							; if the header is wrong then its better to draw with the wrong
							; shape routine than to die
		shl	eax,2
		add	eax,[ShapeJumpTableAddress]	;get the address to jump to
		jmp	[dword eax]			;do the jump

		endm

