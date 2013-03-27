#include "stdafx.h"

ClientServices s_client;
ObjectMgr s_objMgr;

BOOL Command_TestCommand(char const* cmd, char const* args)
{
    Console::Write("Hello from TestCommand: cmd %s, args %s", INPUT_COLOR, cmd, args);

    uint64 guid = s_objMgr.GetActivePlayerGuid();
    CGObject_C *pPlayer = s_objMgr.GetObjectPtr(guid, TYPEMASK_PLAYER);

    if (!pPlayer)
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

    CGObject_C *pTarget = s_objMgr.GetObjectPtr(pPlayer->GetValue<uint64>(UNIT_FIELD_TARGET), TYPEMASK_UNIT);

    Console::Write("CMSG_BEASTMASTER is %s", ECHO_COLOR, state ? "on" : "off");

    if (pTarget)
        Console::Write("Target %s, guid 0x%016llX", ECHO_COLOR, pTarget->GetObjectName(), pTarget->GetValue<uint64>(OBJECT_FIELD_GUID));
    else
        Console::Write("No target!", ECHO_COLOR);

    return TRUE;
}
