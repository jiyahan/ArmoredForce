#pragma once

#include <memory>
#include <RCF/RCF.hpp>
#include "AppConfig.h"
#include "Net/SocketServer.h"
#include "Server/Utility/Singleton.h"
#include "Server/Utility/Random.h"
#include "Server/RPC/ICenterRpcService.h"
#include "MsgProcess.h"
#include "common/setup/ArmyCategory.h"
#include "common/setup/MonsterList.h"
#include "common/setup/OfficerList.h"
#include "common/setup/RegionList.h"

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
    bool    Init(const AppConfig& cfg);

    // �ͷ���Դ
    void    Release();

    // ���з�����
    bool    Run();

    // ֹͣ������
    void    Stop();

    SocketServer&   GetSocketServer() {return server_;}

    RpcClientPtr    GetClient() { return client_;}

    Random&     GetRandGen() {return rnd_gen_;}

private:

    // ����������Ϣ
    void    ProcessMessage();

    void	RegisterMsgHandler();

private:
    AppConfig           config_;        // ����
    SocketServer        server_;        // TCP������

    RpcClientPtr        client_;
    
    HandlerMap	        msg_handlers_;

    Random              rnd_gen_;   // ����������� 
};

inline GameServer& GetServer()
{
    return GameServer::GetInstance();
}

inline RpcClientPtr GetRpcClientPtr()
{
    return GetServer().GetClient();
}

inline SocketServer& GetTCPServer()
{
    return GetServer().GetSocketServer();
}

inline uint32_t  Random(uint32_t max)
{
    return GetServer().GetRandGen().Uniform(max);
}
