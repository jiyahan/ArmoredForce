#pragma once

#include <string>


// ���ýṹ
struct Config
{
    std::string     host;           // LS��IP��ַ
    U32             port;           // LS�˿�

    U32             pool_size;
    U32             thread_num;
};


// ��ȡ����
Config    LoadAppConfig(const std::string& path);
