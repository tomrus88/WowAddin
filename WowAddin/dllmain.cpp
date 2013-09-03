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
        //Console::Write("DLL_THREAD_ATTACH", ECHO_COLOR);
        break;
    case DLL_THREAD_DETACH:
        //Console::Write("DLL_THREAD_DETACH", ECHO_COLOR);
        break;
    case DLL_PROCESS_DETACH:
        //Console::Write("DLL_PROCESS_DETACH", ECHO_COLOR);
        //UninstallGameConsoleCommands(); // cause client to crash at closing
        break;
    }
    return TRUE;
}

struct SizeOfCode
{
    DWORD_PTR start;
    DWORD_PTR end;
};

// Fix InvalidPtrCheck for callbacks outside of .text section
void FixInvalidPtrCheck()
{
    SizeOfCode *s = reinterpret_cast<SizeOfCode*>(SIZE_OF_CODE_ADDR);
    s->start = 0x00000001;
    s->end = 0x7FFFFFFF;
}

// Enable console without using -console command line argument
void EnableConsole()
{
    *reinterpret_cast<DWORD*>(ENABLE_CONSOLE_ADDR) = 1;
}

void InstallGameConsoleCommands()
{
    Console::RegisterCommand("testcmd", CCommand_TestCommand, CATEGORY_DEBUG, "Test help string");
    Console::RegisterCommand("beastmaster", CCommand_Beastmaster, CATEGORY_DEBUG, "Beastmaster mode");
    Console::RegisterCommand("db", CCommand_DBLookup, CATEGORY_DEBUG, "TableName (Name or #ID) Note:Wildcard use * in TableName or Name not ID though");
    Console::RegisterCommand("showobjects", CCommand_ShowObjects, CATEGORY_DEBUG, "Display list of visible objects");

    InstallGMCommands();
}

void UninstallGameConsoleCommands()
{
    Console::UnregisterCommand("testcmd");
    Console::UnregisterCommand("beastmaster");
    Console::UnregisterCommand("db");
    Console::UnregisterCommand("showobjects");

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
