#include "stdafx.h"

void (*Console::Write)(const char *fmt, COLOR_T color, ...) = (ConsoleWriteA)0x00765360;
BOOL (*Console::RegisterCommand)(char const* command, CommadHandler handler, CommandCategory category, char const* help) = (ConsoleCommandRegisterPtr)0x00769100;
void (*Console::UnregisterCommand)(char const* command) = (ConsoleCommandUnregisterPtr)0x007689E0;
