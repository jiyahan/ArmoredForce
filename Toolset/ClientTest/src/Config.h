#pragma once

#include <string>


// ���ýṹ
struct Config
{
    std::string     host;
    int16_t         port;
    int32_t         pool_size;
    int32_t         thread_num;

    std::string     log_config_file;    // ��־����
    std::string     log_dir;            // ��־Ŀ¼
};


// ��ȡ����
Config    LoadAppConfig(const std::string& path);