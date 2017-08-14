#pragma once

#include <boost/noncopyable.hpp>
#include "Server/RPC/IDBRpcService.h"


//IDBRpcService�ӿ�ʵ��
class DBRpcService : boost::noncopyable
{
public:
    // ʵ���û���¼��֤
    int QueryLogin(const std::string& user, const std::string& pwd);

    // ʵ���û���¼��֤
    int RegisterUser(const std::string& user, const std::string& pwd);
private:
};