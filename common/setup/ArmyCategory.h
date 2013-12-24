#ifndef COMMON_SETUP_ARMYCATEGORY_H
#define COMMON_SETUP_ARMYCATEGORY_H

#include "../Config.h"
#include <map>
#include "../../3rdParty/atom/atom/CAtom.h"


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

    String      name;           // 名称
    ArmyType    type;           // 类型
    String      picture_id;     // 兵种图片
    String      animation_id;   // 动画编号
    String      general_skill;  // 普通技能
    String      active_skill;   // 主动技能
    String      passive_skill;  // 被动技能
    String      intro;          // 兵种介绍
    String      skill_desc;     // 主动技能描述
};

// 所有兵种类型定义
typedef std::map<String, tagArmyCategory>     ArmyCategoryList;


//////////////////////////////////////////////////////////////////////////
//
// 兵种类型管理
//
class ArmyCategorySetup : public atom::CSingleton<ArmyCategorySetup>
{
public:
    // 从二进制文件中读取兵种配置
    void    Load(const String& path);

    // 根据名称查找兵种
    const tagArmyCategory&  GetCategory(const String& name) const;

private:
    ArmyCategoryList       categories_;
};

} // namespace setup


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

#endif // COMMON_SETUP_ARMYCATEGORY_H
