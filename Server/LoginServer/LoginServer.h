#pragma once

#include <memory>
#include "Singleton.h"
#include "AppConfig.h"
#include "Server/RPC/ICenterRpcService.h"
#include "Net/SocketServer.h"
#include "MsgProcess.h"



typedef std::shared_ptr<RcfClient<ICenterRpcService>>   RpcClientPtr;

class LoginServer : public Singleton<LoginServer>
{
public:
    LoginServer();
    ~LoginServer();

    //���г�ʼ��
    bool    Init(const AppConfig& cfg);

    // �ͷ��������Դ
    void    Release();

    // ���з�����
    bool    Run();

    // ֹͣ������
    void    Stop();

    SocketServer& GetSocketServer() { return server_; }

    const AppConfig& GetConfig() {return config_;}

    RpcClientPtr    GetClient() {return client_;}

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
};

inline LoginServer& GetServer()
{
    return LoginServer::GetInstance();
}

inline RpcClientPtr GetRpcClientPtr()
{
    return GetServer().GetClient();
}

inline SocketServer& GetTCPServer()
{
    return GetServer().GetSocketServer();
}
