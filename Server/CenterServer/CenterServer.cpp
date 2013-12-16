#include "StdAfx.h"
#include "CenterServer.h"
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <RCF/RCF.hpp>
#include <glog/logging.h>



using namespace std;


CenterServer::CenterServer()
{
}

CenterServer::~CenterServer()
{
}

bool CenterServer::Init()
{
    // 读取启动配置文件
    if (!LoadAppConfig(config_))
    {
        LOG(ERROR) << "读取配置错误";
        return false;
    }

    // 初始化RPC服务器
    RCF::TcpEndpoint endpoint(config_.rpc_host, config_.rpc_port);
    rpc_server_.reset(new RCF::RcfServer(endpoint));
    rpc_server_->bind<ICenterRpcService>(rpc_impl_);
    rpc_server_->start();

    LOG(INFO) << "RPC server started at " << config_.rpc_host << ":" << config_.rpc_port;

    return true;
}


void CenterServer::Release()
{
}

bool CenterServer::Run()
{
    using namespace boost::chrono;
    auto start = high_resolution_clock::now();


    auto elapsed = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    if (elapsed.count() < 1)
    {
        boost::this_thread::sleep_for(milliseconds(1));
    }
    
    return true;
}

void CenterServer::Stop()
{
}


