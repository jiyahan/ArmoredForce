#include "CenterRpcService.h"
#include <glog/logging.h>

using namespace RCF;
using namespace std;


ServerAddress   CenterRpcService::GetGameServerAddress()
{
    if (!gameserver_list_.empty())
    {
        return *gameserver_list_.begin();
    }
    string host = "10.226.34.41";
    int port = 32451;
    return make_pair(host, port);
}

string CenterRpcService::GetLoginSignature(const string& account)
{
    const string signature = "a_quick_fox_jumps_over_the_lazy_dog";
    return signature;
}

bool CenterRpcService::RegisterGameServer(const std::string& host, int port)
{
    LOG(INFO) << "GameServer " << host << ":" << port << " registered.";
    gameserver_list_.push_back(make_pair(host, port));
    return true;
}
