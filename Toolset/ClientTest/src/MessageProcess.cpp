#include "MessageProcess.h"
#include <iterator>
#include <algorithm>
#include "common/MESSAGE_ID.h"
#include "game/ProcessLogin.h"
#include "game/ProcessGameBattle.h"


using namespace std;

// 获取所有的消息路由表
HandlerMap    GetHandlerMap()
{
    HandlerMap handlers;
    handlers[MID_LOGIN_LOGINRESPONSE] = HandleLoginResponse;
    handlers[MID_LOGIN_REGISTER_RESPONSE] = HandleRegisterResponse;
    handlers[MID_VERSION_VERIFYRESPONSE] = HandleVerifyResponse;
    handlers[MID_ACCOUNT_AUTHORIZE_RESPOND] = HandleAuthResponse;
    handlers[MID_CHARACTER_INSTANCE_COMBAT_RESPOND] = HandleCombatResponse;
    return std::move(handlers);
}

void OnConnectLS()
{
    OnConnectLoginServer();
}
