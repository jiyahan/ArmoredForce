#pragma once

#include <memory>
#include <unordered_map>
#include "Net/SocketClient.h"
#include "../../Server/Utility/Singleton.h"


typedef std::function<void (CMessage&)>   HandlerType;
typedef std::unordered_map<int32_t, HandlerType> HandlerMap;

class Minions : public Singleton<Minions>
{
public:
    Minions();
    ~Minions();

    bool    Init();

    void    Release();

    bool    Run();

    SocketClient&  GetClient() {return client_;}

    bool    ResetConnection(const std::string& host, U16 port);

private:
    // 处理消息
    void    ProcessMessage();
    void    RegisterMessageHandler();

private:
    SocketClient    client_;

    HandlerMap  handler_map_; //  所有回调函数
};