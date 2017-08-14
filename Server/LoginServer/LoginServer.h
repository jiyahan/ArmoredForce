#pragma once

#include <memory>
#include <tuple>
#include "Singleton.h"
#include "AppConfig.h"
#include "Server/RPC/ICenterRpcService.h"
#include "Net/SocketServer.h"
#include "MsgProcess.h"
#include "MyConnectionPool.h"
#include "pbkdf2.h"


typedef std::shared_ptr<RcfClient<ICenterRpcService>>   RpcClientPtr;
 

class LoginServer : public Singleton<LoginServer>
{
public:
    explicit LoginServer(const AppConfig& cfg);
    ~LoginServer();

    //���г�ʼ��
    bool    Init();

    // ���з�����
    bool    Run();

    // ֹͣ������
    void    Stop();

    const AppConfig& GetConfig() { return config_; }

    RpcClientPtr    GetClient() { return client_; }

    SocketServer&   GetTcpServer() { return server_; }

    template <typename T>
    void SendMsg(U64 connector, U32 msgid, const T& data)
    {
        CMessage msg(msgid);
        msg << data;
        server_.Send(connector, msg);
    }

    MyConnectionPoolPtr GetConnectionPool() {return conn_pool_;}

    std::tuple<std::string, std::string>    CreatePassword(const std::string& plain);

private:
    // ������Ϣ
    void    ProcessMessage();


private:
    // ������Ϣ
    AppConfig           config_;

    // TCP������
    SocketServer        server_;

    // RPC�ͻ���
    RpcClientPtr        client_;

    // ��Ϣ·�ɱ�
    HandlerMap          handler_map_;

    MyConnectionPoolPtr conn_pool_;

    PBKDF2              pbkdf2_;
};

inline LoginServer& GetApp()
{
    return LoginServer::GetInst();
}

inline RpcClientPtr GetRpcClientPtr()
{
    return GetApp().GetClient();
}

inline MyConnectionPoolPtr GetConnectionPoolPtr()
{
    return GetApp().GetConnectionPool();
}
