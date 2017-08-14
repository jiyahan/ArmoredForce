//
// ��Message��װ��Lua�ű�
// pack��unpack֧�ֵĸ�ʽ:
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

// ��ʼ��
void    MessageInit(lua_State* L, SenderType sender);

// 
bool    DispatchMessage(electron::CMessage* msg);
