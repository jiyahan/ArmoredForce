#include "DBRpcService.h"
#include "MyConnectionPool.h"
#include "DBServer.h"

using namespace std;
using namespace mysqlpp;



// 实现用户登录验证
int DBRpcService::QueryLogin(const std::string& user, const std::string& pwd)
{
    return 0;
}


// 实现用户注册
int DBRpcService::RegisterUser(const std::string& user, const std::string& pwd)
{
    ScopedConnection conn(DBServer::GetInstance().GetConnectionPool());
    Query query = conn->query("call sp_reg_user %0q, %1q");
    query.parse();
    SimpleResult result = query.execute(user, pwd);
    return result.rows();
}
