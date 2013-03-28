#pragma once

enum NETMESSAGE;

typedef void (__cdecl *SendPacketPtr)(CDataStore *pData);
typedef void (__thiscall *SendPacket2Ptr)(void *instance, CDataStore *pData);
typedef void* (__cdecl *GetCurrentPtr)();

// formal = pointer to ClientConnection? (seems to be always NULL)
typedef BOOL (__cdecl *PacketHandler)(void *formal, NETMESSAGE msgId, uint32 time, CDataStore *msg);

// a3 = pointer to NetClient?
typedef void (__cdecl *SetMessageHandlerPtr)(NETMESSAGE msgId, PacketHandler handler, int a3);

class ClientServices
{
public:
    // Use only when in game world
    void SendGamePacket(CDataStore *pData) { fpSendPacket(pData); }
    // Can be used both character selection and in game
    void SendPacket(CDataStore *pData) { fpSendPacket2(GetCurrent(), pData); }
    void *GetCurrent() { return fpGetCurrent(); }
    void SetMessageHandler(NETMESSAGE opcode, PacketHandler handler, int a3) { fpSetMessageHandler(opcode, handler, a3); }
private:
    static SendPacketPtr fpSendPacket;
    static SendPacket2Ptr fpSendPacket2;
    static GetCurrentPtr fpGetCurrent;
    static SetMessageHandlerPtr fpSetMessageHandler;
};
