#pragma once

#include <memory>
#include <RCF/RCF.hpp>
#include "AppConfig.h"
#include "Net/SocketServer.h"
#include "Singleton.h"
#include "Random.h"
#include "Server/RPC/ICenterRpcService.h"
#include "MsgProcess.h"
#include "App/BattleSys.h"


typedef std::shared_ptr<RcfClient<ICenterRpcService>>   RpcClientPtr;


class GameServer : public Singleton<GameServer>
{
public:
    GameServer();
    ~GameServer();

    //��ʼ��
    bool    Init(const AppConfig& cfg);

    // �ͷ���Դ
    void    Release();

    // ���з�����
    bool    Run();

    // ֹͣ������
    void    Stop();

    // TCP����
    SocketServer&   GetSocketServer() {return server_;}

    // RPC�ͻ���
    RpcClientPtr    GetClient() { return client_;}

    // �����������
    Random&         GetRandGen() { return rnd_gen_; }

    BattleSys&      GetBattleSys() { return battle_sys_; }

private:

    // ����������Ϣ
    void    ProcessMessage();

private:
    AppConfig           config_;        // ����
    SocketServer        server_;        // TCP������

    RpcClientPtr        client_;
    
    HandlerMap	        msg_handlers_;

    Random              rnd_gen_;   // ����������� 

    BattleSys           battle_sys_;
};

inline GameServer& GetServer()
{
    return GameServer::GetInst();
}

inline RpcClientPtr GetRpcClientPtr()
{
    return GetServer().GetClient();
}

inline SocketServer& GetTCPServer()
{
    return GetServer().GetSocketServer();
}

inline uint32_t  Rand(uint32_t max)
{
    return GetServer().GetRandGen().Uniform(max);
}

inline BattleSys&  GetBattleSys()
{
    return GetServer().GetBattleSys();
}