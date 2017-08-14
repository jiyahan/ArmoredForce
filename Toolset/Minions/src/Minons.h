#pragma once

#include <memory>
#include "Net/SocketClient.h"
#include "Server/Utility/Singleton.h"
#include "Config.h"
#include "MessageProcess.h"


// һ��������
class Minions : public Singleton<Minions>
{
public:
    Minions();
    ~Minions();

    // ��ʼ��
    bool    Init(const Config& cfg);

    void    Release();

    // ��ѭ��
    bool    Run();

    SocketClient&  GetClient() {return client_;}

    // �����������������
    bool    ResetConnection(const std::string& host, U16 port);

private:
    // ������Ϣ
    void    ProcessMessage();

private:
    Config          cfg_;
    SocketClient    client_;
    HandlerMap      handler_map_;   //  ��Ϣ·�ɱ�
};

inline Minions&  GetMinions()
{
    return Minions::GetInstance();
}

inline SocketClient& GetTCPClient()
{
    return GetMinions().GetClient();
}