#include "ccdde.h"

DDEServerClass DDEServer;
BOOL CC95AlreadyRunning = FALSE;

DDEServerClass::DDEServerClass(void) :
	MPlayerGameInfo(NULL),
	MPlayerGameInfoLength(0),
	IsEnabled(FALSE),
	LastHeartbeat(0)
{
}

DDEServerClass::~DDEServerClass(void)
{
	Delete_MPlayer_Game_Info();
}

char *DDEServerClass::Get_MPlayer_Game_Info(void)
{
	return(MPlayerGameInfo);
}

BOOL DDEServerClass::Callback(unsigned char *, long)
{
	return(FALSE);
}

void DDEServerClass::Delete_MPlayer_Game_Info(void)
{
	delete [] MPlayerGameInfo;
	MPlayerGameInfo = NULL;
	MPlayerGameInfoLength = 0;
}

void DDEServerClass::Enable(void)
{
	IsEnabled = TRUE;
}

void DDEServerClass::Disable(void)
{
	IsEnabled = FALSE;
}

int DDEServerClass::Time_Since_Heartbeat(void)
{
	return(0);
}

BOOL Send_Data_To_DDE_Server(char *, int, int)
{
	return(FALSE);
}
