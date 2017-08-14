#pragma once

#include <unordered_map>
#include "../Utility/Singleton.h"
#include "../RPC/ICenterRpcService.h"
#include "Net/SocketServer.h"
#include "AppConfig.h"



typedef std::shared_ptr<RcfClient<ICenterRpcService>>   RpcClientPtr;
typedef std::function<void (CMessage&)>                 HandlerType;
typedef std::unordered_map<int32_t, HandlerType>        HandlerMap;

//
// ��¼��
//
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
    AppConfig           config_;        // ����
    SocketServer        server_;        // TCP������

    RpcClientPtr        client_;

    HandlerMap	        handler_map_; //  ���лص�����
};
