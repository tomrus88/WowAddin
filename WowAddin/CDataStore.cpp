#include "stdafx.h"

CDataStore* (__thiscall *CDataStore::fpInit)(CDataStore *pData) = (InitializePtr)0x00401050;
CDataStore& (__thiscall *CDataStore::fpPutInt32)(CDataStore *pData, int val) = (PutInt32Ptr)0x0047B0A0;
CDataStore& (__thiscall *CDataStore::fpPutFloat)(CDataStore *pData, float val) = (PutFloatPtr)0x0047B160;
CDataStore& (__thiscall *CDataStore::fpPutCString)(CDataStore *pData, char const* str) = (PutCStringPtr)0x0047B300;
CDataStore& (__thiscall *CDataStore::fpPutBytes)(CDataStore *pData, uint8* buf, int size) = (PutBytesPtr)0x0047B280;
void (__thiscall *CDataStore::fpFinalize)(CDataStore *pData) = (FinalizePtr)0x00401130;
void (__thiscall *CDataStore::fpDestroy)(CDataStore *pData) = (DestroyPtr)0x00403880;
