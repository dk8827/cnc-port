;
; Copyright 2025 Electronic Arts Inc.
;
; Derived from Electronic Arts Inc.'s public source release for
; Command & Conquer: Red Alert.
; Licensed under GPLv3-or-later with additional Electronic Arts terms.
; Modified for the macOS port, 2026.
; See LICENSE.md.
;

;*********************************************************************************************** 
;*                                                                                             * 
;*                 Project Name : Westwood 32 bit Library                                      * 
;*                                                                                             * 
;*                    File Name : MOUSE.INC                                                    * 
;*                                                                                             * 
;*                   Programmer : Philip W. Gorrow                                             * 
;*                                                                                             * 
;*                   Start Date : 12/12/95                                                     * 
;*                                                                                             * 
;*                  Last Update : December 12, 1995 [PWG]                                      * 
;*                                                                                             * 
;*---------------------------------------------------------------------------------------------* 
;* Functions:                                                                                  * 
;* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *


STRUC MouseType
MouseCursor		DD		?			; pointer to the mouse cursor in memory
MouseXHot		DD		?			; X hot spot of the current mouse cursor
MouseYHot		DD		?			; Y hot spot of the current mouse cursor
CursorWidth		DD		?			; Width of mouse cursor in pixels
CursorHeight	DD		?			; Height of the mouse cursor in pixels

MouseBuffer		DD		?			; pointer to background buffer in memory
MouseBuffX		DD		?			; pixel x mouse buffer was preserved at
MouseBuffY		DD		?			; pixel y mouse buffer was preserved at
MaxWidth			DD		?			; Maximum possible width of the background buffer
MaxHeight		DD		?			; Maximum possible height of the background buffer

MouseCXLeft		DD		?			; left hand x position if conditional hide mouse in effect
MouseCYUpper	DD		?			; upper y position if conditional hide mouse in effect
MouseCXRight	DD		?			; right hand x position if conditional hide mouse in effect
MouseCYLower	DD		?			; lower y position if conditional hide mouse in effect
MCFlags			DB		?			; conditional hide mouse flags
MCCount			DB		?			; nesting count for conditional hide mouse

Screen			DD		?			; pointer to the surface mouse was init'd with
PrevCursor		DD		?			; pointer to the prev cursor shape
MouseUpdate		DD		?			; is the mouse being currently updated
State				DD		?

EraseBuffer		DD		?
EraseBuffX		DD		?
EraseBuffY		DD		?
EraseBuffHotX	DD		?
EraseBuffHotY	DD		?
EraseFlags		DD		?
ENDS
