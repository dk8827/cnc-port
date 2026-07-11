/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef INTERNET_H
#define INTERNET_H

#define IP_ADDRESS_MAX 40


void	Register_Game_Start_Time(void);
void	Register_Game_End_Time(void);
void	Send_Statistics_Packet(void);
void 	Check_From_WChat(char *wchat_name);
bool 	Do_The_Internet_Menu_Thang (void);
bool 	Server_Remote_Connect(void);
bool 	Client_Remote_Connect(void);
int 	Read_Game_Options(char *name);

extern char PlanetWestwoodIPAddress[IP_ADDRESS_MAX];
extern long PlanetWestwoodPortNumber;
extern bool PlanetWestwoodIsHost;

#endif
