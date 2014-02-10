#pragma once

#include <memory>
#include <tuple>
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
    explicit LoginServer(const AppConfig& cfg);
    ~LoginServer();

    //进行初始化
    bool    Init();

    // 运行服务器
    bool    Run();

    // 停止服务器
    void    Stop();

    const AppConfig& GetConfig() { return config_; }

    RpcClientPtr    GetClient() { return client_; }

    SocketServer&   GetTcpServer() { return server_; }

    template <typename T>
    void SendMsg(U64 connector, U32 msgid, const T& data)
    {
        CMessage msg(msgid);
        msg << data;
        server_.Send(connector, msg);
    }

    MyConnectionPoolPtr GetConnectionPool() {return conn_pool_;}

    std::tuple<std::string, std::string>    CreatePassword(const std::string& plain);

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

inline LoginServer& GetApp()
{
    return LoginServer::GetInst();
}

inline RpcClientPtr GetRpcClientPtr()
{
    return GetApp().GetClient();
}

inline MyConnectionPoolPtr GetConnectionPoolPtr()
{
    return GetApp().GetConnectionPool();
}
