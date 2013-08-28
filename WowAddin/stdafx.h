// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <stdarg.h>
#include <string>

typedef char int8;
typedef short int16;
typedef int int32;
typedef __int64 int64;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned __int64 uint64;

// Reference additional headers your program requires here
#include "Offsets.h"
#include "Opcodes.h"
#include "UpdateFields.h"
#include "CDataStore.h"
#include "Console.h"
#include "ClientServices.h"
#include "Commands.h"
#include "CGObject_C.h"
#include "CGUnit_C.h"
#include "CGPlayer_C.h"
#include "ObjectMgr.h"
#include "OpcodeHandlers.h"

void InstallGameConsoleCommands();
void UninstallGameConsoleCommands();
void FixInvalidPtrCheck();
void EnableConsole();
void InstallGMCommands();
void UninstallGMCommands();
