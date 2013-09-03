#include "stdafx.h"

void SetMessageHandlers()
{
    ClientServices::SetMessageHandler(SMSG_DBLOOKUP, LookupResultsHandler, (void*)0xDEADBABE);
}

BOOL LookupResultsHandler(void *param, NETMESSAGE msgId, uint32 time, CDataStore *msg)
{
    char received[256];

    msg->GetString(received, sizeof(received));

    Console::Write("Hello from LookupResultsHandler: param %08X, time %u, ticks %u, received '%s'", ECHO_COLOR, param, time, GetTickCount(), received);

    return TRUE;
}
