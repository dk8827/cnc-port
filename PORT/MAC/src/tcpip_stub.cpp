#include <string.h>

#include <windows.h>
#include "tcpip.h"

TcpipManagerClass Winsock;

TcpipManagerClass::TcpipManagerClass(void)
{
	WinsockInitialised = FALSE;
	Connected = FALSE;
	IsServer = FALSE;
	UseUDP = FALSE;
	ConnectStatus = NOT_CONNECTING;
	HostAddress[0] = 0;
	TXBufferHead = TXBufferTail = 0;
	RXBufferHead = RXBufferTail = 0;
	SocketReceiveBuffer = 0;
	SocketSendBuffer = 0;
}

TcpipManagerClass::~TcpipManagerClass(void)
{
	Close();
}

BOOL TcpipManagerClass::Init(void)
{
	WinsockInitialised = FALSE;
	Connected = FALSE;
	ConnectStatus = NOT_CONNECTING;
	return(FALSE);
}

void TcpipManagerClass::Start_Server(void)
{
	IsServer = TRUE;
	Connected = FALSE;
	ConnectStatus = UNABLE_TO_ACCEPT_CLIENT;
}

void TcpipManagerClass::Start_Client(void)
{
	IsServer = FALSE;
	Connected = FALSE;
	ConnectStatus = UNABLE_TO_CONNECT;
}

void TcpipManagerClass::Close_Socket(SOCKET)
{
}

void TcpipManagerClass::Message_Handler(HWND, UINT, UINT, LONG)
{
}

void TcpipManagerClass::Copy_To_In_Buffer(int)
{
}

int TcpipManagerClass::Read(void *, int)
{
	return(0);
}

void TcpipManagerClass::Write(void *, int)
{
}

BOOL TcpipManagerClass::Add_Client(void)
{
	return(FALSE);
}

void TcpipManagerClass::Close(void)
{
	WinsockInitialised = FALSE;
	Connected = FALSE;
	ConnectStatus = NOT_CONNECTING;
}

void TcpipManagerClass::Set_Host_Address(char *address)
{
	if (address) {
		strncpy(HostAddress, address, IP_ADDRESS_MAX - 1);
		HostAddress[IP_ADDRESS_MAX - 1] = 0;
	} else {
		HostAddress[0] = 0;
	}
}

void TcpipManagerClass::Set_Protocol_UDP(BOOL state)
{
	UseUDP = state;
}

void TcpipManagerClass::Clear_Socket_Error(SOCKET)
{
}
