#pragma once

#include <boost/noncopyable.hpp>
#include "common/battle/tagBattle.h"
#include "Singleton.h"
#include "Troop.h"


// 战斗
class BattleSys : boost::noncopyable
{
public:
    // 战斗结果
    enum eBattleResult
    {    
        BR_ATTACKER_WIN = 0,    // 攻击方获胜
        BR_DEFENDER_WIN = 1,    // 防守方获胜
        BR_DOGFALL = 2,         // 打平
        BR_NONE = 3,
    };

    // 一个回合的战斗结果
    enum eRoundResult
    {    
        ROUND_ATTACKER_FAIL = 0,    // 攻击方失败
        ROUND_DEFENDER_FAIL = 1,    // 防守方失败
        ROUND_NONE = 2,
    };

    // 攻击类型
    enum eAttackType
    {
        ATK_ATTACKER = 1,       // 攻击方发动攻击
        ATK_DEFENDER = 2,       // 防守方发动攻击
    };

    struct tagRoundResult
    {
        eRoundResult    result;             // 回合结果        
        int32_t         defence_lost_hp;    // 防守掉血
    };

public:
    BattleSys();
    ~BattleSys();

    tagBattle StartFight(TroopPtr attack_troop, TroopPtr defend_troop);

private:
    tagRoundResult  StartRound(TroopPtr attack_troop, 
                               TroopPtr defend_troop, 
                               tagBattleRound& round);
    
    // 回合结果转换为战斗结果
    eBattleResult   BattleResultFromRound(eRoundResult round_result, bool is_attack_troop);

    // 根据队伍生成战斗角色
    tagBattleRole   BattleRoleFromTroop(TroopPtr troop);

};
