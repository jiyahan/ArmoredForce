#include "stdafx.h"
#include "GameServer.h"
#include <chrono>
#include <thread>
#include "MsgProcess.h"
#include "ScopeGuard.h"
#include "Server/Setup/LoadSetup.h"


using namespace std;
using namespace electron;


GameServer::GameServer()
{
}

GameServer::~GameServer()
{
}

bool GameServer::Init(const AppConfig& cfg)
{    
    config_ = cfg;

    setup::ArmyCategorySetup::CreateInstance();
    setup::OfficerListSetup::CreateInstance();
    setup::RegionListSetup::CreateInstance();
    setup::MonsterListSetup::CreateInstance();
    CHECK(setup::ArmyCategorySetup::GetInstance()->Load("data/ArmyCategory.xml.bin"));
    CHECK(setup::OfficerListSetup::GetInstance()->Load("data/OfficerList.xml.bin"));
    CHECK(setup::RegionListSetup::GetInstance()->Load("data/RegionList.xml.bin"));
    CHECK(setup::MonsterListSetup::GetInstance()->Load("data/MonsterList.xml.bin"));

    // 开始网络服务器	
    CHECK(server_.Start(config_.host, config_.port))
        << "初始化TCP服务器失败! IP:" << config_.host << ",端口:" << config_.port;

    LOG(INFO) << "TCP服务器开始监听 " << config_.host << ":" << config_.port;

    RCF::TcpEndpoint remoteEndPoint(config_.rpc_center_host, config_.rpc_center_port);
    client_.reset(new RcfClient<ICenterRpcService>(remoteEndPoint));
    bool status = client_->RegisterGameServer(config_.host, config_.port);

    // 注册客户端消息回调处理函数
    msg_handlers_ = GetHandlerMap();

    LOG(INFO) << "GameServer初始化成功.";

    return true;
}

bool GameServer::Run()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

	ProcessMessage();

    auto elapsed = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    if (elapsed.count() < 1)
    {
        std::this_thread::sleep_for(milliseconds(1));
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
    for(CMessage* pMsg : messages)
    {
        U32 command_id = pMsg->GetCommandID();
        auto iter = msg_handlers_.find(command_id);
        if (iter != msg_handlers_.end())
        {
            try
            {
                (iter->second)(*pMsg);
            }
            catch(exception& ex)
            {
                LOG(ERROR) << "command id: " << command_id << "\t" << ex.what();
            }
        }

        CMessageAllocator::GetInstance()->Released( pMsg );
    }
}

