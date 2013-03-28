#pragma once

void SetMessageHandlers();
BOOL LookupResultsHandler(void *formal, NETMESSAGE msgId, uint32 time, CDataStore *msg);
