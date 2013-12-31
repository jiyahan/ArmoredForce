#include "Officer.h"


Officer::Officer()
{
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
    return data_.accuracy;
}

I16  Officer::GetPosition() const
{
    return data_.postion;
}

void  Officer::SetPosition(I16 pos)
{
    data_.postion = (U08)pos;
}

// 攻击
tagAttackResult Officer::Attack(Officer& defender)
{
    if (IsDead())
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
        SetHp(damage);
        result.damage = damage;
    }
    return result;
}
