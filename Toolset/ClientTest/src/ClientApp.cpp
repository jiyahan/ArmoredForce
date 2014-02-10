#include "ClientApp.h"
#include <chrono>
#include <thread>
#include "MessageProcess.h"


using namespace std;
using namespace atom;
using namespace electron;


//////////////////////////////////////////////////////////////////////////
ClientApp::ClientApp(const Config& cfg)
    : cfg_(cfg)
{
}

ClientApp::~ClientApp()
{
}

bool ClientApp::Init()
{
    handler_map_ = GetHandlerMap();

    // 开始连接server
    if (client_.Start(cfg_.host, cfg_.port))
    {
        OnConnectLS();
    }
    else
    {
        LOG(ERROR) << "连接服务器失败, " << cfg_.host << ":" << cfg_.port;
        return false;
    }
    return true;
}

bool ClientApp::Run()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    // 处理网络消息
    ProcessMessage();

    auto elapsed = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    if (elapsed.count() < 1)
    {
        std::this_thread::sleep_for(milliseconds(10));
    }
    return true;
}

bool ClientApp::ResetConnection(const std::string& host, U16 port)
{
    return client_.ResetConnection(host, port);
}


void ClientApp::ProcessMessage()
{
    CMessageQueueControllerSetBind messages = client_.GetSocketMessage();
    for (auto pMsg : messages)
    {
        auto commandID = pMsg->GetCommandID();        
        auto iter = handler_map_.find(commandID);
        if (iter != handler_map_.end())
        {
            try
            {
                (iter->second)(*pMsg);
            }
            catch(std::exception& ex)
            {
                LOG(ERROR) << ex.what();
            }
        }
        else
        {
            LOG(WARNING) << "invalid command, " << commandID 
                << " from " << pMsg->GetConnector();
        }
        CMessageAllocator::GetInstance()->Released( pMsg );
    }
}

