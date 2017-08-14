#pragma once

#include <set>
#include <boost/noncopyable.hpp>
#include "../RPC/ICenterRpcService.h"



class CenterRpcService : boost::noncopyable
{
public:
    // ���һ��GameServer�ĵ�ַ
    bool   GetGameServerAddress(std::string& host, int16_t& port);

    // ���ĳ���˻��ĵ�¼��֤
    std::string     GetLoginSignature(const std::string& account);

    // ע��GameServer
    bool            RegisterGameServer(const std::string& address, int16_t port);

private:
    std::set<std::pair<std::string, int16_t>>      gameserver_list_;
};