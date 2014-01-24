/**
 *  @file   message.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  消息格式处理
 *
 */

#pragma once

#include <cstdint>
#include <functional>



typedef uint8_t byte;

namespace electron {class CMessage;}

typedef std::function<void (const void* data, size_t)>   sender_type;

// 将消息压缩并发送给服务器
void SendCompressedMessage(electron::CMessage* msg, sender_type sender);

// 从二进制中解压出正确的消息
electron::CMessage* UnCompressMessage(const void* data, size_t bytes);
