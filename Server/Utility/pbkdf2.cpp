#include "pbkdf2.h"
#include <cstdint>
#include <array>
#include <openssl/evp.h>
#include "Utility.h"



using namespace std;

typedef std::array<uint8_t, PBKDF2::SALT_SIZE>  SaltType;
typedef std::array<uint8_t, PBKDF2::KEY_LEN>    KeyType;

//////////////////////////////////////////////////////////////////////////
PBKDF2::PBKDF2()
    : generator_(std::random_device()())
{
}

PBKDF2::~PBKDF2()
{
}

string  PBKDF2::CreateSalt()
{
    SaltType salt = {};
    for (auto i = 0; i < SALT_SIZE; i+=sizeof(int32_t))
    {
        *reinterpret_cast<int32_t*>(salt.data() + i) = generator_();
    }    
    return BinaryToHex(salt);
}


string PBKDF2::CreateStrongPassword(const std::string& plain, const string& salt)
{
    string result;
    KeyType key = {};
    if (!PKCS5_PBKDF2_HMAC_SHA1(plain.data(), plain.size(), (uint8_t*)salt.data(), 
            salt.size(), ITERATION, KEY_LEN, key.data()))
    {
        return result;
    }
    return BinaryToHex(key);
}
