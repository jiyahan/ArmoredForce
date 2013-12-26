#pragma once

#include <memory>
#include "Skill.h"

class Monster;
typedef std::shared_ptr<Monster>    MonsterPtr;

class Monster
{
public:
    Monster();
    ~Monster();

    // 攻击某个
    void    Attack(MonsterPtr defender);
    void    Defense(SkillPtr skill);

private:

};


