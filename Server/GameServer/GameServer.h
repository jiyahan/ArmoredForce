#pragma once

#include <memory>
#include <unordered_map>
#include <boost/shared_ptr.hpp>
#include <RCF/RCF.hpp>
#include "AppConfig.h"
#include "Net/SocketServer.h"
#include "../Utility/Singleton.h"
#include "../RPC/ICenterRpcService.h"


typedef boost::shared_ptr<RcfClient<ICenterRpcService>>   RpcClientPtr;

//
// 游戏服
//
class GameServer : public Singleton<GameServer>
{
public:
    GameServer();
    ~GameServer();

    //初始化
    bool    Init();

    // 释放资源
    void    Release();

    // 运行服务器
    bool    Run();

    // 停止服务器
    void    Stop();

    SocketServer&   GetSocketServer() {return server_;}

    RpcClientPtr    GetClient() { return client_;}

private:

    // 处理网络消息
    void    ProcessMessage();

    void	RegisterMsgHandler();

private:
    AppConfig           config_;        // 配置
    SocketServer        server_;        // TCP服务器

    RpcClientPtr        client_;

    typedef std::function<void (CMessage&)>		HandlerType;

    std::unordered_map<int32_t, HandlerType>	handler_map_;
};
