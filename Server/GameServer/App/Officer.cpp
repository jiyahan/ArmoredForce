#include "Officer.h"
#include "Utility.h"
#include "common/setup/MonsterList.h"
#include "common/setup/OfficerList.h"

//////////////////////////////////////////////////////////////////////////
Officer::Officer(const setup::tagOfficer& officer)
    : is_monster_(false)
{
    data_.name = officer.name;
    data_.category = officer.category;
    data_.id = CreateUniqueID();
    data_.hp = officer.base_force;
    data_.attack = officer.base_atk;
    data_.command_force = officer.command_force;
    data_.leadership = officer.leadership;
    data_.level = 1;
}

Officer::Officer(const setup::tagMonster& monster)
    : is_monster_(true)
{
    data_.name = monster.name;
    data_.category = monster.category;
    data_.id = CreateUniqueID();
    data_.hp = monster.force;
    data_.attack = monster.attack;
    data_.level = 1;
}

Officer::~Officer()
{
}



// 攻击
tagAttackResult Officer::Attack(Officer& defender)
{
    if (!IsDead())
    {
        tagAttackPower atk = {};
        atk.damage = GetAttack();
        return defender.Defense(atk);
    }
    return tagAttackResult();
}

// 防御
tagAttackResult  Officer::Defense(const tagAttackPower& atk)
{
    tagAttackResult result = {};
    if (!IsDead())
    {
        int32_t damage = min(GetHp(), atk.damage);
        SetHp(GetHp() - damage);
        result.damage = damage;
    }
    return std::move(result);
}
