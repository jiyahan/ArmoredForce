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

typedef std::function<void (int32_t)>  sender_type;

// ��ʼ��
void    message_init(sender_type sender);

// 
bool    dispatch_message(CMessage* msg);
