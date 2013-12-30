#ifndef COMMON_SETUP_ARMYCATEGORY_H
#define COMMON_SETUP_ARMYCATEGORY_H

#include "../Config.h"
#include <map>
#include "../../3rdParty/atom/atom/CAtom.h"

using atom::a_string;

namespace setup {

//
// 兵种结构定义
//
struct tagArmyCategory
{
    // 兵种分为：攻击，防御，辅助
    enum ArmyType 
    {
        ARMY_ATK = 1, 
        ARMY_DEFENSE = 2, 
        ARMY_ASSIST = 3
    }; 

    a_string      name;           // 名称
    ArmyType      type;           // 类型
    a_string      picture_id;     // 兵种图片
    a_string      animation_id;   // 动画编号
    a_string      general_skill;  // 普通技能
    a_string      active_skill;   // 主动技能
    a_string      passive_skill;  // 被动技能
    a_string      intro;          // 兵种介绍
    a_string      skill_desc;     // 主动技能描述
};

//
// 相等性判断
//
inline bool operator == (const tagArmyCategory& lhs, const tagArmyCategory& rhs)
{
    return (lhs.name == rhs.name
        && lhs.type == rhs.type
        && lhs.picture_id == rhs.picture_id
        && lhs.animation_id == rhs.animation_id
        && lhs.general_skill == rhs.general_skill
        && lhs.active_skill == rhs.active_skill
        && lhs.passive_skill == rhs.passive_skill
        && lhs.intro == rhs.intro
        && lhs.skill_desc == rhs.skill_desc);
}

// 所有兵种类型定义
typedef std::map<a_string, tagArmyCategory>     ArmyCategoryList;


//////////////////////////////////////////////////////////////////////////
//
// 兵种类型管理
//
class ArmyCategorySetup : public atom::CSingleton<ArmyCategorySetup>
{
public:
    // 从二进制文件中读取兵种配置
    bool    Load(const a_string& path);

    // 根据名称查找兵种
    const tagArmyCategory*  GetCategory(const a_string& name) const;

private:
    ArmyCategoryList       categories_;
};


// 序列化支持
template<typename Archive>
inline void Serialize(Archive& archive, setup::tagArmyCategory& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( (I32&)value.type );
    archive.Bind( value.picture_id );
    archive.Bind( value.animation_id );
    archive.Bind( value.general_skill );
    archive.Bind( value.active_skill );
    archive.Bind( value.passive_skill );
    archive.Bind( value.intro );
    archive.Bind( value.skill_desc );
}

} // namespace setup



#endif // COMMON_SETUP_ARMYCATEGORY_H
