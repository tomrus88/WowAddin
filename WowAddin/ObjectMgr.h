#pragma once

enum TypeMask
{
    TYPEMASK_OBJECT         = 0x1,
    TYPEMASK_ITEM           = 0x2,
    TYPEMASK_CONTAINER      = 0x4,
    TYPEMASK_UNIT           = 0x8,
    TYPEMASK_PLAYER         = 0x10,
    TYPEMASK_GAMEOBJECT     = 0x20,
    TYPEMASK_DYNAMICOBJECT  = 0x40,
    TYPEMASK_CORPSE         = 0x80,
};

typedef uint64 (__cdecl *ClntObjMgrGetActivePlayerGuidPtr)();

typedef CGObject_C* (__cdecl *ClntObjMgrObjectPtr)(uint64 objectGuid, TypeMask objectTypeMask, const char *file, int line);

// return 0 to stop enumeration, 1 to continue
typedef BOOL (__cdecl *VisibleObjectsEnumProc)(uint64 objectGuid, void *param);

// returns 0 if enumeration stopped by callback, 1 otherwise (iterate through all objects)
typedef BOOL (__cdecl *ClntObjMgrEnumVisibleObjectsPtr)(VisibleObjectsEnumProc proc, void *param);

class ObjectMgr
{
public:
    static uint64 GetActivePlayerGuid() { return fpGetActivePlayerGuid(); }
    static CGObject_C *GetObjectPtr(uint64 objectGuid, TypeMask objectTypeMask) { return fpGetObjectPtr(objectGuid, objectTypeMask, "", 0); }
    static BOOL EnumVisibleObjects(VisibleObjectsEnumProc proc, void *param) { return fpEnumVisibleObjects(proc, param); }
	static BOOL IsInWorld() { return fpGetActivePlayerGuid() != 0; }
private:
    static ClntObjMgrGetActivePlayerGuidPtr fpGetActivePlayerGuid;
    static ClntObjMgrObjectPtr fpGetObjectPtr;
    static ClntObjMgrEnumVisibleObjectsPtr fpEnumVisibleObjects;
};
