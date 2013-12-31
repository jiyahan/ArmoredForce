﻿#include "BattleSys.h"



BattleSys::BattleSys()
{
}

BattleSys::~BattleSys()
{
}


tagBattle   BattleSys::StartFight(TroopPtr attack_troop, TroopPtr defend_troop)
{
    tagBattle battle;
    for (int i = 0; i < MAX_ROUND; ++i)
    {
        LOG(INFO) << "第" << i << "回合开始...";

        tagBattleRound round;

        // 攻击方打防守方
        if (!StartRound(attack_troop, defend_troop, round))
        {
            break;
        }
        // 防守方打攻击方
        if (!StartRound(defend_troop, attack_troop, round))
        {
            break;
        }
    }
    return std::move(battle);
}

// 一个回合，攻击方防守方
bool BattleSys::StartRound(TroopPtr attack_troop, TroopPtr defend_troop, tagBattleRound& round)
{    
    for (int i = 0; i < GRID_AMOUNT; ++i)
    {
        I16 attacker_pos = attack_troop->GetNextAttacker();
        if (attacker_pos == 0)
        {
            break;
        }
        I16 defender_pos = defend_troop->GetNextDefender(attacker_pos);
        if (defender_pos == 0)
        {
            break;
        }

        auto attacker = attack_troop->GetOfficer(attacker_pos);
        auto defender = defend_troop->GetOfficer(defender_pos);
        CHECK(attacker && defender) << "attacker: " << attacker_pos 
            << "\tdefender: " << defender_pos;

        tagAttackResult result = attacker->Attack(*defender);

        tagBattleObject object = {defender_pos, result.damage, defender->GetHp()};
        tagBattleStep step = {attack_troop->GetType(), attacker_pos, 0, 0};
        round.steps.emplace_back(step);
    }

    return true;
}
