#include "stdafx.h"

uint64 (__cdecl *ObjectMgr::fpGetActivePlayerGuid)() = (ClntObjMgrGetActivePlayerGuidPtr)0x004D3790;
void* (__cdecl *ObjectMgr::fpGetObjectPtr)(uint64 objectGuid, TypeMask objectTypeMask, const char *file, int line) = (ClntObjMgrObjectPtr)0x004D4DB0;
