#pragma once

#include <memory>
#include <boost/noncopyable.hpp>
#include "common/OfficerCommon.h"
#include "Skill.h"

// 前向声明
namespace setup {
    struct tagOfficer;
    struct tagMonster;
}

class Officer;
typedef std::shared_ptr<Officer>    OfficerPtr;

// 军官
class Officer : boost::noncopyable
{
public:
    // 从军官配置构造
    explicit Officer(const setup::tagOfficer& officer);

    // 从怪物配置构造
    explicit Officer(const setup::tagMonster& monster);

    ~Officer();

    // 兵力(血量)
    int32_t     GetHp() const {return data_.hp;}
    void        SetHp(uint32_t hp) {data_.hp = hp;}
    bool        IsDead() const {return GetHp() <= 0;}

    // 等级
    int16_t     GetLevel() const {return data_.level;}
    void        SetLevel(int16_t level) {data_.level = level;}

    const std::string& GetName() {return data_.name;}

    // 此军官的UUID
    const std::string& GetUniqueID() {return data_.id;}

    // 攻击力
    uint32_t    GetAttack() const {return data_.attack;}

    // 所在位置
    uint8_t     GetPosition() const {return data_.postion;}
    void        SetPosition(uint8_t pos) {data_.postion = pos;}
    
    // 是否是PVE怪物
    bool        IsMonster() const {return is_monster_;}

    // 攻击对方，返回伤害
    tagAttackResult     Attack(Officer& defender);

    // 防御
    tagAttackResult     Defense(const tagAttackPower& atk);

private:
    OfficerCommon       data_;              // 基础属性
    const bool          is_monster_;        // 是否是PVE怪物
    //SkillPtr                current_skill_;     // 当前技能
    //std::vector<SkillPtr>   skill_list_;        // 技能列表
};



