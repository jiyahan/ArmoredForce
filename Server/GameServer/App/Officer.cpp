#include "Officer.h"
#include "Utility.h"


//////////////////////////////////////////////////////////////////////////
Officer::Officer(const setup::tagOfficer& officer)
{
    data_.name = officer.name;
    data_.category = officer.category;
    data_.id = GetUniqueID().c_str();
    data_.hp = officer.base_force;
    data_.attack = officer.base_atk;
    data_.command_force = officer.command_force;
    data_.leadership = officer.leadership;
    data_.level = 1;
}

Officer::Officer(const setup::tagMonster& monster)
{
    data_.name = monster.name;
    data_.category = monster.category;
    data_.id = GetUniqueID().c_str();
    data_.hp = monster.force;
    data_.attack = monster.attack;
    data_.level = 1;
}

Officer::~Officer()
{
}

I32 Officer::GetHp() const
{
    return data_.hp;
}

void Officer::SetHp(I32 hp)
{
    data_.hp = hp;
}

I32 Officer::GetAttack() const
{
    return data_.attack;
}

U08  Officer::GetPosition() const
{
    return data_.postion;
}

void  Officer::SetPosition(U08 pos)
{
    data_.postion = pos;
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
        I32 damage = min(GetHp(), atk.damage);
        SetHp(GetHp() - damage);
        result.damage = damage;
    }
    return std::move(result);
}
