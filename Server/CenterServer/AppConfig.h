#pragma once

#include <cstdint>
#include <string>



struct AppConfig
{
    std::string     rpc_host;        // 监听的IP
    int32_t         rpc_port;        // 监听的端口

    std::string     rpc_db_host;      // DBServer地址
    int32_t         rpc_db_port;      // DBServer的端口

    int32_t         pool_size;
    int32_t         thread_num;
};


AppConfig    LoadAppConfig(const std::string& path);

