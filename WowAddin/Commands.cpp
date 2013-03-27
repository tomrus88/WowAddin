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

    CGObject_C *pTarget = s_objMgr.GetObjectPtr(pPlayer->GetValue<uint64>(UNIT_FIELD_TARGET), TYPEMASK_UNIT);

    if (pTarget)
        Console::Write("Target %s, guid 0x%016llX", ECHO_COLOR, pTarget->GetObjectName(), pTarget->GetValue<uint64>(OBJECT_FIELD_GUID));
    else
        Console::Write("No target!", ECHO_COLOR);

    return TRUE;
}

BOOL CCommand_Beastmaster(char const* cmd, char const* args)
{
    CDataStore data;
    data.PutInt32(CMSG_BEASTMASTER);
    int state = _strnicmp(args, "off", INT_MAX) != 0;
    data.PutInt8(state);
    data.Finalize();
    s_client.SendPacket(&data);

    Console::Write("Beastmaster mode is %s", ECHO_COLOR, state ? "on" : "off");

    return TRUE;
}

BOOL CCommand_Invis(char const* cmd, char const* args)
{
    CDataStore data;
    data.PutInt32(CMSG_GM_INVIS);
    int state = _strnicmp(args, "off", INT_MAX) != 0;
    data.PutInt32(state);
    data.Finalize();
    s_client.SendPacket(&data);

    Console::Write("GM invis mode is %s", ECHO_COLOR, state ? "on" : "off");

    return TRUE;
}

BOOL CCommand_DBLookup(char const* cmd, char const* args)
{
    CDataStore data;
    data.PutInt32(CMSG_DBLOOKUP);
    data.PutCString(args);
    data.Finalize();
    s_client.SendPacket(&data);

    return TRUE;
}
