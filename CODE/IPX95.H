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

/***************************************************************************
 **   C O N F I D E N T I A L --- W E S T W O O D    S T U D I O S        **
 ***************************************************************************
 *                                                                         *
 *                 Project Name : Command & Conquer                        *
 *                                                                         *
 *                    File Name : IPX95PP                                  *
 *                                                                         *
 *                   Programmer : Steve Tall                               *
 *                                                                         *
 *                   Start Date : January 22nd, 1996                       *
 *                                                                         *
 *                  Last Update : January 22nd, 1996   [ST]                *
 *                                                                         *
 *-------------------------------------------------------------------------*
 *                                                                         *
 *                                                                         *
 *                                                                         *
 *-------------------------------------------------------------------------*
 * Functions:                                                              *
 *                                                                         *
 *                                                                         *
 *                                                                         *
 *                                                                         *
 *                                                                         *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

extern "C"{
	extern BOOL __stdcall IPX_Initialise(void);
	extern BOOL __stdcall IPX_Get_Outstanding_Buffer95(unsigned char *buffer);
	extern void __stdcall IPX_Shut_Down95(void);
	extern int  __stdcall IPX_Send_Packet95(unsigned char *, unsigned char *, int, unsigned char*, unsigned char*);
	extern int  __stdcall IPX_Broadcast_Packet95(unsigned char *, int);
	extern BOOL __stdcall IPX_Start_Listening95(void);
	extern int  __stdcall IPX_Open_Socket95(int socket);
	extern void __stdcall IPX_Close_Socket95(int socket);
	extern int  __stdcall IPX_Get_Connection_Number95(void);
	extern int  __stdcall IPX_Get_Local_Target95(unsigned char *, unsigned char*, unsigned short, unsigned char*);
}
