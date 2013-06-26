#include "stdafx.h"

extern ClientServices s_client;

void SetMessageHandlers()
{
    s_client.SetMessageHandler(SMSG_DBLOOKUP, LookupResultsHandler, (void*)0xDEADBABE);
}

// test change
BOOL LookupResultsHandler(void *param, NETMESSAGE msgId, uint32 time, CDataStore *msg)
{
    char received[256];

    msg->GetString(received, sizeof(received));

    Console::Write("Hello from LookupResultsHandler! param %08X time %u ticks %u received %s", ECHO_COLOR, param, time, GetTickCount(), received);

    return TRUE;
}
