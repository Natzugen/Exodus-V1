/**
* The MuOnline Server Season6 Episode3- a free and open-source server emulator
* Copyright (C) 2015  HappyDay from R@geZone
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#include "StdAfx.h"
#include "..\common\winutil.h"
#include "..\include\readscript.h"
#include "user.h"
#include "OnlineBoard.h"

OnlineBoard g_OnlineBoard;
//---------//
OnlineBoard::OnlineBoard()
{
	this->Init();
}
OnlineBoard::~OnlineBoard()
{

}
//---------//
void OnlineBoard::Init()
{
}

void OnlineBoard::Load()
{

}


void OnlineBoard::RequestOnline(LPOBJ lpUser, ONLINE_REQ_DATA * Request)
{
	if (lpUser->Connected != PLAYER_PLAYING)
	{
		return;
	}
	// ----
	ONLINE_DATA pAnswer = { 0 };
	PHeadSetW((LPBYTE)&pAnswer, 0xFF, sizeof(ONLINE_DATA));
	for (int i = 0; i < 1000; i++)
	{
		pAnswer.m_data[i] = this->m_data[i];
	}
	DataSend(lpUser->m_Index, (LPBYTE)&pAnswer, sizeof(ONLINE_DATA));

}
