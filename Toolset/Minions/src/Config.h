#pragma once

#include <string>


// 配置结构
struct Config
{
    std::string     host;           // LoginServer的IP地址
    int32_t         port;           // LoginServer端口

    int32_t         pool_size;
    int32_t         thread_num;

    std::string     log_config_file;    // 日志配置
    std::string     log_dir;            // 日志目录
};


// 读取配置
Config    LoadAppConfig(const std::string& path);
