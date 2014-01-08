#pragma once

#include <set>
#include <boost/noncopyable.hpp>
#include "../RPC/ICenterRpcService.h"



class CenterRpcService : boost::noncopyable
{
public:
    // 获得一个GameServer的地址
    bool   GetGameServerAddress(std::string& host, int16_t& port);

    // 获得某个账户的登录验证
    std::string     GetLoginSignature(const std::string& account);

    // 注册GameServer
    bool            RegisterGameServer(const std::string& address, int16_t port);

private:
    std::set<std::pair<std::string, int16_t>>      gameserver_list_;
};