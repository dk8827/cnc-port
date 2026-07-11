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

#include "function.h"
#include "ipx95.h"

int IPX_Open_Socket(unsigned short socket)
{
	return (IPX_Open_Socket95((int)socket));
}


int IPX_Close_Socket(unsigned short socket)
{
	IPX_Close_Socket95((int)socket);
	return (0);
}


int IPX_Get_Connection_Number(void)
{
	return (IPX_Get_Connection_Number95());
}



int IPX_Broadcast_Packet(unsigned char *buf, int buflen)
{
	return(IPX_Broadcast_Packet95(buf, buflen));
}

extern "C"{
	extern void __cdecl Int3(void);
}

int IPX_Get_Local_Target(unsigned char *dest_network, unsigned char *dest_node,
	unsigned short dest_socket, unsigned char *bridge_address)
{
	//Int3();
	return (IPX_Get_Local_Target95(dest_network, dest_node, dest_socket, bridge_address));
}


