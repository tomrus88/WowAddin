#pragma once

struct CDataStore;

typedef void (__cdecl *SendPacketPtr)(CDataStore *pData);

class ClientServices
{
public:
	void SendPacket(CDataStore *pData) { fpSendPacket(pData); }
private:
	static SendPacketPtr fpSendPacket;
};
