#pragma once

#include <memory>
#include <string>
#include <cstring>
#include <array>
#include <boost/noncopyable.hpp>
#include "common/Config.h"

// 攻击目标
enum eTarget
{     
    TARGET_NONE = 0,    // 没有目标   
    TARGET_POS1 = 1,    // 1号位
    TARGET_POS2 = 2,    // 2号位
    TARGET_POS3 = 3,    // 3号位
    TARGET_POS4 = 4,    // 4号位
    TARGET_POS5 = 5,    // 5号位
    TARGET_POS6 = 6,    // 6号位
    TARGET_RANDOM = 7,  // 随机目标
};


// 伤害
struct tagAttackPower
{
    I16     attack_type;    // 攻击类型
    I32     last_time;      // 持续时间
    I32     damage;         // 伤害值
};

struct tagAttackResult
{
    I32     damage;         // 造成伤害值
    I16     skill;          // 技能ID
    bool    critical;       // 是否暴击 
};


struct tagSkillProperty
{
    enum {MAX_AOE = GRID_AMOUNT};
    
    std::string     name_;          // 技能名称
    I16             index_;         // 技能ID
    I16             level_;         // 技能等级
    I16             type;           // 技能类型（瞬间伤害，持续伤害，）
    I16             aoe_;           // 伤害范围
    std::array<eTarget, MAX_AOE>  targets;   // 伤害目标
    I32             damage;
};

// 技能
class Skill : private boost::noncopyable
{
public:
    Skill();
    ~Skill();

private:
    tagSkillProperty        property_;
};

typedef std::shared_ptr<Skill>     SkillPtr;
