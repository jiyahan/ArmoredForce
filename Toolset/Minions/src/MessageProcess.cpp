#include "MessageProcess.h"
#include "MinonMgr.h"
#include <iostream>
#include "common/MESSAGE_ID.h"
#include "common/MSGCode.h"
#include "common/MSGGame.h"
#include "common/MSGLogin.h"
#include "common/RoleCommon.h"
#include "common/update/tagGameServer.h"
#include "common/battle/tagBattle.h"

using namespace std;
using namespace atom;
using namespace electron;


void RequestRegister()
{
    MSGLoginRegist reg = {"johnnie", "123456", "johne@gove.cn"};
    //GetTCPClient().Send(MID_LOGIN_REGISTER, reg);
}

//////////////////////////////////////////////////////////////////////////

// 登录返回
void HandleLoginResponse(CMessage& msg)
{
    MSGLoginLoginResponse response;
    msg >> response;
    cout << "result: " << (int)response.result 
        << " signature: " << response.sign << endl;
}

void HandleRegisterResponse(CMessage& msg)
{
    MSGLoginRegistResponse response;
    msg >> response;
    cout << "result: " << (int)response.result << endl;
}

// 验证返回
void HandleVerifyResponse(CMessage& msg)
{
    MSGLoginVersionVerifyResponse response;
    msg >> response;
    cout << "result: " << (int)response.result << endl;

    version::GameServerArea game_area;
    CArchive ar;
    ar.Assign(response.server_area);
    ar >> game_area;

    tagDomain domain;    
    for(const auto& item : game_area)
    {
        cout << item.first << "\t";
        for (const auto& server : item.second)
        {
            domain = server.domain;
            cout << server.entity << ": " << server.domain.host << "\t" 
                 << server.domain.port << endl;
        }
    }

    RequestRegister();

#if 0
    if (GetMinions().ResetConnection(domain.host.c_str(), domain.port))
    {
        MSGAccountAuthorize auth_request;
        auth_request.device = "iOS";
        auth_request.deviceType = "iPad air";
        auth_request.account = "johnnie";
        auth_request.usrsign = "hello,kitty";
        GetMinions().GetClient().Send(MID_ACCOUNT_AUTHORIZE_REQUEST, auth_request);
    }
    else
    {
        LOG(ERROR) << "连接GameServer失败, " << domain.host << ":" << domain.port;
    }
#endif
}

void HandleAuthResponse(CMessage& msg)
{
    MSGAccountAuthorizeResponse response;
    msg >> response;
    cout << (int)response.result << endl;

    vector<OfficerCommon>   officerlist;
    RoleCommon role;
    CArchive ar;
    ar.Assign(response.data);
    ar >> role >> officerlist;

    cout << role.name << endl;

    MSGBattleCombat request;
    request.mapId = 1;
    request.posId = 1;
    //GetMinions().GetClient().Send(request.msgId, request);
}

void HandleCombatResponse(CMessage& msg)
{
    MSGBattleCombatResponse response;
    msg >> response;
    CArchive ar;
    ar.Assign(response.data);
    tagBattle battle;
    ar >> battle;
    cout << battle.attacker.name;
}


HandlerMap    GetHandlerMap()
{
    HandlerMap handlers;
    handlers[MID_LOGIN_LOGINRESPONSE] = HandleLoginResponse;
    handlers[MID_LOGIN_REGISTER_RESPONSE] = HandleRegisterResponse;
    handlers[MID_VERSION_VERIFYRESPONSE] = HandleVerifyResponse;
    handlers[MID_ACCOUNT_AUTHORIZE_RESPOND] = HandleAuthResponse;;
    handlers[MID_CHARACTER_INSTANCE_COMBAT_RESPOND] = HandleCombatResponse;
    return std::move(handlers);
}
