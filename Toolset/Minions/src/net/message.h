/**
 *  @file   message.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  message
 *
 */

#pragma once

#include <cstdint>
#include <memory>
#include <vector>
#include <boost/noncopyable.hpp>

enum {MAX_MSG_SIZE = 8192};
typedef uint8_t byte;

class Message : boost::noncopyable
{
public:
    Message();
    ~Message();

    const byte* data() const {return std::addressof(*buffer_.begin());};
    size_t      size() const {return buffer_.size();}
private:
    std::vector<byte>    buffer_;

};

typedef std::shared_ptr<Message>    MessagePtr;
