#include "Officer.h"


Officer::Officer()
{
}

Officer::~Officer()
{
}

int32_t Officer::GetHp() const
{
    return property_.hp;
}

int32_t Officer::GetAttack() const
{
    return property_.accuracy;
}

// 攻击
void Officer::Attack(Officer& defender)
{
}

// 防御
void  Officer::Defense(const tagAttackPower& atk)
{
}
