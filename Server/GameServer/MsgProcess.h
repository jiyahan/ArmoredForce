#pragma once

#include <functional>
#include <unordered_map>


typedef std::function<void (electron::CMessage&)>	HandlerType;
typedef std::unordered_map<int32_t, HandlerType>    HandlerMap;


// 消息路由表
HandlerMap      GetHandlerMap();
