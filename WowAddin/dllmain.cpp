#include "stdafx.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Console::Write("WowAddin v0.1 Alpha Loaded", ECHO_COLOR);
		EnableConsole();
		FixInvalidPtrCheck();
		InstallGameConsoleCommands();
		break;
	case DLL_THREAD_ATTACH:
		//Console::Write("DLL_THREAD_ATTACH", CON_COLOR_GRAY);
		break;
	case DLL_THREAD_DETACH:
		//Console::Write("DLL_THREAD_DETACH", CON_COLOR_GRAY);
		break;
	case DLL_PROCESS_DETACH:
		//Console::Write("DLL_PROCESS_DETACH", CON_COLOR_GRAY);
		//UninstallGameConsoleCommands(); // cause client to crash at closing
		break;
	}
	return TRUE;
}

void FixInvalidPtrCheck()
{
	*((int*)0x00D415B8) = 0x00000001;
	*((int*)0x00D415BC) = 0x7FFFFFFF;
}

void EnableConsole()
{
	*((int*)0x00CABCC4) = 1;
}

void InstallGameConsoleCommands()
{
	Console::RegisterCommand("testcmd", Command_TestCommand, CATEGORY_DEBUG, "Test help string");
}

void UninstallGameConsoleCommands()
{
	Console::UnregisterCommand("testcmd");
}
