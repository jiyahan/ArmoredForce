/**
 * @file    pbkdf2.h
 * @author  chenqiang01@7aurora.com
 * @date    Jan 13, 2014
 * @brief   ʹ��PBKDF2�㷨�������û�����
 *
 *          ����salt
 *          http://en.wikipedia.org/wiki/Salt_(cryptography)
 *          http://en.wikipedia.org/wiki/PBKDF2
 *
 *          Ϊʲô���ܼ򵥵�MD5����SHA1
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
    PBKDF2();
    ~PBKDF2();

    // �������һ��salt
    std::string CreateSalt();

    // ����pbkdf2���봮
    std::string CreateStrongPassword(const std::string& plain, const std::string& salt);

private:
    std::default_random_engine       generator_;
};

