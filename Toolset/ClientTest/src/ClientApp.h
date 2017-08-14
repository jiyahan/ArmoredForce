#pragma once

#include <memory>
#include <boost/noncopyable.hpp>
#include "Net/SocketClient.h"
#include "MessageProcess.h"
#include "Config.h"

class ClientApp;
ClientApp&  GetClientApp();
bool        CreateClientApp(const Config& cfg);
void        DestroyClientApp();

class ClientApp : boost::noncopyable
{
public:
    explicit ClientApp(const Config& cfg);
    ~ClientApp();

    // ��ѭ��
    bool    Run();

    // �����������������
    bool    ResetConnection(const std::string& host, U16 port);

    SocketClient& GetTcpClient() { return client_;}

private:

    // ������Ϣ
    void    ProcessMessage();

private:
    const Config    cfg_;
    SocketClient    client_;
    HandlerMap      handler_map_;   //  ��Ϣ·�ɱ�
};



//////////////////////////////////////////////////////////////////////////

inline SocketClient& GetTcpClient()
{
    return GetClientApp().GetTcpClient();
}
