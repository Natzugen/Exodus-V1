//////////////////////////////////////////////////////////////////////////
// DBManager.cpp: Database Manager implementation like DataServers
// NOTE: This manager, and db things used only for custom created plugins,
// for avoid GS<-->DS communication and use MuOnline DB directly from plugin.
// Author: HappyDay 
// Revision: 0.2.7
//////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "DBManager.h"
#include "DBConBase.h"
#include "GameMain.h"

CDBConBase conBase;

void DBManager::Initialize()
{
	//--Read Configuration--//
	GetPrivateProfileString("Database", "DNS", "MuOnline", this->ConnectDNS, sizeof(this->ConnectDNS), gDirPath.GetNewPath("Custom\\CustomSQL.ini"));
	GetPrivateProfileString("Database", "DBLogin", "sa", this->ConnectLogin, sizeof(this->ConnectLogin), gDirPath.GetNewPath("Custom\\CustomSQL.ini"));
	GetPrivateProfileString("Database", "DBPassword", "pass", this->ConnectPassword, sizeof(this->ConnectPassword), gDirPath.GetNewPath("Custom\\CustomSQL.ini"));
    //--//
	BOOL Conn = conBase.Connect(this->ConnectLogin, this->ConnectPassword);
	if (Conn)
	{
		//Do the other loading things.
	}
}