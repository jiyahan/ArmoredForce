#pragma once

#include <stdint.h>
#include <string>



struct AppConfig
{
    std::string     rpc_host;        // ������IP
    int32_t         rpc_port;        // �����Ķ˿�

    std::string     rpc_db_host;      // DBServer��ַ
    int32_t         rpc_db_port;      // DBServer�Ķ˿�
};


bool    LoadAppConfig(AppConfig& cfg);

