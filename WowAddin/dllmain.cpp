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
        SetMessageHandlers();
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

// Fix InvalidPtrCheck for callbacks outside of .text section
void FixInvalidPtrCheck()
{
    *((int*)0x00D415B8) = 0x00000001;
    *((int*)0x00D415BC) = 0x7FFFFFFF;
}

// Enable console without using -console command line argument
void EnableConsole()
{
    *((int*)0x00CABCC4) = 1;
}

void InstallGameConsoleCommands()
{
    Console::RegisterCommand("testcmd", CCommand_TestCommand, CATEGORY_DEBUG, "Test help string");
    Console::RegisterCommand("beastmaster", CCommand_Beastmaster, CATEGORY_DEBUG, "Beastmaster mode");
    Console::RegisterCommand("db", CCommand_DBLookup, CATEGORY_DEBUG, "TableName (Name or #ID) Note:Wildcard use * in TableName or Name not ID though");

    InstallGMCommands();
}

void UninstallGameConsoleCommands()
{
    Console::UnregisterCommand("testcmd");
    Console::UnregisterCommand("beastmaster");
    Console::UnregisterCommand("db");

    UninstallGMCommands();
}

void InstallGMCommands()
{
    Console::RegisterCommand("invis", CCommand_Invis, CATEGORY_GM, "Go GM Invis");
}

void UninstallGMCommands()
{
     Console::UnregisterCommand("invis");
}
