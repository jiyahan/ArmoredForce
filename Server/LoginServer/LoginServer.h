#pragma once

#include <memory>
#include "Singleton.h"
#include "AppConfig.h"
#include "Server/RPC/ICenterRpcService.h"
#include "Net/SocketServer.h"
#include "MsgProcess.h"
#include "MyConnectionPool.h"
#include "pbkdf2.h"


typedef std::shared_ptr<RcfClient<ICenterRpcService>>   RpcClientPtr;
 

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

    MyConnectionPoolPtr GetConnectionPool() {return conn_pool_;}

    PBKDF2&         GetPBKDF2() {return pbkdf2_;}

private:
    // 处理消息
    void    ProcessMessage();


private:
    // 配置信息
    AppConfig           config_;

    // TCP服务器
    SocketServer        server_;

    // RPC客户端
    RpcClientPtr        client_;

    // 消息路由表
    HandlerMap          handler_map_;

    MyConnectionPoolPtr conn_pool_;

    PBKDF2              pbkdf2_;
};

inline LoginServer& GetServer()
{
    return LoginServer::GetInstance();
}

inline RpcClientPtr GetRpcClientPtr()
{
    return GetServer().GetClient();
}

inline SocketServer& GetTCPServer()
{
    return GetServer().GetSocketServer();
}

inline MyConnectionPoolPtr GetConnectionPoolPtr()
{
    return GetServer().GetConnectionPool();
}
