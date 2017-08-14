#pragma once

#include <functional>
#include <unordered_map>

namespace electron {class CMessage;}

typedef std::function<void (electron::CMessage&)>   HandlerType;
typedef std::unordered_map<int32_t, HandlerType>    HandlerMap;


// ���������Ϣ·�ɱ� 
HandlerMap  GetHandlerMap();

// ������LS��Ĵ���
void    OnConnectLS();
