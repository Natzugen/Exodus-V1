///HappyDay Simple Protect System.
///Public ver.
#include "stdafx.h"
#include "Anti.h"

inline int AddSubOne(int One, int Two)
{
	JUNK_CODE_ONE
		return ((One + Two) - 1);
}
inline void PushPopSS()
{
	__asm
	{
		push ss
			pop ss
			mov eax, 9
			xor edx, edx
	}
}

void Protector::AntiDebug()
{
	unsigned long NtGlobalFlags = 0;
	char IsDbgPresent = 0;

	__asm {
		mov eax, fs:[30h]
			mov al, [eax + 2h]
			mov IsDbgPresent, al
	}

	__asm {
		mov eax, fs:[30h]
			mov eax, [eax + 68h]
			mov NtGlobalFlags, eax
	}
	PushPopSS();
	if (IsDbgPresent == 1)
	{
		//MessageBox(NULL, "Please close your debugging application and restart the program", "Debugger Found!", 0);
		ExitProcess(0);
	}
	typedef unsigned long(__stdcall *pfnNtQueryInformationProcess)(IN  HANDLE,
		IN  unsigned int, OUT PVOID, IN ULONG, OUT PULONG);


	// ProcessDebugPort
	const int ProcessDbgPort = 7;

	// We have to import the function
	pfnNtQueryInformationProcess NtQueryInfoProcess = NULL;

	// Other Vars
	unsigned long Ret;
	unsigned long IsRemotePresent = 0;

	HMODULE hNtDll = LoadLibrary(TEXT("ntdll.dll"));
	if (hNtDll == NULL)
	{
		// Handle however.. chances of this failing
		// is essentially 0 however since
		// ntdll.dll is a vital system resource
	}

	NtQueryInfoProcess = (pfnNtQueryInformationProcess)
		GetProcAddress(hNtDll, "NtQueryInformationProcess");
	if (NtQueryInfoProcess == NULL)
	{
		//obfuscation part
		PushPopSS();
		auto increment = AddSubOne(567, 234);
		if (increment == 567)
		{
			PushPopSS();
		}
		// Handle however it fits your needs but as before,
		// if this is missing there are some SERIOUS issues with the OS
	}

	// Time to finally make the call
	Ret = NtQueryInfoProcess(GetCurrentProcess(), ProcessDbgPort,
		&IsRemotePresent, sizeof(unsigned long), NULL);
	if (Ret == 0x00000000 && IsRemotePresent != 0)
	{
		// Debugger is present
		//MessageBox(NULL, "Please close your debugging application and restart the program", "Debugger Found!", 0);
		ExitProcess(0);
	}

	if (NtGlobalFlags & 0x70)
		// 0x70 =  FLG_HEAP_ENABLE_TAIL_CHECK |
		//         FLG_HEAP_ENABLE_FREE_CHECK | 
		//         FLG_HEAP_VALIDATE_PARAMETERS
	{
		// Debugger is present
		//MessageBox(NULL, "Please close your debugging application and restart the program", "Debugger Found!", 0);
		ExitProcess(0);
	}
	PushPopSS();
	auto increment = AddSubOne(2334, 67);
	if (increment == 344)
	{
		PushPopSS();
	}
	Sleep(10000);
}