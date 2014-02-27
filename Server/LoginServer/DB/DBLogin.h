#pragma once

#include <string>


class MyConnectionPool;

class DBLogin
{
public:
    // 初始化
    static bool Init(const std::string& host,
                     int32_t port,
                     const std::string& user,
                     const std::string& pwd,
                     const std::string& default,
                     const std::string& charset,
                     int32_t max_pool_size,
                     int32_t max_idle_time);

    // 用户注册
    static int32_t RegisterUser(const std::string& user, 
                                int32_t reg_type,
                                const std::string& ip,
                                const std::string& email,
                                const std::string& pwd
                                );

    // 用户登录
    static int32_t UserLogin(const std::string& user,
                             const std::string& pwd
                             );

    // 保存登录历史
    static bool SaveLoginHistory(const std::string& user,
                                 const std::string& ip,
                                 int32_t login_status
                                 );

private:
    static std::string  GetUserPasswdSalt(const std::string& user);

private:
    static std::unique_ptr<MyConnectionPool>     pool_;
};