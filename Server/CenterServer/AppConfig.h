#pragma once

#include <stdint.h>
#include <string>



struct AppConfig
{
    std::string     rpc_host;        // 监听的IP
    int32_t         rpc_port;        // 监听的端口

    std::string     rpc_db_host;      // DBServer地址
    int32_t         rpc_db_port;      // DBServer的端口
};


bool    LoadAppConfig(AppConfig& cfg);

