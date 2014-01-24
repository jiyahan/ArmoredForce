/**
 *  @file   msg_script.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  Lua虚拟机的简单抽象
 *
 */


//
// 将Message封装为到Lua对象
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

struct lua_State;

#define     MSG_META_HANDLE    "Message*.GC"


// 初始化
void    InitMessageScript(lua_State* L);

