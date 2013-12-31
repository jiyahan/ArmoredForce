#pragma once

#include <string>


// 配置结构
struct Config
{
    std::string     host;           // LS的IP地址
    U32             port;           // LS端口

    U32             pool_size;
    U32             thread_num;
};


// 读取配置
Config    LoadAppConfig(const std::string& path);
