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

    // ��ʼ���������	
    CHECK(server_.Start(config_.host, config_.port))
        << "��ʼ��TCP������ʧ��! IP:" << config_.host << ",�˿�:" << config_.port;

    LOG(INFO) << "TCP��������ʼ����" << config_.host << ":" << config_.port;

    RCF::TcpEndpoint remoteEndPoint(config_.rpc_host, config_.rpc_port);
    client_ = make_shared<RcfClient<ICenterRpcService>>(remoteEndPoint);

    // ע��ͻ�����Ϣ�ص�������
    handler_map_ = GetMsgHandlers();

    LOG(INFO) << "LoginServer��ʼ���ɹ�";

    return true;
}


void LoginServer::Release()
{
}

bool LoginServer::Run()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    // ����������Ϣ
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


// ����������Ϣ
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

