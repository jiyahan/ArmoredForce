#pragma once

#include <cstdint>
#include <string>



struct AppConfig
{
    std::string     mysql_host;             // 数据库IP
    int32_t         mysql_port;             // 数据库端口
    std::string     mysql_user;             // 数据库用户名
    std::string     mysql_pwd;              // 登录密码
    std::string     mysql_default;          // 默认schema
    std::string     mysql_charset;          // 传输编码
    int32_t         connection_pool_size;   // 最大并发连接数
    int32_t         max_idle_time;          // 连接空闲时间

    std::string     host;               // TCP服务器监听地址
    int32_t         port;               // TCP监听端口

    std::string     rpc_host;           // RPC服务器地址
    int32_t         rpc_port;           // RPC服务器端口

    int32_t         pool_size;      
    int32_t         thread_num;

    std::string     log_config_file;    // 日志配置
    std::string     log_dir;            // 日志目录 
};


AppConfig    LoadAppConfig(const std::string& filepath);

