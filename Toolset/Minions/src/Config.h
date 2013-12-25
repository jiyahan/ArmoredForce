#pragma once


struct AppConfig
{
    std::string     host;           // LS的IP地址
    int32_t         port;           // LS端口
};


AppConfig    LoadAppConfig(const std::string& path);
