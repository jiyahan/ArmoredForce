#ifndef COMMON_SETUP_ARMYCATEGORY_H
#define COMMON_SETUP_ARMYCATEGORY_H


#include <cstdint>
#include <string>
#include <unordered_map>

namespace setup {

// 兵种
struct tagArmyCategory
{
    // 兵种分为：攻击，防御，辅助
    enum ArmyType 
    {
        ARMY_ATK = 1, 
        ARMY_DEFENSE = 2, 
        ARMY_ASSIST = 3
    }; 

    std::string      name;           // 名称
    ArmyType         type;           // 类型
    std::string      picture_id;     // 兵种图片
    std::string      animation_id;   // 动画编号
    std::string      general_skill;  // 普通技能
    std::string      active_skill;   // 主动技能
    std::string      passive_skill;  // 被动技能
    std::string      intro;          // 兵种介绍
    std::string      skill_desc;     // 主动技能描述
};

// 所有的兵种，key为名称
typedef std::unordered_map<std::string, tagArmyCategory>     ArmyCategoryMap;

} // namespace setup



template<class Archive>
inline void Serialize(Archive& archive, setup::tagArmyCategory& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( (int32_t&)value.type );
    archive.Bind( value.picture_id );
    archive.Bind( value.animation_id );
    archive.Bind( value.general_skill );
    archive.Bind( value.active_skill );
    archive.Bind( value.passive_skill );
    archive.Bind( value.intro );
    archive.Bind( value.skill_desc );
}


#endif // COMMON_SETUP_ARMYCATEGORY_H
