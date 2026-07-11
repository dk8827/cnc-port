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


;!!!!!!!!!!!!!!!!!!! lock the allocation

;***************************************************************************
;**   C O N F I D E N T I A L --- W E S T W O O D    S T U D I O S        **
;***************************************************************************
;*                                                                         *
;*                 Project Name : VQLIB                                    *
;*                                                                         *
;*                    File Name : HANDLER.ASM                              *
;*                                                                         *
;*                   Programmer : Bill Randolph                            *
;*                                                                         *
;*                   Start Date : April 7, 1995                            *
;*                                                                         *
;*                  Last Update : April 7, 1995   [BRR]                    *
;*                                                                         *
;*-------------------------------------------------------------------------*
;* Functions:                                                              *
;*   IPXHandler -- callback routine for IPX                                *
;* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *
;********************* Model & Processor Directives ************************
IDEAL
P386
MODEL USE32 FLAT
LOCALS ??


;******************************** Includes *********************************


;******************************** Defines ***********************************


;****************************** Declarations ********************************
global C	 Get_RM_IPX_Address:NEAR
global C	 Get_RM_IPX_Size:NEAR

;********************************* Data ************************************
	DATASEG

LABEL 	RealBinStart	BYTE
include "obj\ipxreal.ibn"
LABEL	RealBinEnd	BYTE

;********************************* Data ************************************
	CODESEG

;***************************************************************************
;* Get_RM_IPX_Address -- Return address of real mode code for copy.        *
;*                                                                         *
;* INPUT:								   *
;*	none                                                               *
;*                                                                         *
;* OUTPUT:      							   *
;*	VOID * to the address of the real mode IPX code			   *
;*                                                                         *
;* PROTO:								   *
;*	VOID	*Get_RM_IPX_Address(VOID);			           *
;*                                                                         *
;* HISTORY:                                                                *
;*   07/06/1994 SKB : Created.                                             *
;*=========================================================================*
	PROC	Get_RM_IPX_Address C Near

	mov	eax, OFFSET RealBinStart
	ret

	ENDP

;***************************************************************************
;* Get_RM_IPX_Size -- return size of real mode IPX code.                   *
;*                                                                         *
;* INPUT:					   			   *
;*	none                                                               *
;*                                                                         *
;* OUTPUT:      				   			   *
;*	LONG size of the real mode IPX code                                *
;*                                                                         *
;* PROTO:					   			   *
;*	LONG	Get_RM_IPX_Size(VOID);				   	   *
;*                                                                         *
;* HISTORY:                                                                *
;*   07/06/1994 SKB : Created.                                             *
;*=========================================================================*
	PROC	Get_RM_IPX_Size C Near

	mov	eax, OFFSET RealBinEnd - OFFSET RealBinStart
	ret

	ENDP

	END

;************************** End of handler.asm *****************************
