#include "stdafx.h"

void (*ClientServices::fpSendPacket)(CDataStore *pData) = reinterpret_cast<SendPacketPtr>(0x00406F40);
void (__thiscall *ClientServices::fpSendPacket2)(void *instance, CDataStore *pData) = reinterpret_cast<SendPacket2Ptr>(0x00632B50);
void* (*ClientServices::fpGetCurrent)() = reinterpret_cast<GetCurrentPtr>(0x006B0970);
void (*ClientServices::fpSetMessageHandler)(NETMESSAGE msgId, PacketHandler handler, void *param) = reinterpret_cast<SetMessageHandlerPtr>(0x006B0B80);
