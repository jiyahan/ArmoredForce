#include "DBServer.h"
#include <iostream>
#include <chrono>
#include <thread>


using namespace std;


DBServer::DBServer()
{
}

DBServer::~DBServer()
{
}

bool DBServer::Init(const AppConfig& cfg)
{
    config_ = cfg;

    MyConnectionPool::ConnetionConfig conn_cfg = {};
    conn_cfg.host = config_.mysql_host;
    conn_cfg.port = config_.mysql_port;
    conn_cfg.user = config_.mysql_user;
    conn_cfg.pwd = config_.mysql_pwd;
    conn_cfg.db = config_.mysql_default;
    conn_cfg.charset = config_.mysql_charset;
    conn_cfg.max_pool_size = config_.connection_pool_size;
    conn_cfg.max_idle_time = config_.max_idle_time;
    conn_pool_.reset(new MyConnectionPool(conn_cfg));

    // 初始化RPC服务器
    RCF::TcpEndpoint endpoint(config_.rpc_host, config_.rpc_port);
    rpc_server_.reset(new RCF::RcfServer(endpoint));
    rpc_server_->bind<IDBRpcService>(rpc_impl_);
    rpc_server_->start();

    LOG(INFO) << "服务器初始化成功.";
    return true;
}


bool DBServer::Run()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    // do things here

    auto elapsed = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    if (elapsed.count() < 1)
    {
        std::this_thread::sleep_for(milliseconds(1));
    }

    return true;
}

