/**
 *	@file	MyConnectionPool.h
 *	@author	chenqiang01@7aurora.com
 *	@date	Dec 17, 2013
 *  @brief	MySQL连接池
 */

#pragma once

#include <string>
#include <memory>
#include <atomic>
#include <mysql++.h>



class MyConnectionPool
    : public mysqlpp::ConnectionPool
{
public:
    struct ConnetionConfig
    {
        std::string     host;           // 数据库IP
        int32_t         port;           // 数据库端口
        std::string     user;           // 数据库用户名
        std::string     pwd;            // 数据库用户密码
        std::string     db;             // 默认数据库
        std::string     charset;        // 传输编码
        int32_t         max_pool_size;  // 连接池大小
        int32_t         max_idle_time;  // 连接空闲时间
    };

public:
    MyConnectionPool();
    ~MyConnectionPool();

    // 初始化连接
    bool init(const std::string& host,
              int32_t port,
              const std::string& user,
              const std::string& pwd,
              const std::string& default,
              const std::string& charset,
              int32_t max_pool_size,
              int32_t max_idle_time);
    
    // 获取一个新连接
    mysqlpp::Connection* 	grab();

    // 释放一个连接给池
    void release(const mysqlpp::Connection* p);

private:

    // 创建新连接
    mysqlpp::Connection* 	create();

    // 释放连接
    void 					destroy(mysqlpp::Connection* cp);

    unsigned int 			max_idle_time();
    
private:	
    std::atomic<int32_t> 	conns_in_use_;      // 当前的连接数量
    ConnetionConfig         config_;            // 连接配置
};

typedef std::shared_ptr<MyConnectionPool>   MyConnectionPoolPtr;
