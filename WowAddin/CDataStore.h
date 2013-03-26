#pragma once

struct CDataStore;

typedef CDataStore* (__thiscall *InitializePtr)(CDataStore *pData);
typedef CDataStore& (__thiscall *PutInt32Ptr)(CDataStore *pData, int val);
typedef CDataStore& (__thiscall *PutFloatPtr)(CDataStore *pData, float val);
typedef CDataStore& (__thiscall *PutCStringPtr)(CDataStore *pData, char const* str);
typedef CDataStore& (__thiscall *PutBytesPtr)(CDataStore *pData, uint8* buf, int size);
typedef void (__thiscall *FinalizePtr)(CDataStore *pData);
typedef void (__thiscall *DestroyPtr)(CDataStore *pData);

struct CDataStore
{
private:
	void *vTable;
	uint8 *m_buffer;
	uint32 m_base;
	uint32 m_alloc;
	uint32 m_size;
	uint32 m_read;

	static InitializePtr fpInit;
	static PutInt32Ptr fpPutInt32;
	static PutFloatPtr fpPutFloat;
	static PutCStringPtr fpPutCString;
	static PutBytesPtr fpPutBytes;
	static FinalizePtr fpFinalize;
	static DestroyPtr fpDestroy;
public:
	CDataStore() { fpInit(this); }
	~CDataStore() { fpDestroy(this); }

	CDataStore& PutInt32(int val) { return fpPutInt32(this, val); }
	CDataStore& PutFloat(float val) { return fpPutFloat(this, val); }
	CDataStore& PutCString(char const* str) { return fpPutCString(this, str); }
	CDataStore& PutPutBytes(uint8* buf, int size) { return fpPutBytes(this, buf, size); }
	void Finalize() { fpFinalize(this); }
};
