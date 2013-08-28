#pragma once

typedef void (__cdecl *SendPacketPtr)(CDataStore *pData);
typedef void (__thiscall *SendPacket2Ptr)(void *instance, CDataStore *pData);
typedef void* (__cdecl *GetCurrentPtr)();

typedef BOOL (__cdecl *PacketHandler)(void *param, NETMESSAGE msgId, uint32 time, CDataStore *msg);

typedef void (__cdecl *SetMessageHandlerPtr)(NETMESSAGE msgId, PacketHandler handler, void *param);

class ClientServices
{
public:
    // Use only when in game world
    static void SendGamePacket(CDataStore *pData) { pData->Finalize(); fpSendPacket(pData); }
    // Can be used both character selection and in game
    static void SendPacket(CDataStore *pData) { pData->Finalize(); fpSendPacket2(GetCurrent(), pData); }
    static void *GetCurrent() { return fpGetCurrent(); }
    static void SetMessageHandler(NETMESSAGE msgId, PacketHandler handler, void *param) { fpSetMessageHandler(msgId, handler, param); }
private:
    static SendPacketPtr fpSendPacket;
    static SendPacket2Ptr fpSendPacket2;
    static GetCurrentPtr fpGetCurrent;
    static SetMessageHandlerPtr fpSetMessageHandler;
};
