#pragma once

#include <memory>
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
    bool    Init(const AppConfig& cfg);

    // 释放资源
    void    Release();

    // 运行服务器
    bool    Run();

    MyConnectionPool&   GetConnectionPool() {return conn_pool_;}

private:
    // 配置信息
    AppConfig           config_;

    // mysql连接池
    MyConnectionPool    conn_pool_;

    // RPC 实现
    DBRpcService        rpc_impl_;

    // RPC server
    std::shared_ptr<RCF::RcfServer>     rpc_server_;
};