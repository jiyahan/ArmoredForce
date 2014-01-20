#pragma once

#include <string>


// 配置结构
struct Config
{
    int32_t         pool_size;
    int32_t         thread_num;

    std::string     log_config_file;    // 日志配置
    std::string     log_dir;            // 日志目录
};


// 读取配置
Config    LoadAppConfig(const std::string& path);
