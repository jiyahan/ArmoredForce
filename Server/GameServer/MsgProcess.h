
#pragma once

#include "GameServer.h"


// 处理角色登录
void HandleUserAuth(CMessage& msg);

// 处理战斗
void HandleCombatRequest(CMessage& msg);

// 消息处理函数表
HandlerMap  GetHandlerMap();