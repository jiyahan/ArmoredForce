/**
 *  @file   data_reader.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  读取格式化数据
 *
 */

#pragma once

#include <string>
#include <type_traits>
#include <atom/utility/byteswap/CByteSwap.h>


class DataReader
{
public:
    DataReader(const void* data, size_t bytes)
        : buffer_((const uint8_t*)data), length_(bytes), pos_(0)
    {
    }

    ~DataReader()
    {
        length_ = 0;
        pos_ = 0;
    }

    size_t GetLength() const {return length_;}

    const uint8_t* GetData() const {return buffer_ + pos_;}

    size_t GetLeft() const {return length_ - pos_;}


    template <typename T>
    T  Read()
    {
        static_assert(std::is_pod<T>::value && !std::is_pointer<T>::value, "invalid type");
        if (sizeof(T) <= length_ - pos_)
        {
            T val = *(T*)(buffer_ + pos_);
            pos_ += sizeof(T);
            return CByteSwap::ntoh(val);
        }
        return T();
    }

    void ReadBuffer(uint8_t* buf, size_t length)
    {
        if (length <= length_ - pos_)
        {
            memcpy(buf, buffer_ + pos_, length);
            pos_ += length;
        }
    }

    std::string ReadString()
    {
        string str;
        int32_t len = Read<int32_t>();
        str.resize(len);
        ReadBuffer((uint8_t*)str.data(), len);
        return std::move(str);
    }

private:
    const uint8_t*  buffer_;
    size_t          length_;
    size_t          pos_;
};
