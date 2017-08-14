#pragma once

#include <memory>
#include <unordered_map>
#include <RCF/RCF.hpp>
#include "AppConfig.h"
#include "Net/SocketServer.h"
#include "../Utility/Singleton.h"
#include "../RPC/ICenterRpcService.h"


typedef std::shared_ptr<RcfClient<ICenterRpcService>>   RpcClientPtr;

//
// ��Ϸ��
//
class GameServer : public Singleton<GameServer>
{
public:
    GameServer();
    ~GameServer();

    //��ʼ��
    bool    Init();

    // �ͷ���Դ
    void    Release();

    // ���з�����
    bool    Run();

    // ֹͣ������
    void    Stop();

    SocketServer&   GetSocketServer() {return server_;}

    RpcClientPtr    GetClient() { return client_;}

private:

    // ����������Ϣ
    void    ProcessMessage();

    void	RegisterMsgHandler();

private:
    AppConfig           config_;        // ����
    SocketServer        server_;        // TCP������

    RpcClientPtr        client_;

    typedef std::function<void (CMessage&)>		HandlerType;

    std::unordered_map<int32_t, HandlerType>	handler_map_;
};
