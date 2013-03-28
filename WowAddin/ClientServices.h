#pragma once

enum NETMESSAGE;

typedef void (__cdecl *SendPacketPtr)(CDataStore *pData);
typedef void (__thiscall *SendPacket2Ptr)(void *instance, CDataStore *pData);
typedef void* (__cdecl *GetCurrentPtr)();

typedef BOOL (__cdecl *PacketHandler)(void *param, NETMESSAGE msgId, uint32 time, CDataStore *msg);

typedef void (__cdecl *SetMessageHandlerPtr)(NETMESSAGE msgId, PacketHandler handler, void *param);

class ClientServices
{
public:
    // Use only when in game world
    void SendGamePacket(CDataStore *pData) { fpSendPacket(pData); }
    // Can be used both character selection and in game
    void SendPacket(CDataStore *pData) { fpSendPacket2(GetCurrent(), pData); }
    void *GetCurrent() { return fpGetCurrent(); }
    void SetMessageHandler(NETMESSAGE msgId, PacketHandler handler, void *param) { fpSetMessageHandler(msgId, handler, param); }
private:
    static SendPacketPtr fpSendPacket;
    static SendPacket2Ptr fpSendPacket2;
    static GetCurrentPtr fpGetCurrent;
    static SetMessageHandlerPtr fpSetMessageHandler;
};
