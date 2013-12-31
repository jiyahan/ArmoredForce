#pragma once

#include <boost/noncopyable.hpp>
#include "common/battle/tagBattle.h"
#include "Troop.h"

// 站
enum eBattleResult
{    
    BR_ATTACKER_WIN = 0,
    BR_DEFENDER_WIN = 1,
    BR_DOGFALL = 2,
    BR_NONE = 3,
};

// 攻击类型
enum eAttackType
{
    ATK_ATTACKER = 1,
    ATK_DEFENDER = 2,
};


// 战斗
class BattleSys : private boost::noncopyable
{
public:
    BattleSys();
    ~BattleSys();

    tagBattle StartFight(TroopPtr attack_troop, TroopPtr defend_troop);

private:
    bool    StartRound(TroopPtr attack_troop, TroopPtr defend_troop, tagBattleRound& round);
    
private:

};
