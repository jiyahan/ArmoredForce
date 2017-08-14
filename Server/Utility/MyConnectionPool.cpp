#include "MyConnectionPool.h"
#include "ScopeGuard.h"
#include "easylogging++.h"

using namespace mysqlpp;


MyConnectionPool::MyConnectionPool()
{
    conns_in_use_ = 0;
}

MyConnectionPool::~MyConnectionPool()
{
    clear();
}

// ��ʼ�����Ӳ���
bool MyConnectionPool::init(const ConnetionConfig& cfg)
{
    config_ = cfg;
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
        result->set_option(new ReconnectOption(true));
        result->set_option(new MultiResultsOption(true));
        result->set_option(new MultiStatementsOption(true));
        result->set_option(new SetCharsetNameOption(config_.charset));
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
