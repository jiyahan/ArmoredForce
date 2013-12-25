#pragma once

#include <unordered_map>
#include "../Utility/Singleton.h"
#include "../RPC/ICenterRpcService.h"
#include "Net/SocketServer.h"
#include "AppConfig.h"



typedef std::shared_ptr<RcfClient<ICenterRpcService>>   RpcClientPtr;
typedef std::function<void (CMessage&)>                 HandlerType;
typedef std::unordered_map<int32_t, HandlerType>        HandlerMap;

//
// 登录服
//
class LoginServer : public Singleton<LoginServer>
{
public:
    LoginServer();
    ~LoginServer();

    //进行初始化
    bool    Init(const AppConfig& cfg);

    // 释放申请的资源
    void    Release();

    // 运行服务器
    bool    Run();

    // 停止服务器
    void    Stop();

    SocketServer& GetSocketServer() { return server_; }

    const AppConfig& GetConfig() {return config_;}

    RpcClientPtr    GetClient() {return client_;}

private:
    // 处理消息
    void    ProcessMessage();


private:
    AppConfig           config_;        // 配置
    SocketServer        server_;        // TCP服务器

    RpcClientPtr        client_;

    HandlerMap	        handler_map_; //  所有回调函数
};
