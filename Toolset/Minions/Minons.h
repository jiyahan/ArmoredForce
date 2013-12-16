#pragma once

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

private:
    // 处理消息
    void    ProcessMessage();
    void    RegisterMessageHandler();

private:
    SocketClient    client_;

    typedef std::function<void (CMessage&)>   HandlerType;

    std::unordered_map<int32_t, HandlerType>	handler_map_; //  所有回调函数
};