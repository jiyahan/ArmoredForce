﻿#include "MsgProcess.h"
#include <iostream>
#include <RCF/RCF.hpp>
#include <easylogging++.h>
#include "LoginServer.h"
#include "../Utility/MyConnectionPool.h"
#include "common/MSGLogin.h"
#include "common/MSGCode.h"
#include "common/update/tagGameServer.h"


using namespace std;
using namespace mysqlpp;
using namespace atom;
using namespace electron;





// 处理角色登录
void ProcessUserLogin(CMessage& msg)
{
    MSGLoginLogin request;
    msg >> request;
    cout << request.account << endl << request.password << endl;

    int status = 0;

    // 调用存储过程sp_user_login获得登录结果
    try
    {
        //ScopedConnection conn(MyConnectionPool::GetInstance());
        //Query query = conn->query("call sp_user_login %0q, %1q");
        //StoreQueryResult result = query.store(request.account.c_str(), request.password.c_str());    
        //if (!result.empty() && !result[0].empty())
        {
            //status = static_cast<int>(result[0][0]);
        }
    }
    catch(mysqlpp::Exception& ex)
    {
        cout << ex.what() << endl;
    }

    string signatrue = GetRpcClientPtr()->GetLoginSignature(request.account.c_str());

    MSGLoginLoginResponse response = {signatrue.c_str(), status};
    GetTCPServer().Send(msg.GetConnector(), MID_LOGIN_LOGINRESPONSE, response);
}


void ProcessVerifyVersion(CMessage& msg)
{
    MSGLoginVersionVerify request;
    msg >> request;
    cout << request.major << "\t" << request.minor << endl;

    // rpc调用
    string host;
    I16 port = 0;
    bool ok = GetRpcClientPtr()->GetGameServerAddress(host, port);

    version::GameServerArea game_area;
    version::GameServerList server_list;
    version::tagGameServer game_server;
    game_server.domain.host = host.c_str();
    game_server.domain.port = port;
    game_server.entity = "Thunder";
    server_list.push_back(game_server);
    game_area["World 1"] = server_list;

    MSGLoginVersionVerifyResponse response;
    response.result = 0;
        
    CArchive archive;
    archive << game_area;
    archive.Clone(response.server_area);
    
    GetTCPServer().Send(msg.GetConnector(), MID_VERSION_VERIFYRESPONSE, response);
}


HandlerMap GetMsgHandlers()
{
    HandlerMap handlers;
    handlers[MID_LOGIN_LOGIN] = ProcessUserLogin;
    handlers[MID_VERSION_VERIFY] = ProcessVerifyVersion;
    return std::move(handlers);
}