#pragma once

#include <unordered_map>
#include <RCF/RCF.hpp>
#include "AppConfig.h"
#include "Singleton.h"
#include "../RPC/ICenterRpcService.h"
#include "../RPC/ILoginRpcService.h"

typedef std::set<std::pair<std::string, int32_t>>   GameServerList;

//
// ���ķ�����
//
class CenterServer : public Singleton<CenterServer>
{
public:
    CenterServer();
    ~CenterServer();

    //��ʼ��
    bool    Init(const AppConfig& cfg);

    // �ͷ���Դ
    void    Release();

    // ���з�����
    bool    Run();

    // ֹͣ������
    void    Stop();

    //////////////////////////////////////////////////////////////////////////
    // RPC Service
    //
public:
    // ���һ��GameServer�ĵ�ַ
    bool   GetGameServerAddress(std::string& host, int16_t& port);

    // ���ĳ���˻��ĵ�¼��֤
    std::string     GetUserLoginSign(const std::string& account);

    // ע��GameServer
    bool            RegisterGameServer(const std::string& address, int16_t port);

private:
    AppConfig           config_;        // ����    
    RCF::RcfServer      rpc_server_;
    //RCF::RcfClient<ILoginRpcService>      rpc_client_;
    GameServerList      gameserver_list_;
};
