#include "stdafx.h"
#include "MsgProcess.h"
#include "GameServer.h"
#include "common/battle/tagBattle.h"
#include "common/RoleCommon.h"
#include "common/MSGCode.h"
#include "common/MSGGame.h"


using namespace std;

GameServer& thisServer = GameServer::GetInstance();


HandlerMap GetHandlerMap()
{
    HandlerMap handlers;
    handlers[MID_ACCOUNT_AUTHORIZE_REQUEST] = HandleUserAuth;
    handlers[MID_CHARACTER_INSTANCE_COMBAT_REQUEST] = HandleCombatRequest;
    return std::move(handlers);
}


// ´¦Àí½ÇÉ«µÇÂ¼
void HandleUserAuth(CMessage& msg)
{
	MSGAccountAuthorize request;
	msg >> request;
	cout << request.device << "\t" << request.deviceType << "\t"
        << request.account << "\t" << request.usrsign << endl;

    RoleCommon role = {"role-name"};
    MSGAccountAuthorizeResponse response;
    response.roleId = 1000;
    
    CArchive archive;
    archive << role;
    archive.Clone(response.data);

	thisServer.GetSocketServer().Send(msg.GetConnector(), response);
}


void HandleCombatRequest(CMessage& msg)
{
    MSGBattleCombat request;
    msg >> request;
    cout << request.mapId << "\t" << request.posId << endl;

    tagBattleRole attacker = {"attacker", 100, 200000, 10003};
    for (int i = 0; i < 6; ++i)
    {
        //tagBattleRoleOfficer card = {1000+i, 13, i+1, 2000+i*10};
        //attacker.officers.push_back(card);
    }
    tagBattleRole defender = {"defender", 101, 230000, 10004};
    for (int i = 0; i < 6; ++i)
    {
        //tagBattleRoleOfficer card = {2000+i, 13, i+1, 1800+i*10};
        //defender.officers.push_back(card);
    }

    tagBattleRound rounds;
    tagBattleStep step = {1, 1, 1, 1};
    for (int i = 0; i < 2; ++i)
    {
        tagBattleObject obj = {1, 1000, 2000};
        step.objs.push_back(obj);
    }
    rounds.steps.push_back(step);
    tagBattleResult result = {1, 10000, 10000, 9};
    tagBattlePrize prize = {10, 20, 1};

    tagBattle battle = {attacker, defender, result};
    battle.prize.push_back(prize);
    battle.rounds.push_back(rounds);

    MSGBattleCombatResponse response;
    CArchive ar;
    ar << battle;
    ar.Clone(response.data);
    thisServer.GetSocketServer().Send(msg.GetConnector(), response);

}