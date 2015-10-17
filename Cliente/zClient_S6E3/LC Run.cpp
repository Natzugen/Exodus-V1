#include "stdafx.h"
#include "LC Run.h"
#include <cstdlib>

lcrunname g_lcrunname;

lcrunname::lcrunname()
{

}
// -------------------------------------------------------------------------------

lcrunname::~lcrunname()
{

}

void lcrunname::isRunning()
{
	/*
	if (system("tasklist /fi \"imagename eq UpdateSystem.exe\" | find /i \"UpdateSystem.exe\"") > NULL) 
	{
		WinExec("taskkill /f /im ExedonMu.exe", SW_HIDE);
		WinExec("cmd.exe /c start UpdateSystem.exe", SW_HIDE);
	}
	else 
	{
		//Checked prog is working.
	}
	*/
}