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

    template <typename T>
    void SendMsg(U64 connector, U32 msgid, const T& data)
    {
        CMessage msg(msgid);
        msg << data;
        server_.Send(connector, msg);
    }

    // �����������
    Random&         GetRandGen() { return rnd_gen_; }

    BattleSys&      GetBattleSys() { return battle_sys_; }

private:

    // ����������Ϣ
    void    ProcessMessage();

private:
    AppConfig           config_;        // ����
    SocketServer        server_;        // TCP������

    RpcClientPtr        rpc_client_;
    
    HandlerMap	        msg_handlers_;

    Random              rnd_gen_;   // ����������� 

    BattleSys           battle_sys_;
};

inline GameServer& GetServer()
{
    return GameServer::GetInst();
}

inline uint32_t  Rand(uint32_t max)
{
    return GetServer().GetRandGen().Uniform(max);
}

inline BattleSys&  GetBattleSys()
{
    return GetServer().GetBattleSys();
}