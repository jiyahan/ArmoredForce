#include "LoginServer.h"
#include <chrono>
#include <thread>
#include <easylogging++.h>
#include <RCF/RCF.hpp>
#include "Server/RPC/ICenterRpcService.h"
#include "MsgProcess.h"
#include "Utility.h"
#include "DB/DBLogin.h"

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
    DBLogin::Init(config_.mysql_host, 
        config_.mysql_port, 
        config_.mysql_user,
        config_.mysql_pwd, 
        config_.mysql_default, 
        config_.mysql_charset, 
        config_.connection_pool_size, 
        config_.max_idle_time);

    // ��ʼ���������	
    CHECK(server_.Start(config_.host, config_.port))
        << "��ʼ��TCP������ʧ��! IP:" << config_.host << ",�˿�:" << config_.port;

    LOG(INFO) << "TCP��������ʼ����" << config_.host << ":" << config_.port;

    RCF::TcpEndpoint endpoint(config_.rpc_host, config_.rpc_port);
    rpc_server_.reset(new RCF::RcfServer(endpoint));
    rpc_server_->bind<ILoginRpcService>(*this);
    rpc_server_->start();

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

const string& LoginServer::CreateUserLogSign(const string& user)
{
    DCHECK(user_login_sign_.count(user) == 0);
    user_login_sign_[user] = CreateUniqueID();
    return user_login_sign_[user];
}

void LoginServer::DelUserLoginSign(const string& user)
{
    DCHECK(user_login_sign_.count(user));
    user_login_sign_.erase(user);
}

std::string LoginServer::GetUserLoginSign(const string& user)
{
    static const string dummy = "";
    auto iter = user_login_sign_.find(user);
    if (iter != user_login_sign_.end())
    {
        return iter->second;
    }
    return dummy;
}
