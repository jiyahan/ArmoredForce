#pragma once

#include <memory>
#include <boost/noncopyable.hpp>
#include "Net/SocketClient.h"
#include "MessageProcess.h"
#include "Config.h"
#include "Server/Script/LuaVM.h"


// 所有机器人
class MinionMgr : boost::noncopyable
{
public:
    explicit MinionMgr(const Config& cfg);
    ~MinionMgr();

    // 初始化
    bool    Init();

    // 主循环
    bool    Run();

private:

    // 处理消息
    void    ProcessMessage();

private:
    const Config    cfg_;
    SocketClient    client_;
    LuaVM           vm_;
};


MinionMgr&  GetMinionMgr();

bool CreateMinionMgr(const Config& cfg);

void DestroyMinionMgr();
