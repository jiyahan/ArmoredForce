#include "Minons.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "common/MSGLogin.h"
#include "common/MSGCode.h"
#include "common/MSGGame.h"
#include "MessageProcess.h"

using namespace std;
using namespace atom;
using namespace electron;


//////////////////////////////////////////////////////////////////////////

Minions::Minions()
{
}

Minions::~Minions()
{
}


// 初始化
bool Minions::Init(const Config& cfg)
{
    cfg_ = cfg;

    handler_map_ = GetHandlerMap();

    // 开始连接server
    if (client_.Start(cfg_.host, cfg_.port))
    {
        LOG(INFO) << "连接服务器成功, 发送登录请求...";
        MSGLoginVersionVerify verify_request = {};
        client_.Send(MID_VERSION_VERIFY, verify_request);
    }
    else
    {
        LOG(ERROR) << "连接服务器失败, " << cfg.host << ":" << cfg.port;
        return false;
    }
    return true;
}

void Minions::Release()
{
}


bool Minions::Run()
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

bool Minions::ResetConnection(const std::string& host, U16 port)
{
    return client_.ResetConnection(host, port);
}

void Minions::ProcessMessage()
{
    CMessageQueueControllerSetBind messages;
    client_.GetSocketMessage(messages);
    for (CMessage* pMsg : messages)
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
