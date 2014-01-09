#include "CenterRpcService.h"
#include <easylogging++.h>

using namespace std;



bool  CenterRpcService::GetGameServerAddress(string& host, int16_t& port)
{
    if (!gameserver_list_.empty())
    {
        const auto& item = *gameserver_list_.begin();
        host = item.first;
        port = item.second;
        return true;
    }
    LOG(WARNING) << "No registered GameServer found.";
    return false;
}

string CenterRpcService::GetLoginSignature(const string& account)
{
    const string& signature = "a_quick_fox_jumps_over_the_lazy_dog";
    return signature;
}

bool CenterRpcService::RegisterGameServer(const string& host, int16_t port)
{
    gameserver_list_.emplace(make_pair(host, port));
    LOG(INFO) << "GameServer " << host << ":" << port << " registered.";
    
    return true;
}
