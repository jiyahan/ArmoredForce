#pragma once

#include <memory>
#include <boost/noncopyable.hpp>
#include "Net/SocketClient.h"
#include "MessageProcess.h"
#include "Config.h"

class ClientApp;
ClientApp&  GetClientApp();
bool        CreateClientApp(const Config& cfg);
void        DestroyClientApp();

class ClientApp : boost::noncopyable
{
public:
    explicit ClientApp(const Config& cfg);
    ~ClientApp();

    // 主循环
    bool    Run();

    // 重置与服务器的连接
    bool    ResetConnection(const std::string& host, U16 port);

    SocketClient& GetTcpClient() { return client_;}

private:

    // 处理消息
    void    ProcessMessage();

private:
    const Config    cfg_;
    SocketClient    client_;
    HandlerMap      handler_map_;   //  消息路由表
};



//////////////////////////////////////////////////////////////////////////

inline SocketClient& GetTcpClient()
{
    return GetClientApp().GetTcpClient();
}
