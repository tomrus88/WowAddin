#include "stdafx.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Console::Write("WowAddin v0.1 Alpha Loaded", ECHO_COLOR);
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
	int *textStart = (int*)0x00D415B8;
	int *textEnd = (int*)0x00D415BC;

	*textStart = 0x00000001;
	*textEnd = 0x7FFFFFFF;
}

void InstallGameConsoleCommands()
{
	Console::RegisterCommand("testcmd", Command_TestCommand, CATEGORY_DEBUG, "Test help string");
}

void UninstallGameConsoleCommands()
{
	Console::UnregisterCommand("testcmd");
}
