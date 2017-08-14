#include "MyConnectionPool.h"
#include "ScopeGuard.h"
#include "easylogging++.h"

using namespace mysqlpp;


MyConnectionPool::MyConnectionPool()
    : conns_in_use_(0)
{
    config_.port = 0;
    config_.max_pool_size = 0;
    config_.max_idle_time = 0;
}

MyConnectionPool::~MyConnectionPool()
{
    clear();
}

// ��ʼ������
bool MyConnectionPool::init(const std::string& host,
                            int32_t port,
                            const std::string& user,
                            const std::string& pwd,
                            const std::string& default,
                            const std::string& charset,
                            int32_t max_pool_size,
                            int32_t max_idle_time)
{
    config_.host = host;
    config_.port = port;
    config_.user = user;
    config_.pwd = pwd;
    config_.db = default;
    config_.charset = charset;
    config_.max_pool_size = max_pool_size;
    config_.max_idle_time = max_idle_time;

    Connection* p = create();
    SCOPE_EXIT { destroy(p); };
    return (p != NULL);
}


// ��ȡһ��������
Connection* MyConnectionPool::grab()
{
    if (conns_in_use_ == config_.max_pool_size)
    {
        return NULL;
    }
    else
    {
        ++conns_in_use_;
        return ConnectionPool::grab();
    }
}

// �黹���Ӷ���
void MyConnectionPool::release(const mysqlpp::Connection* p)
{
    ConnectionPool::release(p);
    --conns_in_use_;
}

// ����һ��������
Connection*  MyConnectionPool::create()
{
    Connection* result = NULL;
    try
    {
        result = new mysqlpp::Connection;
        result->set_option(new MultiResultsOption(true));
        result->set_option(new MultiStatementsOption(true));
        result->set_option(new SetCharsetNameOption(config_.charset));
        result->set_option(new ReconnectOption(true));
        result->connect(config_.db.c_str(), config_.host.c_str(), config_.user.c_str(),
            config_.pwd.c_str(), config_.port);
    }
    catch(std::exception& ex)
    {
        delete result;
        LOG(ERROR) << ex.what();
        return NULL;
    }

    return result;
}


void MyConnectionPool::destroy(Connection* cp)
{
    delete cp;
}

unsigned int    MyConnectionPool::max_idle_time()
{
    return config_.max_idle_time;
}
