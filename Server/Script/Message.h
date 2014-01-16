//
// 将Message封装到Lua脚本
// pack和unpack支持的格式:
//      %c  byte
//      %h  short
//      %i  int, long
//      %q  int64
//      %f  float
//      %d  double
//      %s  string
//

#pragma once

#include <cstdint>
#include <functional>

typedef std::function<void (int32_t)>  sender_type;

// 初始化
void    message_init(sender_type sender);

// 
bool    dispatch_message(CMessage* msg);
