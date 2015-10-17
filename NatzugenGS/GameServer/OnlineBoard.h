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

#define ONLINEUSR_MAX   1000
//-------------------------------
#pragma pack(push, 1)
struct ONLINE_USER
{
	char	UserName[80];
	int		Level;
	int		GrandReset;
	int		Reset;
	int     PClass;

	short	Strength;
	short	Dexterity;
	short	Vitality;
	short	Energy;
	short	Leadership;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct ONLINE_DATA
{
	PWMSG_HEAD h;
	ONLINE_USER m_data[ONLINEUSR_MAX];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct ONLINE_REQ_DATA
{
	PBMSG_HEAD2	h;
};
#pragma pack(pop)
//-------------------------------

class OnlineBoard
{
public:
	OnlineBoard();
	~OnlineBoard();
	// ----
	void	Init();
	void	Load();
	void    Update();
	//---//
	void	RequestOnline(LPOBJ lpUser, ONLINE_REQ_DATA * Request);
	// ----
	ONLINE_USER m_data[ONLINEUSR_MAX];
	//-----
}; extern OnlineBoard g_OnlineBoard;