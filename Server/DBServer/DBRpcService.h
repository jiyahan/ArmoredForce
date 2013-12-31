#pragma once

#include <boost/noncopyable.hpp>
#include "Server/RPC/IDBRpcService.h"


//IDBRpcService接口实现
class DBRpcService : boost::noncopyable
{
public:
    // 实现用户登录验证
    int QueryLogin(const std::string& user, const std::string& pwd);

    // 实现用户登录验证
    int RegisterUser(const std::string& user, const std::string& pwd);
private:
};