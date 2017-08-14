#include "DBRpcService.h"
#include "MyConnectionPool.h"
#include "DBServer.h"

using namespace std;
using namespace mysqlpp;



// ʵ���û���¼��֤
int DBRpcService::QueryLogin(const std::string& user, const std::string& pwd)
{
    return 0;
}


// ʵ���û�ע��
int DBRpcService::RegisterUser(const std::string& user, const std::string& pwd)
{
    ScopedConnection conn(DBServer::GetInstance().GetConnectionPool());
    Query query = conn->query("call sp_reg_user %0q, %1q");
    query.parse();
    SimpleResult result = query.execute(user, pwd);
    return result.rows();
}
