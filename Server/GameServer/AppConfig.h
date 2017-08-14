#pragma once

#include <stdint.h>
#include <string>



struct AppConfig
{
    std::string     host;           // ������IP��ַ
    int32_t         port;           // �����Ķ˿�

    int32_t         pool_size;      // Ԥ�����ڴ�ش�С
    int32_t         thread_num;     // �߳�����

    std::string     rpc_center_host;    // CenterServer��IP
    int32_t         rpc_center_port;    // CenterServer�Ķ˿�
};


bool    LoadAppConfig(AppConfig& cfg);

