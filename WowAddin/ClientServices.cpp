#include "stdafx.h"

void (*ClientServices::fpSendPacket)(CDataStore *pData) = (SendPacketPtr)0x00406F40;
void (*ClientServices::fpSetMessageHandler)(Opcodes opcode, PacketHandler handler, int a3) = (SetMessageHandlerPtr)0x006B0B80;
