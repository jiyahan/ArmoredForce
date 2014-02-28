#include "CenterServer.h"
#include <thread>
#include <chrono>
#include <RCF/RCF.hpp>
#include <easylogging++.h>

using namespace std;


CenterServer::CenterServer()
{
}

CenterServer::~CenterServer()
{
    Release();
}

bool CenterServer::Init(const AppConfig& cfg)
{
    config_ = cfg;

    RCF::TcpEndpoint remoteEndPoint(config_.rpc_login_host, config_.rpc_login_port);
    rpc_client_.reset(new RcfClient<ILoginRpcService>(remoteEndPoint));
#ifdef _DEBUG
    rpc_client_->getClientStub().setRemoteCallTimeoutMs(120 * 1000);
#endif

    // 初始化RPC服务器
    RCF::TcpEndpoint endpoint(config_.rpc_host, config_.rpc_port);
    rpc_server_.addEndpoint(endpoint);
    rpc_server_.bind<ICenterRpcService>(*this);
    rpc_server_.start();

    LOG(INFO) << "RPC server started at " << config_.rpc_host << ":" << config_.rpc_port;

    return true;
}


void CenterServer::Release()
{
}

bool CenterServer::Run()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    //

    auto elapsed = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    if (elapsed.count() < 1)
    {
        this_thread::sleep_for(milliseconds(1));
    }
    
    return true;
}


bool  CenterServer::GetGameServerAddress(string& host, int16_t& port)
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

string CenterServer::GetUserLoginSign(const string& account)
{
    return rpc_client_->GetUserLoginSign(account);
}

bool CenterServer::RegisterGameServer(const string& host, int16_t port)
{
    gameserver_list_.emplace(make_pair(host, port));
    LOG(INFO) << "GameServer " << host << ":" << port << " registered.";

    rpc_client_->PutGameAddress("Thunder", "full", host, port);

    return true;
}


