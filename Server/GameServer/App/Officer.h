#pragma once

#include <memory>
#include "Skill.h"
#include "common/OfficerCommon.h"


class Officer;
typedef std::shared_ptr<Officer>    OfficerPtr;


// 军官
class Officer
{
public:
    Officer();
    ~Officer();

    int32_t     GetHp() const;
    int32_t     GetAttack() const;

    bool    IsDead() const {return GetHp() > 0;}

    // 攻击
    void    Attack(Officer& defender);

    // 防御
    void    Defense(const tagAttackPower& atk);

private:
    OfficerCommon           property_;          // 基础属性
    SkillPtr                current_skill_;     // 当前技能
    std::vector<SkillPtr>   skill_list_;        // 技能列表
};



