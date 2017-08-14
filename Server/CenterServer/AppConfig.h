#pragma once

#include <cstdint>
#include <string>



struct AppConfig
{
    std::string     rpc_host;        // ������IP
    int32_t         rpc_port;        // �����Ķ˿�

    std::string     rpc_db_host;      // DBServer��ַ
    int32_t         rpc_db_port;      // DBServer�Ķ˿�

    int32_t         pool_size;
    int32_t         thread_num;
};


AppConfig    LoadAppConfig(const std::string& path);

