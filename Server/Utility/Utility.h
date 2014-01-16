/**
 * @file    Utility.h
 * @author  chenqiang01@7aurora.com
 * @date    Dec 23, 2013
 * @brief   工具类function, macro, class
 *
 */
#pragma once

#include <cstdio>
#include <string>
#include <boost/noncopyable.hpp>


//将二进制buffer转换为字符串
template <int32_t N>
inline std::string  BinaryToHex(const std::array<uint8_t, N>& ar)
{
    std::string result;
    result.reserve(N*2);
    for (auto ch : ar)
    {
        char buf[4] = {};
        _snprintf(buf, _countof(buf), "%02x", ch);
        result += buf;
    }
    return std::move(result);
}


// 自动初始化atom
class AtomAutoInit : boost::noncopyable
{
public:
    AtomAutoInit(int32_t pool_size, int32_t thread_num);

    ~AtomAutoInit();
};


// 生成一个UUID
std::string     CreateUniqueID();


#ifndef NOT_USE_ATOM_ALLOCATOR
#define AS2Std(s)  as2std((s).c_str())
#else
#define AS2Std(s)   (s)
#endif