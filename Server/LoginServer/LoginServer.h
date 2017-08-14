#pragma once

#include <memory>
#include <tuple>
#include "Singleton.h"
#include "AppConfig.h"
#include "Server/RPC/ILoginRpcService.h"
#include "Net/SocketServer.h"
#include "MsgProcess.h"


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

    SocketServer&   GetTcpServer() { return server_; }

    template <typename T>
    void SendMsg(U64 connector, U32 msgid, const T& data)
    {
        CMessage msg(msgid);
        msg << data;
        server_.Send(connector, msg);
    }    


    //////////////////////////////////////////////////////////////////////////
public:
    const std::string& CreateUserLogSign(const std::string& user);


    //////////////////////////////////////////////////////////////////////////
    //
    // RPC Service
    //
public:
    std::string   GetUserLoginSign(const std::string& user);
    void          DelUserLoginSign(const std::string& user);

private:
    // ������Ϣ
    void    ProcessMessage();


private:
    // ������Ϣ
    AppConfig           config_;
    SocketServer        server_;

    std::shared_ptr<RCF::RcfServer> rpc_server_;
    HandlerMap          handler_map_;         // ��Ϣ·�ɱ�

    std::unordered_map<std::string, std::string>    user_login_sign_;    
};

inline LoginServer& GetApp()
{
    return LoginServer::GetInst();
}
