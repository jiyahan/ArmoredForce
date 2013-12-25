#include "StdAfx.h"
#include "MessageProcess.h"
#include "Minons.h"
#include <iostream>
#include "../../common/MESSAGE_ID.h"
#include "../../common/MSGCode.h"
#include "../../common/MSGGame.h"
#include "../../common/MSGLogin.h"
#include "../../common/RoleCommon.h"
#include "../../common/update/tagGameServer.h"

using namespace std;


Minions&    gMinionMgr = Minions::GetInstance();


// 登录返回
void HandleLoginResponse(CMessage& msg)
{
    MSGLoginLoginResponse response;
    msg >> response;
    cout << "result: " << (int)response.result 
        << " signature: " << response.sign << endl;
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
        cout << item.first;
        for (const auto& server : item.second)
        {
            domain = server.domain;
            cout << server.entity << ": " << server.domain.host << "\t" 
                 << server.domain.port << endl;
        }
    }

    if (gMinionMgr.ResetConnection(domain.host.c_str(), domain.port))
    {
        MSGAccountAuthorize auth_request;
        auth_request.device = "iOS";
        auth_request.deviceType = "iPad air";
        auth_request.account = "johnnie";
        auth_request.usrsign = "hello,kitty";
        gMinionMgr.GetClient().Send(MID_ACCOUNT_AUTHORIZE_REQUEST, auth_request);
    }
}

void HandleAuthResponse(CMessage& msg)
{
    MSGAccountAuthorizeResponse response;
    msg >> response;
    cout << (int)response.result << endl;

    RoleCommon role;
    CArchive ar;
    ar.Assign(response.data);
    ar >> role;

    cout << role.name << endl;
}


HandlerMap    GetHandlerMap()
{
    HandlerMap handlers;
    handlers[MID_LOGIN_LOGINRESPONSE] = HandleLoginResponse;
    handlers[MID_VERSION_VERIFYRESPONSE] = HandleVerifyResponse;
    handlers[MID_ACCOUNT_AUTHORIZE_RESPOND] = HandleAuthResponse;
    return std::move(handlers);
}