#pragma once

#include <stdint.h>
#include <string>



struct AppConfig
{
    std::string     host;           // 监听的IP地址
    int32_t         port;           // 监听的端口

    int32_t         pool_size;      // 预分配内存池大小
    int32_t         thread_num;     // 线程数量

    std::string     rpc_center_host;    // CenterServer的IP
    int32_t         rpc_center_port;    // CenterServer的端口
};


bool    LoadAppConfig(AppConfig& cfg);

