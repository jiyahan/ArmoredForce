#include "StdAfx.h"
#include "DBServer.h"
#include <iostream>
#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include "DB/ConnectionPool.h"


using namespace std;



DBServer::DBServer()
{
}

DBServer::~DBServer()
{
}

bool DBServer::Init()
{
    // 读取启动配置文件
    if (!LoadAppConfig(config_))
    {
        LOG(ERROR) << "读取配置错误";
        return false;
    }

    MyConnectionPool::ConnetionConfig conn_cfg = {};
    conn_cfg.host = config_.mysql_host;
    conn_cfg.port = config_.mysql_port;
    conn_cfg.user = config_.mysql_user;
    conn_cfg.pwd = config_.mysql_pwd;
    conn_cfg.db = config_.mysql_default;
    conn_cfg.charset = config_.mysql_charset;
    conn_cfg.max_pool_size = config_.connection_pool_size;
    conn_cfg.max_idle_time = config_.max_idle_time;

    if (!MyConnectionPool::GetInstance().init(conn_cfg))
    {
        LOG(ERROR) << "初始化mysql连接错误";
        return false;
    }

    // 初始化RPC服务器
    RCF::TcpEndpoint endpoint(config_.rpc_host, config_.rpc_port);
    rpc_server_.reset(new RCF::RcfServer(endpoint));
    rpc_server_->bind<IDBRpcService>(rpc_impl_);
    rpc_server_->start();

    LOG(INFO) << "服务器初始化成功.";
    return true;
}


void DBServer::Release()
{
}


bool DBServer::Run()
{
    using namespace boost::chrono;
    auto start = high_resolution_clock::now();

    // do things here

    auto elapsed = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    if (elapsed.count() < 1)
    {
        boost::this_thread::sleep_for(milliseconds(1));
    }

    return true;
}

