#pragma once

#include "common/OfficerCommon.h"
#include "Skill.h"


// 军官
class Officer
{
public:
    Officer();
    ~Officer();

    // 兵力(血量)
    I32     GetHp() const;
    void    SetHp(I32 hp);
    bool    IsDead() const {return GetHp() > 0;}

    // 攻击力
    I32     GetAttack() const;

    I16     GetPosition() const ;
    void    SetPosition(I16 pos);
    
    // 攻击对方，返回伤害
    tagAttackResult     Attack(Officer& defender);

    // 防御
    tagAttackResult     Defense(const tagAttackPower& atk);

private:
    OfficerCommon           data_;          // 基础属性
    //SkillPtr                current_skill_;     // 当前技能
    //std::vector<SkillPtr>   skill_list_;        // 技能列表
};



