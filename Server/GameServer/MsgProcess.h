
#pragma once

#include "GameServer.h"


// �����ɫ��¼
void HandleUserAuth(CMessage& msg);

// ����ս��
void HandleCombatRequest(CMessage& msg);


HandlerMap GetHandlerMap();