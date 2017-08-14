#pragma once

#include <unordered_map>
#include "../Utility/Singleton.h"
#include "../RPC/ICenterRpcService.h"
#include "Net/SocketServer.h"
#include "AppConfig.h"



typedef std::shared_ptr<RcfClient<ICenterRpcService>>   RpcClientPtr;

//
// ��¼��
//
class LoginServer : public Singleton<LoginServer>
{
public:
    LoginServer();
    ~LoginServer();

    //���г�ʼ��
    bool    Init();

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

    // ע����Ϣ�ص�
    void    RegisterMsgHandler();

private:
    AppConfig           config_;        // ����
    SocketServer        server_;        // TCP������

    RpcClientPtr        client_;

    typedef std::function<void (CMessage&)>   HandlerType;

    std::unordered_map<int32_t, HandlerType>	handler_map_; //  ���лص�����
};
