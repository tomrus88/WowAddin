#include "stdafx.h"

void (*Console::Write)(const char *fmt, COLOR_T color, ...) = reinterpret_cast<ConsoleWriteA>(ConsoleWriteAddr);
BOOL (*Console::RegisterCommand)(char const* command, CommadHandler handler, CommandCategory category, char const* help) = reinterpret_cast<ConsoleCommandRegisterPtr>(ConsoleRegisterCommandAddr);
void (*Console::UnregisterCommand)(char const* command) = reinterpret_cast<ConsoleCommandUnregisterPtr>(ConsoleUnregisterCommandAddr);
