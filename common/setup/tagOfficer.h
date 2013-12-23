#ifndef COMMON_SETUP_OFFICER_H
#define COMMON_SETUP_OFFICER_H

#include <cstdint>
#include <string>
#include <map>

namespace setup {
    
// 军官，即卡片或者怪物
struct tagOfficer
{
    // 卡片的品质
    enum Quality 
    {
        CARD_WHITE = 1,     // 白色品质
        CARD_BLUE = 2,      // 蓝色品质
        CARD_YELLOW = 3,    // 黄色品质
        CARD_GREEN = 4,     // 绿色品质
        CARD_PURPLE = 5,    // 紫色品质
        CARD_ORANGE = 6,    // 橙色品质
    }; 

    std::string     name;               // 军官名称
    std::string     index;              // 军官编号
    std::string     category;           // 部队类型
    Quality         quality;            // 品质    
    int32_t         command_force;      // 指挥力
    int32_t         leadership;         // 领导力
    int32_t         base_hp;            // 基础血量
    int32_t         base_atk;           // 基础攻击
    int32_t         atk_upgrade;        // 攻击成长
    int32_t         base_force;         // 基础兵力
    int32_t         force_upgrade;      // 兵力成长
    int32_t         max_level;          // 最大等级
    int32_t         price;              // 出售价格
    std::string     picture_large;      // 大图片
    std::string     picture_small;      // 小图片
    std::string     intro;              // 说明文字
};


// 所有的军官，key为编号
typedef std::map<std::string, tagOfficer>     OfficerMap;

} // namespace setup


template<typename Archive>
inline void Serialize(Archive& archive, setup::tagOfficer& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.category );
    archive.Bind( (int32_t&)value.quality );
    archive.Bind( value.command_force );
    archive.Bind( value.base_hp );
    archive.Bind( value.base_atk );
    archive.Bind( value.atk_upgrade );
    archive.Bind( value.base_force );
    archive.Bind( value.force_upgrade );
    archive.Bind( value.max_level );
    archive.Bind( value.price );
    archive.Bind( value.picture_large );
    archive.Bind( value.picture_small );
    archive.Bind( value.intro );
}

#endif // COMMON_SETUP_OFFICER_H
