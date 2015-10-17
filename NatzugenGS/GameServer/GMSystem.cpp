#include "StdAfx.h"
#include "GMSystem.h"
#include "GameMain.h"
#include "user.h"
#include "logproc.h"
#include "BuffEffectSlot.h"
#include "LogToFile.h"

#include "gObjMonster.h"
#include "ObjCalCharacter.h"
#include "ObjUseSkill.h"
#include "DSProtocol.h"
#include "protocol.h"

cGMSystem g_GMSystem;

cGMSystem::cGMSystem()
{
	// ----
}
// -------------------------------------------------------------------------------

cGMSystem::~cGMSystem()
{
	// ----
}

void cGMSystem::Load(LPBYTE lpdata, int aIndex)
{


	SDHP_DBCHAR_INFORESULT * lpMsg = (SDHP_DBCHAR_INFORESULT *)lpdata;
	LPOBJ lpObj = &gObj[aIndex];

	int gmcodenum = GetPrivateProfileInt("GameMasters", "GMsCode", 16, gDirPath.GetNewPath("Custom\\GMSystem.ini"));

	if (lpMsg->CtlCode == 8) 
	{
		lpObj->Authority = 8;
	}

	AllSendServerMsg(lpObj->Name); // GM is Online Text
	AllSendServerMsg("Is Online");

	LogAddC(2, "[GMSystem] (%s)(%s) Set Event GM", lpObj->AccountID, lpObj->Name);
		
		gObjAddBuffEffect(lpObj, 28, 1, 0, 0, 0, 20000);
}