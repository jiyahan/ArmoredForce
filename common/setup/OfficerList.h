#ifndef COMMON_SETUP_OFFICERLIST_H
#define COMMON_SETUP_OFFICERLIST_H


#include "../Config.h"
#include <map>
#include "../../3rdParty/atom/atom/CAtom.h"

namespace setup {
    
// 军官,卡片
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

    a_string        name;               // 军官名称
    a_string        index;              // 军官编号
    a_string        category;           // 部队类型
    Quality         quality;            // 品质
    I32             command_force;      // 指挥力
    I32             leadership;         // 领导力
    I32             base_atk;           // 基础攻击
    I32             atk_upgrade;        // 攻击成长
    I32             base_force;         // 基础兵力
    I32             force_upgrade;      // 兵力成长
    I32             max_level;          // 最大等级
    I32             price;              // 出售价格
    a_string        picture_large;      // 大图片
    a_string        picture_small;      // 小图片
    a_string        intro;              // 说明文字
};

//
// 相等性判断
//
inline bool operator == (const tagOfficer& lhs, const tagOfficer& rhs)
{
    return (lhs.name == rhs.name 
        && lhs.index == rhs.index
        && lhs.category == rhs.category
        && lhs.quality == rhs.quality
        && lhs.command_force == rhs.command_force
        && lhs.leadership == rhs.leadership
        && lhs.base_atk == rhs.base_atk
        && lhs.atk_upgrade == rhs.atk_upgrade
        && lhs.base_force == rhs.base_force
        && lhs.force_upgrade == rhs.force_upgrade
        && lhs.max_level == rhs.max_level
        && lhs.price == rhs.price
        && lhs.picture_large == rhs.picture_large
        && lhs.picture_small == rhs.picture_small
        && lhs.intro == rhs.intro);
}


// 所有的军官，key为编号
typedef std::map<a_string, tagOfficer>     OfficerList;

class OfficerListSetup : public atom::CSingleton<OfficerListSetup>
{
public:
    // 从二进制文件中加载所有的军官
    bool    Load(const a_string& path);

    // 根据编号得到某个军官的配置
    const tagOfficer*   GetOfficer(const a_string& index) const;

    // 获得所有军官列表
    const OfficerList&  GetOfficerList() const {return officer_list_;}

private:
    OfficerList      officer_list_;
};

} // namespace setup


template<typename Archive>
inline void Serialize(Archive& archive, setup::tagOfficer& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.category );
    archive.Bind( (I32&)value.quality );
    archive.Bind( value.command_force );
    archive.Bind( value.leadership );
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

#endif // COMMON_SETUP_OFFICERLIST_H
