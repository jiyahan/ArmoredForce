/**
 *	@file	MyConnectionPool.h
 *	@author	chenqiang01@7aurora.com
 *	@date	Dec 17, 2013
 *  @brief	MySQL���ӳ�
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
        std::string     host;           // ���ݿ�IP
        int32_t         port;           // ���ݿ�˿�
        std::string     user;           // ���ݿ��û���
        std::string     pwd;            // ���ݿ��û�����
        std::string     db;             // Ĭ�����ݿ�
        std::string     charset;        // �������
        int32_t         max_pool_size;  // ���ӳش�С
        int32_t         max_idle_time;  // ���ӿ���ʱ��
    };

public:
    MyConnectionPool();
    ~MyConnectionPool();

    // ��ʼ������
    bool init(const std::string& host,
              int32_t port,
              const std::string& user,
              const std::string& pwd,
              const std::string& default,
              const std::string& charset,
              int32_t max_pool_size,
              int32_t max_idle_time);
    
    // ��ȡһ��������
    mysqlpp::Connection* 	grab();

    // �ͷ�һ�����Ӹ���
    void release(const mysqlpp::Connection* p);

private:

    // ����������
    mysqlpp::Connection* 	create();

    // �ͷ�����
    void 					destroy(mysqlpp::Connection* cp);

    unsigned int 			max_idle_time();
    
private:	
    std::atomic<int32_t> 	conns_in_use_;      // ��ǰ����������
    ConnetionConfig         config_;            // ��������
};

typedef std::shared_ptr<MyConnectionPool>   MyConnectionPoolPtr;
