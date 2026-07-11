/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

/*************************************************************************** 
 *                                                                         * 
 *                 Project Name : Command & Conquer                        * 
 *                                                                         * 
 *                    File Name : TENMGR.H                                 * 
 *                                                                         * 
 *                   Programmer : Bill R. Randolph                         * 
 *                                                                         * 
 *                   Start Date : 06/26/96                                 * 
 *                                                                         * 
 *                  Last Update : June 26, 1996 [BRR]                      * 
 *                                                                         * 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class TenConnManClass : public ConnManClass
{
	public:
		//
		// Constructor / Destructor
		//
		TenConnManClass(void);
		virtual ~TenConnManClass();

		//
		// Initialization
		//
	   int Init(void);

		//
		// Service routine
		//
		virtual int Service(void);

		//
		// Sending & receiving data
		//
		virtual int Send_Private_Message (void *buf, int buflen, 
			int ack_req = 1, int conn_id = CONNECTION_NONE);
		virtual int Get_Private_Message (void *buf, int *buflen, 
			int *conn_id);

	   int Send_Global_Message(void *buf, int buflen, 
	   	int ack_req = 0, int address = 0);
	   int Get_Global_Message(void *buf, int *buflen, 
	   	int *address = 0);

		//
		// Connection management
		//
		virtual int Num_Connections(void);
		virtual int Connection_ID(int index);
		virtual int Connection_Index(int id);

	   int Create_Connection(int id, char *name, int address);
	   int Delete_Connection(int id);
	   char *Connection_Name(int id);
	   int Connection_Address(int id);

		//
		// Queue utility routines
		//
		virtual int Global_Num_Send(void);
		virtual int Global_Num_Receive(void);
		virtual int Private_Num_Send(int id = CONNECTION_NONE);
		virtual int Private_Num_Receive(int id = CONNECTION_NONE);

		void Flush_All(void);

		//
		// Timing management
		//
		virtual void Reset_Response_Time(void);
		virtual unsigned long Response_Time(void);
		virtual void Set_Timing (unsigned long retrydelta, 
			unsigned long maxretries, unsigned long timeout);

		//
		// Debugging
		//
		virtual void Configure_Debug(int index, int type_offset, int type_size, 
			char **names, int namestart, int namecount);
		virtual void Mono_Debug_Print(int index, int refresh);

		CommBufferClass *GlobalQueue;
		CommBufferClass *PrivateQueue;

		//
		// This flag will be set if I'm the game host.
		//
		int IsHost;

	private:
	   int Connections[MAX_PLAYERS];
		int ID[MAX_PLAYERS];
	   char Names[MAX_PLAYERS][128];
	   int NumConnections;

};

/***************************** end of tenmgr.h *****************************/
