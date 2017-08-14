#pragma once

#include <memory>
#include <boost/noncopyable.hpp>
#include "Net/SocketClient.h"
#include "MessageProcess.h"
#include "Config.h"
#include "Server/Script/LuaVM.h"


// ���л�����
class MinionMgr : boost::noncopyable
{
public:
    explicit MinionMgr(const Config& cfg);
    ~MinionMgr();

    // ��ʼ��
    bool    Init();

    // ��ѭ��
    bool    Run();

private:

    // ������Ϣ
    void    ProcessMessage();

private:
    const Config    cfg_;
    SocketClient    client_;
    LuaVM           vm_;
};


MinionMgr&  GetMinionMgr();

bool CreateMinionMgr(const Config& cfg);

void DestroyMinionMgr();
