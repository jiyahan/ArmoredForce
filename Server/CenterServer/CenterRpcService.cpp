#include "StdAfx.h"
#include "CenterRpcService.h"
#include <glog/logging.h>

using namespace RCF;
using namespace std;


ServerAddress   CenterRpcService::GetGameServerAddress()
{
    string host = "10.226.34.41";
    int port = 32451;
    return make_pair(host, port);
}

string CenterRpcService::GetLoginSignature(const string& account)
{
    string signature = "a_quick_fox_jumps_over_the_lazy_dog";
    return signature;
}

bool CenterRpcService::RegisterGameServer(const std::string& host, int port)
{
    LOG(INFO) << "GameServer " << host << ":" << port << " registered.";
    return true;
}
