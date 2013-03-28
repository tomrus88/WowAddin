#include "stdafx.h"

void (*ClientServices::fpSendPacket)(CDataStore *pData) = (SendPacketPtr)0x00406F40;
void (__thiscall *ClientServices::fpSendPacket2)(void *instance, CDataStore *pData) = (SendPacket2Ptr)0x00632B50;
void* (*ClientServices::fpGetCurrent)() = (GetCurrentPtr)0x006B0970;
void (*ClientServices::fpSetMessageHandler)(NETMESSAGE msgId, PacketHandler handler, int a3) = (SetMessageHandlerPtr)0x006B0B80;
