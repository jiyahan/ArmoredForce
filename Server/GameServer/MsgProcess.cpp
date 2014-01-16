#include "MsgProcess.h"
#include <algorithm>
#include <numeric>
#include <easylogging++.h>
#include "GameServer.h"
#include "Server/GameServer/App/BattleSys.h"
#include "Server/GameServer/App/Troop.h"
#include "common/RoleCommon.h"
#include "common/MSGCode.h"
#include "common/MSGGame.h"
#include "common/setup/RegionList.h"
#include "common/setup/MonsterList.h"
#include "common/setup/OfficerList.h"


using namespace std;
using namespace atom;
using namespace electron;


static vector<OfficerCommon>   GetMonsterMatrix(bool reverse)
{    
    vector<OfficerCommon> officers;
    
    auto fn = [&](const setup::tagMonster& item, int count)
    {
        OfficerCommon officer;
        officer.name = item.name;
        officer.category = item.category;
        //officer.id = GetUniqueID();
        officer.level = 1;
        officer.postion = count;
        officer.hp = item.force;
        officer.attack = item.attack;
        officer.blast = 10;
        officer.accuracy = 10;
        officer.command_force = 0;
        officer.leadership = 0;

        officers.emplace_back(officer);
    };

    auto officer_list = setup::MonsterListSetup::GetInstance()->GetMonsterList();
    if (reverse)
    {
        int count = 1;
        for (auto iter = officer_list.rbegin(); iter != officer_list.rend(); ++iter)
        {
            fn(iter->second, count);
            if (count++ == 6)
                break;
        }
    }
    else
    {
        int count = 1;
        for (auto iter = officer_list.begin(); iter != officer_list.end(); ++iter)
        {
            fn(iter->second, count);
            if (count++ == 6)
                break;
        }
    }
    return std::move(officers);
}


tagBattle MockFight2()
{    
    TroopPtr troop = Troop::CreateFromRegion("极乐世界", 1);
    TroopPtr troop2 = Troop::CreateFromRegion("极乐世界", 2);
    tagBattle battle = GetBattleSys().StartFight(troop, troop2);
    return std::move(battle);
}

static void HandleCombatRequest(CMessage& msg)
{
    MSGBattleCombat request;
    msg >> request;
    cout << request.mapId << "\t" << request.posId << endl;

    
    tagBattle battle = MockFight2();

    MSGBattleCombatResponse response;
    CArchive ar;
    ar << battle;
    ar.Clone(response.data);
    GetTCPServer().Send(msg.GetConnector(), response);

}

// 处理角色登录
static void HandleUserAuth(CMessage& msg)
{
    MSGAccountAuthorize request;
    msg >> request;
    cout << request.device << "\t" << request.deviceType << "\t"
        << request.account << "\t" << request.usrsign << endl;

    RoleCommon role;
    role.name = "TomHagen";
    role.id = 10013;
    role.level = 56;
    role.title = 13;
    role.exp = 103450;
    role.action_point = 790;
    role.gold = 200000; 
    role.gold = 530;
    auto  officer_list = GetMonsterMatrix(false);

    MSGAccountAuthorizeResponse response;
    response.roleId = 1000;

    CArchive archive;
    archive << role << officer_list;
    archive.Clone(response.data);

    GetTCPServer().Send(msg.GetConnector(), response);
}


HandlerMap GetHandlerMap()
{
    //MockFight2();

    HandlerMap handlers;
    handlers[MID_ACCOUNT_AUTHORIZE_REQUEST] = HandleUserAuth;
    handlers[MID_CHARACTER_INSTANCE_COMBAT_REQUEST] = HandleCombatRequest;
    return std::move(handlers);
}
