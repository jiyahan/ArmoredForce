/**
 * @file    pbkdf2.h
 * @author  chenqiang01@7aurora.com
 * @date    Jan 13, 2014
 * @brief   使用PBKDF2算法来加密用户密码
 *
 *          关于salt
 *          http://en.wikipedia.org/wiki/Salt_(cryptography)
 *          http://en.wikipedia.org/wiki/PBKDF2
 *
 *          为什么不能简单的MD5或者SHA1
 *          https://crackstation.net/hashing-security.html
 *          http://stackoverflow.com/questions/4433216/password-encryption-pbkdf2-using-sha512-x-1000-vs-bcrypt
 */
 
#pragma once


#include <string>
#include <random>



class PBKDF2
{
public:
    enum 
    {
        SALT_SIZE = 8,      // cryptographic salt length
        KEY_LEN = 32,       // desired length of the derived key
        ITERATION = 2024,   // number of iterations desired
    };

public:

    // 随机生成一个salt
    static std::string CreateSalt();

    // 生成pbkdf2密码串
    static std::string CreateStrongPassword(const std::string& plain, const std::string& salt);

private:
    static std::default_random_engine       generator_;
};

