#pragma once

#include <memory>
#include <RCF/RCF.hpp>
#include "AppConfig.h"
#include "Net/SocketServer.h"
#include "Singleton.h"
#include "Random.h"
#include "Server/RPC/ICenterRpcService.h"
#include "MsgProcess.h"
#include "App/BattleSys.h"


typedef std::shared_ptr<RcfClient<ICenterRpcService>>   RpcClientPtr;


class GameServer : public Singleton<GameServer>
{
public:
    GameServer();
    ~GameServer();

    //初始化
    bool    Init(const AppConfig& cfg);

    // 释放资源
    void    Release();

    // 运行服务器
    bool    Run();

    // 停止服务器
    void    Stop();

    // TCP服务
    SocketServer&   GetSocketServer() {return server_;}

    // RPC客户端
    RpcClientPtr    GetClient() { return client_;}

    // 随机数生成器
    Random&         GetRandGen() { return rnd_gen_; }

    BattleSys&      GetBattleSys() { return battle_sys_; }

private:

    // 处理网络消息
    void    ProcessMessage();

private:
    AppConfig           config_;        // 配置
    SocketServer        server_;        // TCP服务器

    RpcClientPtr        client_;
    
    HandlerMap	        msg_handlers_;

    Random              rnd_gen_;   // 随机数生成器 

    BattleSys           battle_sys_;
};

inline GameServer& GetServer()
{
    return GameServer::GetInst();
}

inline RpcClientPtr GetRpcClientPtr()
{
    return GetServer().GetClient();
}

inline SocketServer& GetTCPServer()
{
    return GetServer().GetSocketServer();
}

inline uint32_t  Rand(uint32_t max)
{
    return GetServer().GetRandGen().Uniform(max);
}

inline BattleSys&  GetBattleSys()
{
    return GetServer().GetBattleSys();
}