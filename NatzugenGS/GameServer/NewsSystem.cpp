#include "StdAfx.h"
#include "NewsSystem.h"
#include "GameMain.h"
#include "user.h"
#include "logproc.h"
#include "LogToFile.h"

cNewsSystem g_NewsSystem;

cNewsSystem::cNewsSystem()
{
	// ----
}
// -------------------------------------------------------------------------------

cNewsSystem::~cNewsSystem()
{
	// ----
}

void cNewsSystem::Load()
{

	int news_intMinute = GetPrivateProfileInt("News", "NewsEveMinute", 30, gDirPath.GetNewPath("Custom\\NewsSys.ini"));

	SYSTEMTIME t;
	GetLocalTime(&t);
	if (t.wMinute == news_intMinute && t.wSecond == 00)
	{

		int randNumber = rand() % 5 + 1;

		if (randNumber == 1) {
			char news1Texta[255];
			char news1Textb[255];
			char news1Textc[255];
			GetPrivateProfileString("News", "News1Texta", "zGameServer", news1Texta, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			GetPrivateProfileString("News", "News1Textb", "zGameServer", news1Textb, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			GetPrivateProfileString("News", "News1Textc", "zGameServer", news1Textc, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			AllSendServerMsg(news1Texta);
			AllSendServerMsg(news1Textb);
			AllSendServerMsg(news1Textc);
			LogAddTD("[NewsSystem] %s ", news1Texta);
			LogAddTD("[NewsSystem] %s ", news1Textb);
			LogAddTD("[NewsSystem] %s ", news1Textc);
		}

		else if (randNumber == 2) {
			char news2Texta[255];
			char news2Textb[255];
			char news2Textc[255];
			GetPrivateProfileString("News", "News2Texta", "zGameServer", news2Texta, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			GetPrivateProfileString("News", "News2Textb", "zGameServer", news2Textb, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			GetPrivateProfileString("News", "News2Textc", "zGameServer", news2Textc, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			AllSendServerMsg(news2Texta);
			AllSendServerMsg(news2Textb);
			AllSendServerMsg(news2Textc);
			LogAddTD("[NewsSystem] %s ", news2Texta);
			LogAddTD("[NewsSystem] %s ", news2Textb);
			LogAddTD("[NewsSystem] %s ", news2Textc);
		}

		else if (randNumber == 3) {
			char news3Texta[255];
			char news3Textb[255];
			char news3Textc[255];
			GetPrivateProfileString("News", "News3Texta", "zGameServer", news3Texta, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			GetPrivateProfileString("News", "News3Textb", "zGameServer", news3Textb, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			GetPrivateProfileString("News", "News3Textc", "zGameServer", news3Textc, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			AllSendServerMsg(news3Texta);
			AllSendServerMsg(news3Textb);
			AllSendServerMsg(news3Textc);
			LogAddTD("[NewsSystem] %s ", news3Texta);
			LogAddTD("[NewsSystem] %s ", news3Textb);
			LogAddTD("[NewsSystem] %s ", news3Textc);
		}

		else if (randNumber == 4) {
			char news4Texta[255];
			char news4Textb[255];
			char news4Textc[255];
			GetPrivateProfileString("News", "News4Texta", "zGameServer", news4Texta, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			GetPrivateProfileString("News", "News4Textb", "zGameServer", news4Textb, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			GetPrivateProfileString("News", "News4Textc", "zGameServer", news4Textc, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			AllSendServerMsg(news4Texta);
			AllSendServerMsg(news4Textb);
			AllSendServerMsg(news4Textc);
			LogAddTD("[NewsSystem] %s ", news4Texta);
			LogAddTD("[NewsSystem] %s ", news4Textb);
			LogAddTD("[NewsSystem] %s ", news4Textc);
		}

		else if (randNumber == 5) {
			char news5Texta[255];
			char news5Textb[255];
			char news5Textc[255];
			GetPrivateProfileString("News", "News5Texta", "zGameServer", news5Texta, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			GetPrivateProfileString("News", "News5Textb", "zGameServer", news5Textb, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			GetPrivateProfileString("News", "News5Textc", "zGameServer", news5Textc, 255, gDirPath.GetNewPath("Custom\\NewsSys.ini"));
			AllSendServerMsg(news5Texta);
			AllSendServerMsg(news5Textb);
			AllSendServerMsg(news5Textc);
			LogAddTD("[NewsSystem] %s ", news5Texta);
			LogAddTD("[NewsSystem] %s ", news5Textb);
			LogAddTD("[NewsSystem] %s ", news5Textc);
		}

	}
}