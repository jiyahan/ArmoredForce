#pragma once

#include <functional>
#include <unordered_map>

namespace electron {class CMessage;}

typedef std::function<void (electron::CMessage&)>   HandlerType;
typedef std::unordered_map<int32_t, HandlerType>    HandlerMap;


// 获得所有消息路由表 
HandlerMap  GetHandlerMap();

// 连接上LS后的处理
void    OnConnectLS();
