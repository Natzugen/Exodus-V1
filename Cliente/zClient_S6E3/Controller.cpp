#include "stdafx.h"
#include "Controller.h"
#include "Import.h"
#include "Interface.h"
#include "Camera.h"
#include "ChatExpanded.h"
#include "NewsBoard.h"
#include "TrayMode.h"
#include "TDebugLog.h"
#include "User.h"
// ----------------------------------------------------------------------------------------------

Controller	gController;
// ----------------------------------------------------------------------------------------------

bool Controller::Load()
{
	if( !this->MouseHook )
	{
		this->MouseHook = SetWindowsHookEx(WH_MOUSE, this->Mouse, gController.Instance, GetCurrentThreadId());
		// ----
		if( !this->MouseHook )
		{
			return false;
		}
	}
	// ----
	if( !this->KeyboardHook )
	{
		this->KeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, this->Keyboard, gController.Instance, NULL);
		// ----
		if( !this->KeyboardHook )
		{
			return false;
		}
	}
	// ----
	return true;
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Mouse(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
	}
	// ----
	MOUSEHOOKSTRUCTEX * Mouse	= (MOUSEHOOKSTRUCTEX*)lParam;
	// ----
	gCamera.Run(Mouse, wParam);
	// ----
	switch(wParam)
	{
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN:
		{
			gInterface.EventCraftWindow_Main(wParam);
			gInterface.EventCameraUI(wParam);
			gInterface.EventResetWindow_Main(wParam);
			gInterface.EventNewsWindow_Main(wParam);
			gInterface.EventOffExpSwitch(wParam);
		}
		break;
	}
	// ----
	return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Keyboard(int Code, WPARAM wParam, LPARAM lParam)
{
	if( (Code == HC_ACTION) && (wParam == WM_KEYDOWN))
	{
		KBDLLHOOKSTRUCT Hook = *((KBDLLHOOKSTRUCT*)lParam);
		// ----
		switch(Hook.vkCode)
		{
#ifdef __ROOT__
		case VK_F4:
			{
				if( GetForegroundWindow() == pGameWindow )
				{
					if( gInterface.CheckQuestDialog() )
					{
						gInterface.CloseQuestDialog();
					}
					else
					{
						gInterface.OpenQuestDialog();
					}
				}
			}
			break;
#endif
			case VK_F4:
			{
				if( GetForegroundWindow() == pGameWindow )
				{
					if (gObjUser.showHPBar)
					{
						gObjUser.showHPBar = false;
						gInterface.DrawMessage(1, "Lifebars disabled");
					}
					else
					{
						gInterface.DrawMessage(1, "Lifebars enabled");
						gObjUser.showHPBar = true;
					}
				}
			}
			break;
		case VK_F6:
			{
				if( GetForegroundWindow() == pGameWindow )
				{
					gChatExpanded.Switch();
				}
			}
			break;
			// --
		case VK_F7:
			{
				if( GetForegroundWindow() == pGameWindow )
				{
					if( gInterface.CheckNewsWindow() )
					{
						gInterface.CloseNewsWindow();
					}
					else
					{
						gNewsBoard.ReqOpenMain();
					}
				}
			}
			break;
		case VK_F8:
		{
			gInterface.DrawMessage(1, "Tron Glow Settings");
		}
		break;
			// --
		case VK_F12:
			{
				if( gTrayMode.TempWindowProc == NULL )
				{
					gTrayMode.TempWindowProc = SetWindowLong(pGameWindow, GWL_WNDPROC, (long)gController.Window);
				}
				// ----
				gTrayMode.SwitchState();
			}
			break;
			// --
		case VK_END:
			{
				//gInterface.SwitchTime();
			}
			break;
		}
	} 
	return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Window(HWND Window, DWORD Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{
	case TRAYMODE_ICON_MESSAGE:
		{
			switch(lParam)
			{
			case WM_LBUTTONDBLCLK:
				{
					gTrayMode.SwitchState();
				}
				break;
			}
		}
		break;
	}
	// ----
	return CallWindowProc((WNDPROC)gTrayMode.TempWindowProc, Window, Message, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------
