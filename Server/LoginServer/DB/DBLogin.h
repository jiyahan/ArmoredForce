#pragma once

#include <string>


class MyConnectionPool;

class DBLogin
{
public:
    // ��ʼ��
    static bool Init(const std::string& host,
                     int32_t port,
                     const std::string& user,
                     const std::string& pwd,
                     const std::string& default,
                     const std::string& charset,
                     int32_t max_pool_size,
                     int32_t max_idle_time);

    // �û�ע��
    static int32_t RegisterUser(const std::string& user, 
                                int32_t reg_type,
                                const std::string& ip,
                                const std::string& email,
                                const std::string& pwd
                                );

    // �û���¼
    static int32_t UserLogin(const std::string& user,
                             const std::string& pwd
                             );

    // �����¼��ʷ
    static bool SaveLoginHistory(const std::string& user,
                                 const std::string& ip,
                                 int32_t login_status
                                 );

private:
    static std::string  GetUserPasswdSalt(const std::string& user);

private:
    static std::unique_ptr<MyConnectionPool>     pool_;
};