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

struct lua_State;
namespace electron {class CMessage;}

typedef std::function<void (int32_t, electron::CMessage*)>  SenderType;

// 初始化
void    MessageInit(lua_State* L, SenderType sender);

// 
bool    DispatchMessage(electron::CMessage* msg);
