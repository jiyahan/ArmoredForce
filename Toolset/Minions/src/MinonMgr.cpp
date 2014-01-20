#include "MinonMgr.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "common/MSGLogin.h"
#include "common/MSGCode.h"
#include "common/MSGGame.h"
#include "MessageProcess.h"
#include "Script/MinionScript.h"
#include "Server/Script/Message.h"

using namespace std;
using namespace atom;
using namespace electron;



//////////////////////////////////////////////////////////////////////////

MinionMgr::MinionMgr(const Config& cfg)
    : cfg_(cfg)
{
    
}

MinionMgr::~MinionMgr()
{
}


// 初始化
bool MinionMgr::Init()
{
    vm_.OpenLibs();

    MinionInit(vm_.GetState());
    
    if (!vm_.DoFile("Minion.lua"))
    {
        return false;
    }
    vm_.Call("OnStartup");
    return true;
}

bool MinionMgr::Run()
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


void MinionMgr::ProcessMessage()
{
    CMessageQueueControllerSetBind messages;
    client_.GetSocketMessage(messages);
    for (CMessage* pMsg : messages)
    {
        //auto commandID = pMsg->GetCommandID();        
        //auto iter = handler_map_.find(commandID);
        //if (iter != handler_map_.end())
        //{
        //    try
        //    {
        //        (iter->second)(*pMsg);
        //    }
        //    catch(std::exception& ex)
        //    {
        //        LOG(ERROR) << ex.what();
        //    }
        //}
        //else
        //{
        //    LOG(WARNING) << "invalid command, " << commandID 
        //        << " from " << pMsg->GetConnector();
        //}
        //CMessageAllocator::GetInstance()->Released( pMsg );
    }
}


//////////////////////////////////////////////////////////////////////////
namespace {

    static std::unique_ptr<MinionMgr>   g_MinionMgr;
}

MinionMgr&  GetMinionMgr() 
{
    return *g_MinionMgr;
}

bool CreateMinionMgr(const Config& cfg)
{
    g_MinionMgr.reset(new MinionMgr(cfg));
    return g_MinionMgr->Init();
}

void DestroyMinionMgr()
{
    g_MinionMgr.reset(nullptr);
}
