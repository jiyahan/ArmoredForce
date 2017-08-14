#pragma once

#include <cstdint>
#include <string>


struct AppConfig
{
    std::string     rpc_host;           // ������IP
    int32_t         rpc_port;           // �����Ķ˿�

    std::string     rpc_db_host;        // DBServer��ַ
    int32_t         rpc_db_port;        // DBServer�Ķ˿�

    std::string     rpc_login_host;      // LoginServer��ַ
    int32_t         rpc_login_port;      // DLoginServer�Ķ˿�

    int32_t         pool_size;
    int32_t         thread_num;

    std::string     log_config_file;    // ��־����
    std::string     log_dir;            // ��־Ŀ¼ 
};


AppConfig    LoadAppConfig(const std::string& path);

