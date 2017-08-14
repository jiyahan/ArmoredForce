/**
 *  @file   msg_script.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  Lua������ļ򵥳���
 *
 */


//
// ��Message��װΪ��Lua����
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

#define     MSG_META_HANDLE    "Message*.GC"


// ��ʼ��
void    InitMessageScript(lua_State* L);

