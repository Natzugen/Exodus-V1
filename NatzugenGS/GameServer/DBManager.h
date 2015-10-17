//////////////////////////////////////////////////////////////////////////
// DBManager.cpp: Database Manager implementation like DataServers
// NOTE: This manager, and db things used only for custom created plugins,
// for avoid GS<-->DS communication and use MuOnline DB directly from plugin.
// Author: HappyDay 
// Revision: 0.2.7
//////////////////////////////////////////////////////////////////////////
#pragma once

class DBManager
{
public:
	//-------------------//
	char	ConnectDNS[52];
	char	ConnectLogin[52];
	char	ConnectPassword[52];
	//-------------------//
	void Initialize();

}; extern DBManager gsDB;