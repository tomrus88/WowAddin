#include "stdafx.h"

ClientServices s_client;
ObjectMgr s_objMgr;

BOOL Command_TestCommand(char const* cmd, char const* args)
{
	Console::Write("Hello from TestCommand: cmd %s, args %s", INPUT_COLOR, cmd, args);

	uint64 guid = s_objMgr.GetActivePlayerGuid();
	void *pPlayer = s_objMgr.GetObjectPtr(guid, TYPEMASK_PLAYER);

	if(!pPlayer)
	{
		Console::Write("TestCommand: Not in world!", ERROR_COLOR);
		return TRUE;
	}

	std::string str(args);

	size_t found = str.find("on");

	BOOL state = 0;

	if(found != std::string::npos)
		state = 1;

	CDataStore data;
	data.PutInt32(CMSG_BEASTMASTER);
	data.PutInt32(state);
	data.PutCString(str.c_str());
	data.Finalize();
	s_client.SendPacket(&data);

	Console::Write("CMSG_BEASTMASTER is %s", ECHO_COLOR, state ? "on" : "off");

	return TRUE;
}
