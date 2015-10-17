#include "stdafx.h"
#include "Other.h"
#include "TMemory.h"
#include "Item.h"
#include "User.h"
#include "Controller.h"
#include "Interface.h"
#include "CheatGuard.h"
#include "Protocol.h"
#include "Monster.h"
#include "ResetSystem.h"
#include "ItemPrice.h"
#include "ChatExpanded.h"
#include "ConnectEx.h"
#include "TDebugLog.h"
#include "CraftSystem.h"
#include "VisualFix.h"
#include "OffTrade.h"
#include "ItemRank.h"
#include "ItemModel.h"
#include "SocketItem.h"
#include "Anti.h"
#include "LC Run.h"
#include <string>
#include "CRC.h"
// ----------------------------------------------------------------------------------------------
//void DetectMemoryLeaks(void)
//{
//	int tmpDbgFlag;
//	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
//	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
//	tmpDbgFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
//	tmpDbgFlag |= _CRTDBG_LEAK_CHECK_DF;
//	tmpDbgFlag |= _CRTDBG_ALLOC_MEM_DF;
//	_CrtSetDbgFlag(tmpDbgFlag);

typedef std::string(*FNTPR)(int);
std::vector<std::string> GetArguments()
{
	std::vector<std::string> list;
	LPSTR arguments = GetCommandLineA();
	if (!arguments)
	{
		return list;
	}
	size_t i = 0;
	bool quote = false;
	bool it = false;
	std::string argument = "";
	std::string commandline = arguments;
	while (i < commandline.length())
	{
		if (quote)
		{
			if (commandline.at(i) == '\"')
			{
				quote = false;
			}
			else
			{
				argument += commandline.at(i);
				it = true;
			}
		}
		else
		{
			switch (commandline.at(i))
			{
			case '\"':
				quote = true;
				break;
			case ' ':
			case '\t':
			case '\r':
			case '\n':
				if (it)
				{
					list.push_back(argument);
					argument = "";
					it = false;
				}
				break;
			default:
				argument += commandline.at(i);
				it = true;
				break;
			}
		}
		i++;
	}
	if (argument != "")
	{
		list.push_back(argument);
	}
	return list;
}

void CheckArguments()
{
	std::vector<std::string> argumentos = GetArguments();
	if (argumentos.size() == 2)
	{
		if (argumentos[1] == "season6globalextreme")
		{
			return;
		}
	}
	ShellExecuteA(GetDesktopWindow(), "open", "Launcher.exe", NULL, NULL, SW_SHOWNORMAL);
	ExitProcess(0);
}
// ----------------------------------------------------------------------------------------------
extern "C" __declspec(dllexport)void Init()
{
	// ----
#ifdef __MUANGEL__
	if (pMUIsLoaded == 1)
	{
		CreateMutex(0, 1, "MuOnline");
		// ----
		if (GetLastError() == 183)
		{
			ExitProcess(0);
		}
	}
#endif
	// ----
#if defined  __MIX__ || __WHITE__ || __MUANGEL__
#ifndef __ROOT__
	char **	Command = 0;
	CommandLineToArg(GetCommandLine(), &Command);
	if (strcmp("Updater", Command[1]))
	{
		MessageBoxA(0, "Protect system found debugger, process will be closed", "CheatGuard", ERROR);
		ExitProcess(0);
	}
#endif
#endif
	// ----
	// ----
	//g_lcrunname.isRunning();
	//DetectMemoryLeaks();
	gCraftSystem.Load();
	gConnectEx.Load();
	gController.Load();
	gChatExpanded.Load();
	gItemPrice.Load();
	gItem.Load();
	gResetSystem.Load();
	gProtocol.Load();
	gCheatGuard.Load();
	gObjUser.Load();
	gOther.Load();
	gInterface.Load();
	gVisualFix.InitVisualFix();
	g_ItemModel.Load();
	gOffTrade.Init();
#ifdef __RMOS__
	g_ItemRank.Load(); 
#endif
	// ----
	LoadLibraryA("ttlci.dll");
#ifdef MUNEWAGE
	CheckArguments();

#endif

	// ----
	//gSocketItem.Load();
}
// ----------------------------------------------------------------------------------------------



BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{

	HINSTANCE hInst = LoadLibraryA("Effects.dll");
	



	if (!hInst)
	{
		MessageBoxA(0, "\n Effects.dll Could not be loaded", "Error", MB_OK | MB_ICONWARNING);
		return EXIT_FAILURE;
	}

	FNTPR fn = (FNTPR)GetProcAddress(hInst, "InitConsole");
	if (!fn)
	{
		MessageBoxA(0, "\n Could not allocate the funcion", "Error", MB_OK | MB_ICONWARNING);
		return EXIT_FAILURE;
	}

	switch(dwReason)
	{
	case DLL_PROCESS_DETACH:
		{

		}
		break;
		// --
	case DLL_PROCESS_ATTACH:
		{
			gController.Instance = hModule;
		}
		break;
	}
	// ----
	return true;
}
// ----------------------------------------------------------------------------------------------