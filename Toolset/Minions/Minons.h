#pragma once

#include <memory>
#include <unordered_map>
#include "Net/SocketClient.h"
#include "../../Server/Utility/Singleton.h"


class Minions : public Singleton<Minions>
{
public:
    Minions();
    ~Minions();

    bool    Init();

    void    Release();

    bool    Run();

    SocketClient&  GetClient() {return *client_ptr_;}

    bool    ResetClient(const char* host, int port);

private:
    // 处理消息
    void    ProcessMessage();
    void    RegisterMessageHandler();

private:
    std::shared_ptr<SocketClient>    client_ptr_;

    typedef std::function<void (CMessage&)>   HandlerType;

    std::unordered_map<int32_t, HandlerType>	handler_map_; //  所有回调函数
};