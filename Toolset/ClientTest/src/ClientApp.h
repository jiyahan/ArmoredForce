#pragma once

#include <memory>
#include <boost/noncopyable.hpp>
#include "Net/SocketClient.h"
#include "MessageProcess.h"
#include "Config.h"
#include "Singleton.h"


class ClientApp : public Singleton<ClientApp>
{
public:
    explicit ClientApp(const Config& cfg);
    ~ClientApp();

    bool Init();

    // 主循环
    bool    Run();

    // 重置与服务器的连接
    bool    ResetConnection(const std::string& host, U16 port);

    template <typename T>
    void SendMsg(U32 msgID, const T& data)
    {
        //static_assert(std::is_pod<T>::value, "pod only");
        CMessage msg(msgID);
        msg << data;
        client_.Send(msg);
    }

    SocketClient& GetTcpClient() { return client_;}

private:

    // 处理消息
    void    ProcessMessage();

private:
    const Config    cfg_;
    SocketClient    client_;
    HandlerMap      handler_map_;   //  消息路由表
};

inline ClientApp& GetApp()
{
    return ClientApp::GetInst();
}