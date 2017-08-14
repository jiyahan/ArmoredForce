#include "stdafx.h"
#include "GameServer.h"
#include <chrono>
#include <thread>
#include "MsgProcess.h"
#include "ScopeGuard.h"

using namespace std;


GameServer::GameServer()
{
}

GameServer::~GameServer()
{
}

bool GameServer::Init(const AppConfig& cfg)
{
    config_ = cfg;

    // ��ʼ���������	
    CHECK(server_.Start(config_.host.c_str(),config_.port))
        << "��ʼ��TCP������ʧ��! IP:" << config_.host << ",�˿�:" << config_.port;

    LOG(INFO) << "TCP��������ʼ���� " << config_.host << ":" << config_.port;

    RCF::TcpEndpoint remoteEndPoint(config_.rpc_center_host, config_.rpc_center_port);
    client_.reset(new RcfClient<ICenterRpcService>(remoteEndPoint));
    SCOPE_FAIL{cout << "OK";};
    bool status = client_->RegisterGameServer(config_.host, config_.port);

    // ע��ͻ�����Ϣ�ص�������
    handler_map_ = GetHandlerMap();

    LOG(INFO) << "GameServer��ʼ���ɹ�.";

    return true;
}


void GameServer::Release()
{

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

// ����������Ϣ
void GameServer::ProcessMessage()
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
            catch(exception& ex)
            {
                LOG(ERROR) << "command id: " << command_id << "\t" << ex.what();
            }
        }

        CMessageAllocator::GetInstance()->Released( pMsg );
    }
}

