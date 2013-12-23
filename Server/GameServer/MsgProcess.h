
#pragma once

#include "GameServer.h"


// 处理角色登录
void HandleUserAuth(CMessage& msg);

// 处理战斗
void HandleCombatRequest(CMessage& msg);


HandlerMap GetHandlerMap();