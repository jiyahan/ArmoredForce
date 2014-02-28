#include "ProcessLogin.h"
#include "../ClientApp.h"
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

static void RequestRegister()
{
    for (int i = 1; i < 100; ++i)
    {
        char name[40] = {};
        _snprintf(name, _countof(name), "test%03d", i);
        string email = name + string("@gov.cn");
        MSGLoginRegist req = { name, "111111", email.c_str() };
        GetApp().SendMsg(MID_LOGIN_REGISTER, req);
    }
}

void RequestLogin()
{
    a_string user = "test010";
    a_string passwd = "111111";
    MSGLoginLogin req = {user, passwd};
    GetApp().SendMsg(MID_LOGIN_LOGIN, req);
}

void RequestLoginGameServer(const a_string& host, int16_t port)
{
    if (GetApp().ResetConnection(host.c_str(), port))
    {
        MSGAccountAuthorize auth_request;
        auth_request.device = "iOS";
        auth_request.deviceType = "iPad air";
        auth_request.account = "johnnie";
        auth_request.usrsign = "hello,kitty";
        GetApp().SendMsg(MID_ACCOUNT_AUTHORIZE_REQUEST, auth_request);
    }
    else
    {
        LOG(ERROR) << "连接GameServer失败, " << host << ":" << port;
    }
}

//////////////////////////////////////////////////////////////////////////

// 登录返回
void HandleLoginResponse(CMessage& msg)
{
    MSGLoginLoginResponse response;
    msg >> response;
    cout << "result: " << (int)response.result 
        << " signature: " << response.sign << endl;

    MSGLoginVersionVerify verify_request = {};
    GetApp().SendMsg(MID_VERSION_VERIFY, verify_request);
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

    RequestLoginGameServer(domain.host, domain.port);
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

void OnConnectLoginServer()
{
    LOG(INFO) << "连接服务器成功, 发送登录请求...";
    RequestLogin();

}