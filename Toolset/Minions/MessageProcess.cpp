#include "StdAfx.h"
#include "MessageProcess.h"
#include "Minons.h"
#include "../../common/MESSAGE_ID.h"
#include "../../common/MSGCode.h"
#include "../../common/MSGGame.h"
#include "../../common/MSGLogin.h"
#include "../../common/RoleCommon.h"
#include "../../common/update/tagGameServer.h"

using namespace std;

Minions&    gMinionMgr = Minions::GetInstance();

void HandleLoginResponse(CMessage& msg)
{
    MSGLoginLoginResponse response;
    msg >> response;
    cout << "result: " << (int)response.result 
        << " signature: " << response.sign << endl;
}

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
    for(auto iter = game_area.begin(); iter != game_area.end(); ++iter)
    {
        cout << iter->first;
        for (auto iterV = iter->second.begin(); iterV != iter->second.end(); ++iterV)
        {
            const version::tagGameServer& var = *iterV;
            domain = var.domain;
            cout << var.entity << ": " << var.domain.host << "\t" << var.domain.port << endl;
        }
    }

    if (gMinionMgr.ResetClient(domain.host.c_str(), domain.port))
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