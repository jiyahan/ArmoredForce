#include "BattleSys.h"
#include "ScopeGuard.h"


BattleSys::BattleSys()
{
}

BattleSys::~BattleSys()
{
}


tagBattle   BattleSys::StartFight(TroopPtr attack_troop, TroopPtr defend_troop)
{
    tagBattle battle = {};
    for (auto i = 0; i < MAX_ROUND; ++i)
    {
        cout << "第" << i+1 << "回合开始..." << endl;

        tagBattleRound round = {};
        SCOPE_EXIT{battle.rounds.emplace_back(round);};

        cout << "进攻方开始攻击..." << endl;
        // 攻击方打防守方
        if (!StartRound(attack_troop, defend_troop, round))
        {
            break;
        }

        cout << "防守方开始攻击..." << endl;
        // 防守方打攻击方
        if (!StartRound(defend_troop, attack_troop, round))
        {
            break;
        }
        
    }
    return std::move(battle);
}

// 一个回合，攻击方防守方
eBattleResult BattleSys::StartRound(TroopPtr attack_troop, TroopPtr defend_troop, tagBattleRound& round)
{
    for (auto i = 0; i < GRID_AMOUNT; ++i)
    {
        // 从攻击方挑一个位置
        auto attacker_pos = attack_troop->GetNextAttacker();
        if (attacker_pos == 0)
        {
            break;
        }

        // 从防守方挑一个位置
        auto defender_pos = defend_troop->GetNextDefender(attacker_pos);
        if (defender_pos == 0)
        {
            break;
        }

        auto attacker = attack_troop->GetOfficer(attacker_pos);
        auto defender = defend_troop->GetOfficer(defender_pos);
        CHECK(attacker && defender) << "attacker: " << attacker_pos 
            << "\tdefender: " << defender_pos;

        tagAttackResult result = attacker->Attack(*defender);

        cout << attacker->GetName() << " --> " << defender->GetName()
            << ", 伤害hp: " << result.damage << ", 剩余hp: " << defender->GetHp()
            << endl;

        tagBattleObject object = {defender_pos, result.damage, defender->GetHp()};
        tagBattleStep step = {attack_troop->GetType(), attacker_pos, 0, 0};
        round.steps.emplace_back(step);
    }

    return BR_NONE;
}

