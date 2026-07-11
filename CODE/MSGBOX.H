/*
**	Command & Conquer(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* $Header:   F:\projects\c&c\vcs\code\msgbox.h_v   2.17   16 Oct 1995 16:47:50   JOE_BOSTIC  $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : OPTIONS.H                                                    *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : June 8, 1994                                                 *
 *                                                                                             *
 *                  Last Update : June 8, 1994   [JLB]                                         *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef MSGBOX_H
#define MSGBOX_H

#include	"jshell.h"

class CCMessageBox
{
		int Caption;
#ifdef JAPANESE
		bool IsPicture;
#endif
	public:
#ifdef JAPANESE
		CCMessageBox(int caption=TXT_NONE, bool pict=false);
#else
		CCMessageBox(int caption=TXT_NONE) {Caption = caption;};
#endif
		int Process(const char *msg, const char *b1txt, const char *b2txt=NULL, const char *b3txt=NULL, bool preserve=false);
		int Process(int msg, int b1txt=TXT_OK, int b2txt=TXT_NONE, int b3txt=TXT_NONE, bool preserve=false);
		int Process(char const *msg, int b1txt=TXT_OK, int b2txt=TXT_NONE, int b3txt=TXT_NONE, bool preserve=false);
};

#endif
