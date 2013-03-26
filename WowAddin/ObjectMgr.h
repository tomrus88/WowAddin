#pragma once

enum TypeMask
{
  TYPEMASK_OBJECT = 0x1,
  TYPEMASK_ITEM = 0x2,
  TYPEMASK_CONTAINER = 0x4,
  TYPEMASK_UNIT = 0x8,
  TYPEMASK_PLAYER = 0x10,
  TYPEMASK_GAMEOBJECT = 0x20,
  TYPEMASK_DYNAMICOBJECT = 0x40,
  TYPEMASK_CORPSE = 0x80,
};

typedef uint64 (__cdecl *ClntObjMgrGetActivePlayerGuidPtr)();

typedef void* (__cdecl *ClntObjMgrObjectPtr)(uint64 objectGuid, TypeMask objectTypeMask, const char *file, int line);

class ObjectMgr
{
public:
	uint64 GetActivePlayerGuid() { return fpGetActivePlayerGuid(); }
	void *GetObjectPtr(uint64 objectGuid, TypeMask objectTypeMask) { return fpGetObjectPtr(objectGuid, objectTypeMask, "", 0); }
private:
	static ClntObjMgrGetActivePlayerGuidPtr fpGetActivePlayerGuid;
	static ClntObjMgrObjectPtr fpGetObjectPtr;
};
