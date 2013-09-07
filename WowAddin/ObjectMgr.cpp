#include "stdafx.h"

uint64 (__cdecl *ObjectMgr::fpGetActivePlayerGuid)() = reinterpret_cast<ClntObjMgrGetActivePlayerGuidPtr>(ClntObjMgrGetActivePlayerGuidAddr);
CGObject_C* (__cdecl *ObjectMgr::fpGetObjectPtr)(uint64 objectGuid, TypeMask objectTypeMask, const char *file, int line) = reinterpret_cast<ClntObjMgrObjectPtr>(GetObjectPtrAddr);
BOOL (__cdecl *ObjectMgr::fpEnumVisibleObjects)(VisibleObjectsEnumProc proc, void *param) = reinterpret_cast<ClntObjMgrEnumVisibleObjectsPtr>(EnumVisibleObjectsAddr);
