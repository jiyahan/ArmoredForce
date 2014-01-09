#pragma once

#include <memory>
#include <RCF/RCF.hpp>
#include "AppConfig.h"
#include "Net/SocketServer.h"
#include "Server/Utility/Singleton.h"
#include "Server/Utility/Random.h"
#include "Server/RPC/ICenterRpcService.h"
#include "MsgProcess.h"
#include "common/setup/ArmyCategory.h"
#include "common/setup/MonsterList.h"
#include "common/setup/OfficerList.h"
#include "common/setup/RegionList.h"

typedef std::shared_ptr<RcfClient<ICenterRpcService>>   RpcClientPtr;


//
// 游戏服
//
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

    SocketServer&   GetSocketServer() {return server_;}

    RpcClientPtr    GetClient() { return client_;}

    Random&     GetRandGen() {return rnd_gen_;}

private:

    // 处理网络消息
    void    ProcessMessage();

    void	RegisterMsgHandler();

private:
    AppConfig           config_;        // 配置
    SocketServer        server_;        // TCP服务器

    RpcClientPtr        client_;
    
    HandlerMap	        msg_handlers_;

    Random              rnd_gen_;   // 随机数生成器 
};

inline GameServer& GetServer()
{
    return GameServer::GetInstance();
}

inline RpcClientPtr GetRpcClientPtr()
{
    return GetServer().GetClient();
}

inline SocketServer& GetTCPServer()
{
    return GetServer().GetSocketServer();
}

inline uint32_t  Random(uint32_t max)
{
    return GetServer().GetRandGen().Uniform(max);
}
