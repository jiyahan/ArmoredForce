#pragma once

#include <memory>
#include <unordered_map>
#include "Net/SocketClient.h"
#include "Server/Utility/Singleton.h"
#include "Config.h"

typedef std::function<void (CMessage&)>         HandlerType;
typedef std::unordered_map<I32, HandlerType>    HandlerMap;



// 一个机器人
class Minions : public Singleton<Minions>
{
public:
    Minions();
    ~Minions();

    // 初始化
    bool    Init(const Config& cfg);

    void    Release();

    // 主循环
    bool    Run();

    SocketClient&  GetClient() {return client_;}

    // 重置与服务器的连接
    bool    ResetConnection(const std::string& host, U16 port);

private:
    // 处理消息
    void    ProcessMessage();

private:
    Config          cfg_;
    SocketClient    client_;
    HandlerMap      handler_map_;   //  消息路由表
};