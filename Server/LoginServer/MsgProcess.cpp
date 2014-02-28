#include "MsgProcess.h"
#include <iostream>
#include <future>
#include <RCF/RCF.hpp>
#include <easylogging++.h>
#include "LoginServer.h"
#include "common/MSGLogin.h"
#include "common/MSGCode.h"
#include "common/update/tagGameServer.h"
#include "DB/DBLogin.h"
#include "Utility.h"
#include "Foreach.h"



using namespace std;
using namespace atom;
using namespace electron;


void ProcessRegister(CMessage& msg)
{
    MSGLoginRegist req;
    msg >> req;

    string reg_ip = GetApp().GetTcpServer().GetPeerAddress(msg.GetConnector());
    int32_t reg_type = 1;
    int32_t reg_status =  DBLogin::RegisterUser(req.account, reg_type, reg_ip, 
        req.email, req.password);
    if (reg_status == 0)
    {
        LOG(INFO) << req.account << " registered OK";
    }
    else
    {
        LOG(INFO) << req.account << " registered failed, " << reg_status;
    }
}


// 处理角色登录
void ProcessUserLogin(CMessage& msg)
{
    MSGLoginLogin req;
    msg >> req;
    LOG(INFO) << req.account << endl << req.password << endl;

    string reg_ip = GetApp().GetTcpServer().GetPeerAddress(msg.GetConnector());
    int32_t status = DBLogin::UserLogin(req.account, req.password);
    DBLogin::SaveLoginHistory(req.account, reg_ip, status);

    string signatrue;
    if (status == 0)
    {
        signatrue = GetApp().CreateUserLogSign(req.account);
    }

    MSGLoginLoginResponse response = {signatrue, status};
    GetApp().SendMsg(msg.GetConnector(), MID_LOGIN_LOGINRESPONSE, response);
}


void ProcessVerifyVersion(CMessage& msg)
{
    MSGLoginVersionVerify request;
    msg >> request;
    cout << request.major << "\t" << request.minor << endl;

    version::GameServerArea game_area;
    const auto& game_world = GetApp().GetGameWorldInfo();
    FOR_EACH_KV(name, game_list, game_world)
    {        
        version::GameServerList server_list;
        for (const auto& gameinfo : game_list)
        {
            version::tagGameServer game_server;
            game_server.entity = std::get<0>(gameinfo).c_str();
            game_server.domain.host = std::get<1>(gameinfo).c_str();
            game_server.domain.port = std::get<2>(gameinfo);
            server_list.push_back(game_server);
        }        
        game_area[name] = server_list;
    }

    MSGLoginVersionVerifyResponse response;
    response.result = 0;
        
    CArchive archive;
    archive << game_area;
    archive.Clone(response.server_area);
    
    GetApp().SendMsg(msg.GetConnector(), MID_VERSION_VERIFYRESPONSE, response);
}


HandlerMap GetMsgHandlers()
{
    HandlerMap handlers;
    handlers[MID_LOGIN_LOGIN] = ProcessUserLogin;
    handlers[MID_VERSION_VERIFY] = ProcessVerifyVersion;
    handlers[MID_LOGIN_REGISTER] = ProcessRegister;
    
    return std::move(handlers);
}