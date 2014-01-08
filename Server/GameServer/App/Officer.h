#pragma once

#include <memory>
#include <boost/noncopyable.hpp>
#include "common/setup/MonsterList.h"
#include "common/setup/OfficerList.h"
#include "common/OfficerCommon.h"
#include "Skill.h"


class Officer;
typedef std::shared_ptr<Officer>    OfficerPtr;

// 军官
class Officer : boost::noncopyable
{
public:
    explicit Officer(const setup::tagOfficer& officer);
    explicit Officer(const setup::tagMonster& monster);

    ~Officer();

    // 兵力(血量)
    I32     GetHp() const {return data_.hp;}
    void    SetHp(I32 hp) {data_.hp = hp;}
    bool    IsDead() const {return GetHp() <= 0;}

    const std::string& GetName() {return data_.name;};

    // 攻击力
    I32     GetAttack() const {return data_.attack;}

    // 所在位置
    U08     GetPosition() const {return data_.postion;}
    void    SetPosition(U08 pos) {data_.postion = pos;}
    
    // 攻击对方，返回伤害
    tagAttackResult     Attack(Officer& defender);

    // 防御
    tagAttackResult     Defense(const tagAttackPower& atk);

private:
    OfficerCommon           data_;          // 基础属性
    //SkillPtr                current_skill_;     // 当前技能
    //std::vector<SkillPtr>   skill_list_;        // 技能列表
};



