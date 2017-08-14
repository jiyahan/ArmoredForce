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
LoginServer::LoginServer(const AppConfig& cfg)
    : config_(cfg)
{
}

LoginServer::~LoginServer()
{
    Stop();
}

bool LoginServer::Init()
{
    MyConnectionPool::ConnetionConfig conn_cfg = {};
    conn_cfg.host = config_.mysql_host;
    conn_cfg.port = config_.mysql_port;
    conn_cfg.user = config_.mysql_user;
    conn_cfg.pwd = config_.mysql_pwd;
    conn_cfg.db = config_.mysql_default;
    conn_cfg.charset = config_.mysql_charset;
    conn_cfg.max_pool_size = config_.connection_pool_size;
    conn_cfg.max_idle_time = config_.max_idle_time;

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
    server_.Stop();
}

tuple<string, string> LoginServer::CreatePassword(const std::string& plain)
{
    string salt = pbkdf2_.CreateSalt();
    string pwd = pbkdf2_.CreateStrongPassword(plain, salt);
    return make_tuple(move(pwd), move(salt));
}

// ����������Ϣ
void LoginServer::ProcessMessage()
{   
    CMessageQueueControllerSetBind messages = server_.GetSocketMessage();
    for(auto pMsg : messages)
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

