/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef WSPIPX_H
#define WSPIPX_H

#include	"WSProto.h"

/*
** Include Windows specific extensions for Winsock that allow IPX over winsock 1.1
*/
#include	<wsipx.h>

/*
** This file normally resides with the SDK. However, since it needs fixing up before watcom will
** compile it, it has been incorporated into the project.
*/
#include	"wsnwlink.h"

/*
** IPX interface class. This handles access to the IPX specific portions of the
** Winsock interface.
**
*/
class IPXInterfaceClass : public WinsockInterfaceClass {

	public:

		IPXInterfaceClass (void);
		//virtual ~IPXInterfaceClass(void){Close();};
		bool Get_Network_Card_Address (int card_number, SOCKADDR_IPX *addr);
	 	virtual long Message_Handler(HWND window, UINT message, UINT wParam, LONG lParam);
		virtual bool Open_Socket ( SOCKET socketnum );

		virtual ProtocolEnum Get_Protocol (void) {
			return (PROTOCOL_IPX);
		};

		virtual int Protocol_Event_Message (void) {
			return (WM_IPXASYNCEVENT);
		};


	private:
		/*
		** The address of the network we will send broadcasts to. Normally you would expect
		** this to be ff,ff,ff,ff but this fails under NT 4.0. Instead, we can use the network
		** number of the net that this PC is attached to. This limits broadcasts to the current
		** network.
		*/
		unsigned char	BroadcastNet[4];

		/*
		** The node to use as a broadcast address. Normally ff,ff,ff,ff,ff,ff.
		*/
		unsigned char	BroadcastNode[6];

		/*
		** The id of the network cars in this machine.
		*/
		unsigned char	MyNode[6];

		/*
		** The socket number to connect with. Normally this will be virgins reserved socket
		** number - VIRGIN_SOCKET (0x8813).
		*/
		SOCKET			IPXSocketNumber;

};



#endif