#include "stdafx.h"

CDataStore* (__thiscall *CDataStore::fpInit)(CDataStore *pData) = (InitializePtr)0x00401050;

CDataStore& (__thiscall *CDataStore::fpPutInt8)(CDataStore *pData, int8 val) = (PutInt8Ptr)0x0047AFE0;
CDataStore& (__thiscall *CDataStore::fpPutInt16)(CDataStore *pData, int16 val) = (PutInt16Ptr)0x0047B040;
CDataStore& (__thiscall *CDataStore::fpPutInt32)(CDataStore *pData, int32 val) = (PutInt32Ptr)0x0047B0A0;
CDataStore& (__thiscall *CDataStore::fpPutInt64)(CDataStore *pData, int64 val) = (PutInt64Ptr)0x0047B100;
CDataStore& (__thiscall *CDataStore::fpPutFloat)(CDataStore *pData, float val) = (PutFloatPtr)0x0047B160;
CDataStore& (__thiscall *CDataStore::fpPutString)(CDataStore *pData, char const* pString) = (PutStringPtr)0x0047B300;
CDataStore& (__thiscall *CDataStore::fpPutBytes)(CDataStore *pData, uint8* pBuf, uint32 size) = (PutBytesPtr)0x0047B1C0;

CDataStore& (__thiscall *CDataStore::fpGetInt8)(CDataStore *pData, int8& val) = (GetInt8Ptr)0x0047B340;
CDataStore& (__thiscall *CDataStore::fpGetInt16)(CDataStore *pData, int16& val) = (GetInt16Ptr)0x0047B380;
CDataStore& (__thiscall *CDataStore::fpGetInt32)(CDataStore *pData, int32& val) = (GetInt32Ptr)0x0047B3C0;
CDataStore& (__thiscall *CDataStore::fpGetInt64)(CDataStore *pData, int64& val) = (GetInt64Ptr)0x0047B400;
CDataStore& (__thiscall *CDataStore::fpGetFloat)(CDataStore *pData, float& val) = (GetFloatPtr)0x0047B440;
CDataStore& (__thiscall *CDataStore::fpGetString)(CDataStore *pData, char* pString, uint32 maxChars) = (GetStringPtr)0x0047B480;
CDataStore& (__thiscall *CDataStore::fpGetBytes)(CDataStore *pData, uint8* pBuf, uint32 numBytes) = (GetBytesPtr)0x0047B560;

void (__thiscall *CDataStore::fpFinalize)(CDataStore *pData) = (FinalizePtr)0x00401130;
void (__thiscall *CDataStore::fpDestroy)(CDataStore *pData) = (DestroyPtr)0x00403880;
