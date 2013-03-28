#include "stdafx.h"

extern ClientServices s_client;

void SetMessageHandlers()
{
    s_client.SetMessageHandler(SMSG_DBLOOKUP, LookupResultsHandler, 0);
}

BOOL LookupResultsHandler(void *formal, NETMESSAGE msgId, uint32 time, CDataStore *msg)
{
    char received[256];

    msg->GetString(received, sizeof(received));

    Console::Write("Hello from LookupResultsHandler! time %u ticks %u received %s", ECHO_COLOR, time, GetTickCount(), received);

    return TRUE;
}
