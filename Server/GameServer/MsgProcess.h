
#pragma once

#include "GameServer.h"


// �����ɫ��¼
void HandleUserAuth(CMessage& msg);

// ����ս��
void HandleCombatRequest(CMessage& msg);

// ��Ϣ��������
HandlerMap  GetHandlerMap();