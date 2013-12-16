#include "StdAfx.h"
#include "GameServer.h"
#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include "MsgProcess.h"
#include "../../common/MESSAGE_ID.h"

using namespace std;


GameServer::GameServer()
{
}

GameServer::~GameServer()
{
}

bool GameServer::Init()
{
    // 读取启动配置文件
    if (!LoadAppConfig(config_))
    {
        LOG(ERROR) << "读取配置错误";
        return false;
    }

    // 初始化TCP网络服务器框架
    CAtom::Presetup();
    CElectron::Presetup();
    if (!CAtom::Initiate(config_.pool_size))
    {
        LOG(ERROR) << "初始化atom错误";
        return false;
    }
    if (!CElectron::Initiate(config_.thread_num))
    {
        LOG(ERROR) << "初始化electron错误";
        return false;
    }

    // 开始网络服务器	
    if (!server_.Start(config_.host.c_str(),config_.port))
    {
        LOG(ERROR) << "初始化TCP服务器失败! IP:" << config_.host 
            << ",端口:" << config_.port;
        return false;
    }
    LOG(INFO) << "TCP服务器开始监听" << config_.host << ":" << config_.port;

    RCF::TcpEndpoint remoteEndPoint(config_.rpc_center_host, config_.rpc_center_port);
    client_.reset(new RcfClient<ICenterRpcService>(remoteEndPoint));

    bool status = client_->RegisterGameServer(config_.host, config_.port);

    // 注册客户端消息回调处理函数
    RegisterMsgHandler();

    LOG(INFO) << "GameServer初始化成功";

    return true;
}


void GameServer::Release()
{
    CElectron::Shutdown();
    CAtom::Shutdown();
    CElectron::Destruct();
    CAtom::Destruct();
}

bool GameServer::Run()
{
    using namespace boost::chrono;
    auto start = high_resolution_clock::now();

	ProcessMessage();

    auto elapsed = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    if (elapsed.count() < 1)
    {
        boost::this_thread::sleep_for(milliseconds(1));
    }

    return true;
}

void GameServer::Stop()
{

}

// 处理网络消息
void GameServer::ProcessMessage()
{
    CMessageQueueControllerSetBind messages;
    server_.GetSocketMessage(messages);
    std::for_each(messages.begin(), messages.end(), [this](CMessage* pMsg)
    {
        U32 command_id = pMsg->GetCommandID();
        cout << "command id: " << command_id << endl;
        auto iter = handler_map_.find(command_id);
        if (iter != handler_map_.end())
        {
            try
            {
                (iter->second)(*pMsg);
            }
            catch(exception& ex)
            {
                LOG(ERROR) << "command id: " << command_id
                    << "\t" << ex.what();
            }
        }
        CMessageAllocator::GetInstance()->Released( pMsg );
    });
}


void GameServer::RegisterMsgHandler()
{
    handler_map_[MID_ACCOUNT_AUTHORIZE_REQUEST] = HandleUserAuth;
}