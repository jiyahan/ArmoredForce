#include "ProcessGameBattle.h"
#include "common/MESSAGE_ID.h"
#include "common/MSGCode.h"
#include "common/MSGGame.h"
#include "common/MSGLogin.h"
#include "common/RoleCommon.h"
#include "common/update/tagGameServer.h"
#include "common/battle/tagBattle.h"

using namespace std;
using namespace atom;
using namespace electron;


void HandleCombatResponse(CMessage& msg)
{
    MSGBattleCombatResponse response;
    msg >> response;
    CArchive ar;
    ar.Assign(response.data);
    tagBattle battle;
    ar >> battle;
    cout << battle.attacker.name;
}
