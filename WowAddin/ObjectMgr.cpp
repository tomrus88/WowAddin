#include "stdafx.h"

uint64 (__cdecl *ObjectMgr::fpGetActivePlayerGuid)() = reinterpret_cast<ClntObjMgrGetActivePlayerGuidPtr>(ClntObjMgrGetActivePlayerGuidAddr);
BOOL (__cdecl *ObjectMgr::fpIsPlayerFullyLoadedInWorld)() = reinterpret_cast<ClntObjMgrIsPlayerFullyLoadedInWorldPtr>(IsPlayerFullyLoadedInWorldAddr);
CGObject_C* (__cdecl *ObjectMgr::fpGetObjectPtr)(uint64 objectGuid, TypeMask objectTypeMask, const char *file, int line) = reinterpret_cast<ClntObjMgrObjectPtr>(GetObjectPtrAddr);
BOOL (__cdecl *ObjectMgr::fpEnumVisibleObjects)(EnumVisibleObjectsCallback callback, void *param) = reinterpret_cast<ClntObjMgrEnumVisibleObjectsPtr>(EnumVisibleObjectsAddr);
