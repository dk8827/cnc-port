/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef mpmgr_h
#define mpmgr_h

#include "connmgr.h"

// maximum number of connections
#define CONNECT_MAX    7
#define MAX_NAME_LEN   128

class MPlayerManClass : public ConnManClass {
public:
   MPlayerManClass(void);

   // queues up incoming packets appropriately
   int   Service(void);

   // initialization
   int   Init(void);
	int Find_Num_Connections(void);
	void Flush_All(void);

   // send/receive data
   int  Send_Private_Message(void *buf, int buflen, int ack_req = 1, int conn_id = CONNECTION_NONE);
   int  Get_Private_Message(void *buf, int *buflen, int *conn_id);

   int  Send_Global_Message(void *buf, int buflen, int ack_req = 0, int address = 0);
   int  Get_Global_Message(void *buf, int *buflen, int *address = 0);

   // manage connections
   int  Num_Connections(void);
   int  Connection_ID(int index);
   int  Connection_Index(int id);
   int  Create_Connection(int id, char *name, int address);
   int  Delete_Connection(int id);
   char *Connection_Name(int id);
   int  Connection_Address(int id);

   // queueing routines

   int Global_Num_Send(void);
   int Global_Num_Receive(void);
   int Private_Num_Send(int id = CONNECTION_NONE);
   int Private_Num_Receive(int id = CONNECTION_NONE);

   // timing magnagement
   void Reset_Response_Time(void);
   unsigned long Response_Time(void);
   void Set_Timing(unsigned long retrydelta, unsigned long maxretries, unsigned long timeout);

   // debug
   void Configure_Debug(int index, int type_offset, int type_size, char **names, int namestart,
      int namecount);
   void Mono_Debug_Print(int index, int refresh);

private:
   int  _myAddr;
   int  _Connections[CONNECT_MAX];
	int  _ID[CONNECT_MAX];
   char _Names[CONNECT_MAX][MAX_NAME_LEN];
   int  _nConnections;
};

#endif // mpmgr_h

