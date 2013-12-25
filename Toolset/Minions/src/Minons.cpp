#include "StdAfx.h"
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


Minions::Minions()
{
}

Minions::~Minions()
{
}

bool Minions::Init()
{
    handler_map_ = GetHandlerMap();

    if (client_.Start("127.0.0.1", 32450))
    {
        MSGLoginVersionVerify verify_request;
        verify_request.major = 10;
        verify_request.minor = 21;
        client_.Send(MID_VERSION_VERIFY, verify_request);
    }
    else
    {
        LOG(ERROR) << "Connection failed.";
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
        std::this_thread::sleep_for(milliseconds(1));
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
        int32_t commandID = pMsg->GetCommandID();
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


