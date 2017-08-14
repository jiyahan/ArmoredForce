#pragma once

#include <memory>
#include <RCF/RCF.hpp>
#include "AppConfig.h"
#include "DBRpcService.h"
#include "Singleton.h"
#include "MyConnectionPool.h"

//
// ���ݿ������
//
class DBServer : public Singleton<DBServer>
{
public:
    DBServer();
    ~DBServer();

    // ��ʼ��
    bool    Init(const AppConfig& cfg);

    // �ͷ���Դ
    void    Release();

    // ���з�����
    bool    Run();

    MyConnectionPool&   GetConnectionPool() {return conn_pool_;}

private:
    // ������Ϣ
    AppConfig           config_;

    // mysql���ӳ�
    MyConnectionPool    conn_pool_;

    // RPC ʵ��
    DBRpcService        rpc_impl_;

    // RPC server
    std::shared_ptr<RCF::RcfServer>     rpc_server_;
};