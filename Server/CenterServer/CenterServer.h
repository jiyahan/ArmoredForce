#pragma once

#include <unordered_map>
#include <RCF/RCF.hpp>
#include "AppConfig.h"
#include "Singleton.h"
#include "../RPC/ICenterRpcService.h"
#include "../RPC/ILoginRpcService.h"

typedef std::set<std::pair<std::string, int32_t>>   GameServerList;

//
// 中心服务器
//
class CenterServer : public Singleton<CenterServer>
{
public:
    CenterServer();
    ~CenterServer();

    //初始化
    bool    Init(const AppConfig& cfg);

    // 释放资源
    void    Release();

    // 运行服务器
    bool    Run();

    // 停止服务器
    void    Stop();

    //////////////////////////////////////////////////////////////////////////
    // RPC Service
    //
public:
    // 获得一个GameServer的地址
    bool   GetGameServerAddress(std::string& host, int16_t& port);

    // 获得某个账户的登录验证
    std::string     GetUserLoginSign(const std::string& account);

    // 注册GameServer
    bool            RegisterGameServer(const std::string& address, int16_t port);

private:
    AppConfig           config_;        // 配置    
    RCF::RcfServer      rpc_server_;
    //RCF::RcfClient<ILoginRpcService>      rpc_client_;
    GameServerList      gameserver_list_;
};
