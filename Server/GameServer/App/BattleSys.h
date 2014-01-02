#pragma once

#include "common/battle/tagBattle.h"
#include "Singleton.h"
#include "Troop.h"


// 战斗结果
enum eBattleResult
{    
    BR_ATTACKER_WIN = 0,    // 攻击方获胜
    BR_DEFENDER_WIN = 1,    // 防守方获胜
    BR_DOGFALL = 2,         // 打平
    BR_NONE = 3,
};

// 攻击类型
enum eAttackType
{
    ATK_ATTACKER = 1,       // 攻击方发动攻击
    ATK_DEFENDER = 2,       // 防守方发动攻击
};


// 战斗
class BattleSys : public Singleton<BattleSys>
{
public:
    BattleSys();
    ~BattleSys();

    tagBattle StartFight(TroopPtr attack_troop, TroopPtr defend_troop);

private:
    eBattleResult    StartRound(TroopPtr attack_troop, TroopPtr defend_troop, tagBattleRound& round);
    
private:

};
