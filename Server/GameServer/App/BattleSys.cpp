#include "BattleSys.h"
#include "ScopeGuard.h"


BattleSys::BattleSys()
{
}

BattleSys::~BattleSys()
{
}

BattleSys::eBattleResult BattleSys::BattleResultFromRound(eRoundResult round_result, 
                                                          bool is_attack_troop)                                                              
{
    switch(round_result)
    {
    case ROUND_ATTACKER_FAIL:
        return (is_attack_troop ? BR_DEFENDER_WIN : BR_ATTACKER_WIN);
            break;

    case ROUND_DEFENDER_FAIL:
        return (is_attack_troop ? BR_ATTACKER_WIN : BR_DEFENDER_WIN);
        break;

    }
    return BR_NONE;
}

tagBattleRole   BattleSys::BattleRoleFromTroop(TroopPtr troop)
{
    tagBattleRole role = {};
    role.hp = troop->GetTotalHp();
    role.name = troop->GetOwnerName();
    for (auto i = 0U; i < GRID_AMOUNT; ++i)
    {
        auto pos = i + 1;
        tagBattleRoleOfficer battle_officer = {};
        auto officer = troop->GetOfficer(pos);
        battle_officer.id = officer->GetUniqueID();
        battle_officer.level = officer->GetLevel();
        battle_officer.attack = officer->GetAttack();
        battle_officer.hp = officer->GetHp();
        battle_officer.pos = pos;
        role.officers.emplace_back(battle_officer);
    }
    return std::move(role);
}

tagBattle   BattleSys::StartFight(TroopPtr attack_troop, TroopPtr defend_troop)
{
    tagBattle battle = {};
    battle.attacker = BattleRoleFromTroop(attack_troop);
    battle.defender = BattleRoleFromTroop(defend_troop);

    eBattleResult battle_result = BR_NONE;
    int32_t attacker_lost_hp = 0;
    int32_t defender_lost_hp = 0;

    for (auto i = 0; i < MAX_ROUND; ++i)
    {
        LOG(TRACE) << endl << "第" << i+1 << "回合开始..." << endl;

        tagBattleRound round = {};
        SCOPE_EXIT{battle.rounds.emplace_back(round);};

        LOG(TRACE) << "进攻方开始攻击..." << endl;

        // 攻击方打防守方
        tagRoundResult round_result = StartRound(attack_troop, defend_troop, round);
        defender_lost_hp += round_result.defence_lost_hp;
        if (round_result.result != ROUND_NONE)
        {
            battle_result = BattleResultFromRound(round_result.result, true);
            break;
        }

        LOG(TRACE) << "防守方开始攻击..." << endl;
        // 防守方打攻击方
        round_result = StartRound(defend_troop, attack_troop, round);
        attacker_lost_hp += round_result.defence_lost_hp;
        if (round_result.result != ROUND_NONE)
        {
            battle_result = BattleResultFromRound(round_result.result, false);
            break;
        }
        
    }
    return std::move(battle);
}

// 一个回合，攻击方防守方
BattleSys::tagRoundResult BattleSys::StartRound(TroopPtr attack_troop, 
                                                TroopPtr defend_troop, 
                                                tagBattleRound& round)
{
    tagRoundResult round_result = {ROUND_NONE, 0};
    for (auto i = 0; i < GRID_AMOUNT; ++i)
    {
        // 从攻击方挑一个位置
        auto attacker_pos = attack_troop->GetNextAttacker();
        if (attacker_pos == 0)
        {
            round_result.result = ROUND_ATTACKER_FAIL;
            break;
        }

        // 从防守方挑一个位置
        auto defender_pos = defend_troop->GetNextDefender(attacker_pos);
        if (defender_pos == 0)
        {
            round_result.result = ROUND_DEFENDER_FAIL;
            break;
        }

        auto attacker = attack_troop->GetOfficer(attacker_pos);
        auto defender = defend_troop->GetOfficer(defender_pos);
        CHECK(attacker && defender) << "attacker: " << attacker_pos 
            << "\tdefender: " << defender_pos;

        tagAttackResult atk_result = attacker->Attack(*defender);
        round_result.defence_lost_hp += atk_result.damage;
 
        LOG(TRACE) << attacker->GetName() << " --> " << defender->GetName()
            << ",\t伤害hp: " << atk_result.damage << ", 剩余hp: " << defender->GetHp()
            << (defender->IsDead() ? "战亡": "") << endl;

        tagBattleObject object = {defender_pos, atk_result.damage, defender->GetHp()};
        tagBattleStep step = {attack_troop->GetType(), attacker_pos, 0, 0};
        step.objs.emplace_back(object);
        round.steps.emplace_back(step);
    }

    return std::move(round_result);
}

