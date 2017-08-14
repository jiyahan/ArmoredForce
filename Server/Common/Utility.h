/**
 * @file    Utility.h
 * @author  chenqiang01@7aurora.com
 * @date    Dec 23, 2013
 * @brief   ������function, macro, class
 *
 */
#pragma once

#include <cstdio>
#include <string>
#include <boost/noncopyable.hpp>


//��������bufferת��Ϊ�ַ���
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

std::string escape_string(const std::string& str);

/**
 * stringPrintf is much like printf but deposits its result into a
 * string. Two signatures are supported: the first simply returns the
 * resulting string, and the second appends the produced characters to
 * the specified string and returns a reference to it.
 */
std::string stringPrintf(const char* format, ...);

/** Similar to stringPrintf, with different signiture.
 */
void stringPrintf(std::string* out, const char* fmt, ...);

std::string& stringAppendf(std::string* output, const char* format, ...);


// ����һ��UUID
std::string     CreateUniqueID();


