#include "stdafx.h"
#include "MsgProcess.h"
#include <algorithm>
#include <numeric>
#include "Server/GameServer/App/BattleSys.h"
#include "common/RoleCommon.h"
#include "common/MSGCode.h"
#include "common/MSGGame.h"


using namespace std;

GameServer& thisServer = GameServer::GetInstance();

I32 GetUniqueID()
{
    static I32 current_id = 2000;
    return current_id++;
}

static vector<OfficerCommon>   GetMonsterMatrix(bool reverse)
{    
    vector<OfficerCommon> officers;
    
    auto fn = [&](const setup::tagMonster& item, int count)
    {
        OfficerCommon officer = {};
        officer.name = item.name;
        officer.category = item.category;
        officer.id = GetUniqueID();
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


tagBattle InitFightRole(vector<OfficerCommon>& attacker_troop, vector<OfficerCommon>& defender_troop)
{
    tagBattle battle = {};
    int atk_sum = 0;
    int pos = 1;
    cout << "��������: \n";
    for(const auto& item : attacker_troop)
    {
        atk_sum += item.hp;
        tagBattleRoleOfficer monster = {item.name, item.attack, item.level, pos++, item.hp};
        battle.attacker.officers.emplace_back(monster);     
        cout << "\t" << monster.id.c_str() << "\t����: " 
             << monster.attack << "\tѪ��:" << monster.hp << endl;
    }
    battle.attacker.hp = atk_sum;
    battle.attacker.name = "TomHagen";
    battle.attacker.level = 56;

    int def_sum = 0;
    pos = 1;
    cout << "\n���ض���: \n";
    for (const auto& item : defender_troop)
    {
        def_sum += item.hp;
        tagBattleRoleOfficer monster = {item.name, item.attack, item.level, pos++, item.hp};
        battle.defender.officers.emplace_back(monster);
        cout << "\t" << monster.id.c_str() << "\t����: " 
            << monster.attack << "\tѪ��:" << monster.hp << endl;
    }
    battle.defender.hp = def_sum;
    battle.defender.name = "Monster";
    battle.defender.level = 1;

    cout << "\n\n";
    return std::move(battle);
}

// step 1, ѡһ��attacker
// step 2, ѡһ��defender
// step 3, attacker --> defender
//

tagBattleRoleOfficer* GetNextDefender(vector<tagBattleRoleOfficer>& defense_troop, int& pos)
{
    for (int i = pos; i < defense_troop.size(); ++i)
    {
        auto& monster = defense_troop[i];
        if (monster.hp > 0)
        {
            pos = i+1;
            return std::addressof(monster);
        }
    }
    for (int i = 0; i < pos && i < defense_troop.size(); ++i)
    {
        auto& monster = defense_troop[i];
        if (monster.hp > 0)
        {
            pos = i+1;
            return std::addressof(monster);
        }
    }
    return nullptr;
}

tagBattleRoleOfficer* GetNextAttacker(vector<tagBattleRoleOfficer>& attack_troop, int& pos)
{
    for (int i = pos; i < attack_troop.size(); ++i)
    {
        auto& monster = attack_troop[i];
        if (monster.hp > 0)
        {
            pos = i+1;
            return std::addressof(monster);
        }
    }
    for (int i = 0; i < pos && i < attack_troop.size(); ++i)
    {
        auto& monster = attack_troop[i];
        if (monster.hp > 0)
        {
            pos = i+1;
            return std::addressof(monster);
        }
    }
    return nullptr;
}

int DoAttack(tagBattleRoleOfficer& attacker, tagBattleRoleOfficer& defender)                       
{
    if (attacker.hp <= 0)
        return 0;

    int atk = attacker.attack;
    if (atk > defender.hp)
        atk = defender.hp;
    defender.hp -= atk;
    if (defender.hp == 0)
        cout << "\t" << defender.id << " ����.\n";
    return atk;
}

tagBattle MockFight()
{
    // ��������
    vector<OfficerCommon> attackers = GetMonsterMatrix(false);
    // ���ض���
    vector<OfficerCommon> defenders = GetMonsterMatrix(true);

    tagBattle battle = InitFightRole(attackers, defenders);

    vector<tagBattleRoleOfficer> attacker_troop = battle.attacker.officers;
    vector<tagBattleRoleOfficer> defender_troop = battle.defender.officers;

    int result = 2;
    int attack_lose = 0;
    int defense_lose = 0;

    for (int i = 0; i < MAX_ROUND; ++i)
    {
        cout << "\n��" << i+1 << "�غϿ�ʼ��������\n\n";
        tagBattleRound round;
        // ����������ط�
        int atk_pos = 0;
        int def_pos = 0;
        for (int i = 0; i < GRID_AMOUNT; ++i)
        {            
            auto attacker = GetNextAttacker(attacker_troop, atk_pos);
            if (!attacker)
            {
                result = 1;
                break;
            }
            auto defender = GetNextDefender(defender_troop, def_pos);
            if (!defender)
            {
                result = 0;
                break;
            }

            int lost_hp = DoAttack(*attacker, *defender);
            if (lost_hp > 0)
            {
                defense_lose += lost_hp;
                cout << "\t����������: " << attacker->id << " --> " << defender->id
                    << ", �˺�hp: " << lost_hp << ", ʣ��hp: " << defender->hp
                    << endl;

                tagBattleObject object = {def_pos, lost_hp, defender->hp};
                tagBattleStep step = {1, atk_pos, 0, 0};
                step.objs.emplace_back(object);
                round.steps.emplace_back(step);
            }
        }

        // �Ѿ��н��
        if (result < 2) 
        {
            battle.rounds.emplace_back(round);
            break;
        }

        cout << "\n\t�������������ط�����ʼ������\n\n";
        // ���ط��򹥻���
        atk_pos = 0;
        def_pos = 0;
        for (int i = 0; i < GRID_AMOUNT; ++i)
        {
            auto attacker = GetNextAttacker(defender_troop, atk_pos);
            if (!attacker)
            {
                result = 0;
                break;
            }
            auto defender = GetNextDefender(attacker_troop, def_pos);
            if (!defender)
            {
                result = 1;
                break;
            }

            int lost_hp = DoAttack(*attacker, *defender);
            if (lost_hp > 0)
            {
                attack_lose += lost_hp;
                cout << "\t���ط�����: " << attacker->id << " --> " << defender->id
                    << ", �˺�hp: " << lost_hp << ", ʣ��hp: " << defender->hp
                    << endl;

                tagBattleObject object = {def_pos, lost_hp, defender->hp};
                tagBattleStep step = {2, atk_pos, 0, 0};
                step.objs.emplace_back(object);
                round.steps.emplace_back(step);
            }
        }
        // �Ѿ��н��
        if (result < 2) 
        {
            battle.rounds.emplace_back(round);
            break;
        }
        battle.rounds.emplace_back(round);
    }
    
    string str = "��ƽ";
    if (result == 0)
        str = "��������ʤ";
    else if (result == 1)
        str = "���ط���ʤ";
    cout << "\n�����չ�." << str << endl;

    battle.result.result = result;
    battle.result.attackerLoseHP = attack_lose;
    battle.result.defenderLoseHP = defense_lose;
    battle.result.score = thisServer.GetRandGen().Uniform(50);
    if (result == 0)
        battle.result.score += 50;
    return std::move(battle);
}

static void HandleCombatRequest(CMessage& msg)
{
    MSGBattleCombat request;
    msg >> request;
    cout << request.mapId << "\t" << request.posId << endl;

    
    tagBattle battle = MockFight();

    MSGBattleCombatResponse response;
    CArchive ar;
    ar << battle;
    ar.Clone(response.data);
    thisServer.GetSocketServer().Send(msg.GetConnector(), response);

}

// �����ɫ��¼
static void HandleUserAuth(CMessage& msg)
{
    MSGAccountAuthorize request;
    msg >> request;
    cout << request.device << "\t" << request.deviceType << "\t"
        << request.account << "\t" << request.usrsign << endl;

    RoleCommon role = {"TomHagen", 10013, 56, 31, 103450, 2000, 200000, 530};
    auto  officer_list = GetMonsterMatrix(false);

    MSGAccountAuthorizeResponse response;
    response.roleId = 1000;

    CArchive archive;
    archive << role << officer_list;
    archive.Clone(response.data);

    thisServer.GetSocketServer().Send(msg.GetConnector(), response);
}

HandlerMap GetHandlerMap()
{
    //MockFight();

    HandlerMap handlers;
    handlers[MID_ACCOUNT_AUTHORIZE_REQUEST] = HandleUserAuth;
    handlers[MID_CHARACTER_INSTANCE_COMBAT_REQUEST] = HandleCombatRequest;
    return std::move(handlers);
}
