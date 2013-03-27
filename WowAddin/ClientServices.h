#pragma once

enum Opcodes;

typedef void (__cdecl *SendPacketPtr)(CDataStore *pData);

// a1 = pointer to ClientConnection?
// a3 = ??? may be time
typedef BOOL (__cdecl *PacketHandler)(void *a1, Opcodes opcode, int a3, CDataStore *pData);

// a3 = pointer to NetClient?
typedef void (__cdecl *SetMessageHandlerPtr)(Opcodes opcode, PacketHandler handler, int a3);

class ClientServices
{
public:
    void SendPacket(CDataStore *pData) { fpSendPacket(pData); }
    void SetMessageHandler(Opcodes opcode, PacketHandler handler, int a3) { fpSetMessageHandler(opcode, handler, a3); }
private:
    static SendPacketPtr fpSendPacket;
    static SetMessageHandlerPtr fpSetMessageHandler;
};
