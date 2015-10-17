#include "StdAfx.h"
#include "user.h"
#include "RRSysNew.h"

cRRSysNew g_RRSysNew;

cRRSysNew::cRRSysNew()
{
	// ----
}
// -------------------------------------------------------------------------------

cRRSysNew::~cRRSysNew()
{
	// ----
}

void cRRSysNew::Load()
{

	int news_intMinute = GetPrivateProfileInt("News", "NewsEveMinute", 30, gDirPath.GetNewPath("Custom\\NewsSys.ini"));

}