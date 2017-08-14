#pragma once

#include <cstdint>
#include <string>

struct AppConfig
{
    std::string     host;           // ������IP��ַ
    int32_t         port;           // �����Ķ˿�

    int32_t         pool_size;      // Ԥ�����ڴ�ش�С
    int32_t         thread_num;     // �߳�����

    std::string     rpc_center_host;    // CenterServer��IP
    int32_t         rpc_center_port;    // CenterServer�Ķ˿�

    std::string     log_config_file;    // ��־����
    std::string     log_dir;            // ��־Ŀ¼ 
};


AppConfig    LoadAppConfig(const std::string& path);
