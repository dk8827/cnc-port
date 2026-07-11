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

/* $Header:   F:\projects\c&c\vcs\code\phone.h_v   1.9   16 Oct 1995 16:47:58   JOE_BOSTIC  $ */
/*************************************************************************** 
 *                                                                         * 
 *                 Project Name : Command & Conquer                        * 
 *                                                                         * 
 *                    File Name : PHONE.H                                  * 
 *                                                                         * 
 *                   Programmer : Bill R. Randolph                         * 
 *                                                                         * 
 *                   Start Date : 04/28/95                                 * 
 *                                                                         * 
 *                  Last Update : April 28, 1995 [BRR]                     * 
 *                                                                         * 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef PHONE_H
#define PHONE_H

/*
***************************** Class Declaration *****************************
*/
class PhoneEntryClass
{
	public:
		enum PhoneEntryEnum {
			PHONE_MAX_NAME = 21,
			PHONE_MAX_NUM = 21
		};

		PhoneEntryClass(void) {};
		~PhoneEntryClass() {};

		int operator == (PhoneEntryClass &obj) 
			{ return (memcmp (Name,obj.Name,strlen(Name))==0);}
		int operator != (PhoneEntryClass &obj)
			{ return (memcmp (Name,obj.Name,strlen(Name))!=0);}
		int operator > (PhoneEntryClass &obj)
			{ return (memcmp(Name, obj.Name, strlen(Name)) > 0);}
		int operator < (PhoneEntryClass &obj)
			{ return (memcmp(Name, obj.Name, strlen(Name)) < 0);}
		int operator >= (PhoneEntryClass &obj)
			{ return (memcmp(Name, obj.Name, strlen(Name)) >= 0);}
		int operator <= (PhoneEntryClass &obj)
			{ return (memcmp(Name, obj.Name, strlen(Name)) <= 0);}

		SerialSettingsType Settings;
		char Name[ PHONE_MAX_NAME ];		// destination person's name
		char Number[ PHONE_MAX_NUM ];		// phone #
};

#endif
