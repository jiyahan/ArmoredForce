#include "DBLogin.h"
#include "DBUtils.h"
#include "pbkdf2.h"
#include "Utility.h"
#include "MyConnectionPool.h"


std::unique_ptr<MyConnectionPool>  DBLogin::pool_;


bool DBLogin::Init(const std::string& host,
                   int32_t port,
                   const std::string& user,
                   const std::string& pwd,
                   const std::string& default,
                   const std::string& charset,
                   int32_t max_pool_size,
                   int32_t max_idle_time)
{
    pool_.reset(new MyConnectionPool);
    return pool_->init(host, port, user, pwd, default, charset,
        max_pool_size, max_idle_time);
}

int32_t DBLogin::RegisterUser(const std::string& username,
                              int32_t reg_type,
                              const std::string& reg_ip,
                              const std::string& reg_email,
                              const std::string& passwd
                              )
{
    string salt = PBKDF2::CreateSalt();
    string pwd = PBKDF2::CreateStrongPassword(passwd, salt);    

    int32_t status = -1; // failed
    try
    {
        string account = escape_string(username);
        string email = escape_string(reg_email);
        string stmt = stringPrintf("call sp_register_user('%s', %d, '%s', '%s', '%s', '%s')",
            account.c_str(), reg_type, reg_ip.c_str(),
            email.c_str(), pwd.c_str(), salt.c_str());

        mysqlpp::ScopedConnection conn(*pool_);
        auto query = conn->query(stmt);
        auto result = QueryMoreStoreResult(query);
        if (!result.empty() && !result[0].empty())
        {
            status = static_cast<int32_t>(result[0][0]);
        }
    }
    catch (mysqlpp::Exception& ex)
    {
        LOG(WARNING) << ex.what();
    }
    return status;
}

    
int32_t DBLogin::UserLogin(const std::string& user,
                           const std::string& passwd)
{
    try
    {
        string account = escape_string(user);
        string salt = GetUserPasswdSalt(account);
        if (salt.empty())
        {
            return 1;
        }
        string pwd = PBKDF2::CreateStrongPassword(passwd, salt);
        string stmt = stringPrintf("select account from account_db.account_info where "
            "account='%s' and passwd='%s'", account.c_str(), pwd.c_str());
        mysqlpp::ScopedConnection conn(*pool_);
        mysqlpp::Query query = conn->query(stmt);
        auto result = QueryMoreStoreResult(query);
        if (!result.empty() && !result[0].empty())
        {
            if (result[0][0] == account)
            {
                return 0; // OK
            }
        }
        // else not found
    }
    catch (mysqlpp::Exception& ex)
    {
        LOG(WARNING) << ex.what();
    }
    return 1;
}


string DBLogin::GetUserPasswdSalt(const std::string& user)
{
    string salt;
    try
    {
        const char* fmt = "select salt from account_db.account_info where account='%s'";        
        string stmt = stringPrintf(fmt, user.c_str());

        mysqlpp::ScopedConnection conn(*pool_);
        mysqlpp::Query query = conn->query(stmt);
        auto result = QueryMoreStoreResult(query);
        if (!result.empty() && !result[0].empty())
        {
            salt = result[0][0]; // OK
        }
    }
    catch (mysqlpp::Exception& ex)
    {
        LOG(WARNING) << ex.what();
    }

    return salt;
}

bool DBLogin::SaveLoginHistory(const std::string& user,
                               const std::string& ip,
                               int32_t login_status
                               )
{
    try
    {
        string account = escape_string(user);
        string stmt = stringPrintf("insert into account_db.login_history(account, "
            " login_date, login_ip, login_status) values('%s', now(), '%s', %d)",
            account.c_str(), ip.c_str(), login_status);

        mysqlpp::ScopedConnection conn(*pool_);
        mysqlpp::Query query = conn->query(stmt);
        mysqlpp::SimpleResult result = query.execute();
        if (result && result.rows() == 1)
        {
            return true;
        }
    }
    catch (mysqlpp::Exception& ex)
    {
        LOG(WARNING) << ex.what();
    }
    return false;
}
