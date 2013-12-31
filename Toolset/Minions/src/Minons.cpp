#include "Minons.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <glog/logging.h>
#include "../../common/MSGLogin.h"
#include "../../common/MSGCode.h"
#include "../../common/MSGGame.h"
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
        MSGLoginVersionVerify verify_request = {};
        client_.Send(MID_VERSION_VERIFY, verify_request);
    }
    else
    {
        LOG(ERROR) << "Failed to connect server: " << cfg.host << " :" << cfg.port;
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
        cout << "command:" << commandID << ",\tsession id: " << pMsg->GetConnector() << endl;
        auto iter = handler_map_.find(commandID);
        if (iter != handler_map_.end())
        {
            try
            {
                (iter->second)(*pMsg);
            }
            catch(std::exception& ex)
            {
                cout << ex.what() << endl;
            }
        }
        else
        {
            cout << "invalid command.\n";
        }
        CMessageAllocator::GetInstance()->Released( pMsg );
    }
}
