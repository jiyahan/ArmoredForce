#include "StdAfx.h"
#include "Minons.h"
#include <iostream>
#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include "../../common/MSGLogin.h"
#include "../../common/MSGCode.h"
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
    CAtom::Presetup();
    CElectron::Presetup();
    if (!CAtom::Initiate(128 * 1024))
    {
        return false;
    }
    if (!CElectron::Initiate( 1 ))
    {
        return false;
    }

    RegisterMessageHandler();

    if (client_.Start("10.226.34.41", 32450))
    {
        MSGLoginVersionVerify verify_request;
        verify_request.major = 10;
        verify_request.minor = 21;
        client_.Send(MID_VERSION_VERIFY, verify_request);
    }
    return true;
}

void Minions::Release()
{
    CElectron::Shutdown();
    CAtom::Shutdown();
    CElectron::Destruct();
    CAtom::Destruct();
}

bool Minions::Run()
{
    using namespace boost::chrono;
    auto start = high_resolution_clock::now();

    // 处理网络消息
    ProcessMessage();

    auto elapsed = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    if (elapsed.count() < 1)
    {
        boost::this_thread::sleep_for(milliseconds(1));
    }
    return true;
}


void Minions::ProcessMessage()
{
    CMessageQueueControllerSetBind messages;
    client_.GetSocketMessage(messages);
    for (auto iter = messages.begin(); iter != messages.end(); ++iter)
    {
        CMessage* pMsg = *iter;
        int32_t commandID = pMsg->GetCommandID();
        cout << "command:" << commandID << ",\tsession id: " << pMsg->GetConnector() << endl;
        auto handler = handler_map_.find(commandID);
        if (handler != handler_map_.end())
        {
            (handler->second)(*pMsg);
        }
        else
        {
            cout << "invalid command.\n";
        }
        CMessageAllocator::GetInstance()->Released( pMsg );
    }
}

void    Minions::RegisterMessageHandler()
{
    handler_map_[MID_LOGIN_LOGINRESPONSE] = HandleLoginResponse;
    handler_map_[MID_VERSION_VERIFYRESPONSE] = HandleVerifyResponse;
}
