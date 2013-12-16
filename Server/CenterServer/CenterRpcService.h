#pragma once

#include <boost/noncopyable.hpp>
#include "../RPC/ICenterRpcService.h"



class CenterRpcService : boost::noncopyable
{
public:
    //
    ServerAddress   GetGameServerAddress();

    //
    std::string     GetLoginSignature(const std::string& account);

    //
    bool            RegisterGameServer(const std::string& address, int port);

private:
    std::vector<ServerAddress>      gameserver_list_;
};