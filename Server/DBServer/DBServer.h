#pragma once

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
    bool    Init();

    // �ͷ���Դ
    void    Release();

    // ���з�����
    bool    Run();

    MyConnectionPool&   GetConnectionPool() {return conn_pool_;}

private:
    AppConfig           config_;
    MyConnectionPool    conn_pool_;
    DBRpcService        rpc_impl_;
    std::shared_ptr<RCF::RcfServer>     rpc_server_;
};