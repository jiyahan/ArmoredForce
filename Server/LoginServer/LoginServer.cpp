#include "LoginServer.h"
#include <chrono>
#include <thread>
#include <easylogging++.h>
#include <RCF/RCF.hpp>
#include "Server/RPC/ICenterRpcService.h"
#include "MsgProcess.h"


using namespace std;
using namespace atom;
using namespace electron;



//////////////////////////////////////////////////////////////////////////
LoginServer::LoginServer()
{
}

LoginServer::~LoginServer()
{
}

bool LoginServer::Init(const AppConfig& cfg)
{
    config_ = cfg;

    MyConnectionPool::ConnetionConfig conn_cfg = {};
    conn_cfg.host = cfg.mysql_host;
    conn_cfg.port = cfg.mysql_port;
    conn_cfg.user = cfg.mysql_user;
    conn_cfg.pwd = cfg.mysql_pwd;
    conn_cfg.db = cfg.mysql_default;
    conn_cfg.charset = cfg.mysql_charset;
    conn_cfg.max_pool_size = cfg.connection_pool_size;
    conn_cfg.max_idle_time = cfg.max_idle_time;

    conn_pool_ = make_shared<MyConnectionPool>(conn_cfg);

    // 开始网络服务器	
    CHECK(server_.Start(config_.host, config_.port))
        << "初始化TCP服务器失败! IP:" << config_.host << ",端口:" << config_.port;

    LOG(INFO) << "TCP服务器开始监听" << config_.host << ":" << config_.port;

    RCF::TcpEndpoint remoteEndPoint(config_.rpc_host, config_.rpc_port);
    client_ = make_shared<RcfClient<ICenterRpcService>>(remoteEndPoint);

    // 注册客户端消息回调处理函数
    handler_map_ = GetMsgHandlers();

    LOG(INFO) << "LoginServer初始化成功";

    return true;
}


void LoginServer::Release()
{
}

bool LoginServer::Run()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    // 处理网络消息
    ProcessMessage();

    auto elapsed = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    if (elapsed.count() < 1)
    {
        this_thread::sleep_for(milliseconds(10));
    }

    return true;
}

void LoginServer::Stop()
{
    server_.Close();
}


// 处理网络消息
void LoginServer::ProcessMessage()
{
    CMessageQueueControllerSetBind messages;
    server_.GetSocketMessage(messages);
    for(CMessage* pMsg : messages)
    {
        U32 command_id = pMsg->GetCommandID();
        auto iter = handler_map_.find(command_id);
        if (iter != handler_map_.end())
        {
            try
            {
                (iter->second)(*pMsg);
            }
            catch(std::exception& ex)
            {
                LOG(ERROR) << "command id: " << command_id << "\t" << ex.what();
            }
        }

        CMessageAllocator::GetInstance()->Released( pMsg );
    }
}

