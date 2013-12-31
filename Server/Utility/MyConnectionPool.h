/**
 *	@file	MyConnectionPool.h
 *	@author	ichenq@gmail.com
 *	@date	Dec 17, 2013
 *  @brief	MySQL连接池
 */

#pragma once

#include <string>
#include <atomic>
#include <mysql++.h>
#include "Singleton.h"



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

    // 初始化配置
    bool init(const ConnetionConfig& cfg);
	
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
