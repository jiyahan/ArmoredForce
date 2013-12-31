#pragma once

#include <RCF/RCF.hpp>
#include "AppConfig.h"
#include "DBRpcService.h"
#include "Singleton.h"
#include "MyConnectionPool.h"

//
// 数据库服务器
//
class DBServer : public Singleton<DBServer>
{
public:
    DBServer();
    ~DBServer();

    // 初始化
    bool    Init();

    // 释放资源
    void    Release();

    // 运行服务器
    bool    Run();

    MyConnectionPool&   GetConnectionPool() {return conn_pool_;}

private:
    AppConfig           config_;
    MyConnectionPool    conn_pool_;
    DBRpcService        rpc_impl_;
    std::shared_ptr<RCF::RcfServer>     rpc_server_;
};