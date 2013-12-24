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

    String          name;               // 军官名称
    String          index;              // 军官编号
    String          category;           // 部队类型
    Quality         quality;            // 品质    
    I32             command_force;      // 指挥力
    I32             leadership;         // 领导力
    I32             base_hp;            // 基础血量
    I32             base_atk;           // 基础攻击
    I32             atk_upgrade;        // 攻击成长
    I32             base_force;         // 基础兵力
    I32             force_upgrade;      // 兵力成长
    I32             max_level;          // 最大等级
    I32             price;              // 出售价格
    String          picture_large;      // 大图片
    String          picture_small;      // 小图片
    String          intro;              // 说明文字
};


// 所有的军官，key为编号
typedef std::map<String, tagOfficer>     OfficerList;

class OfficerListSetup : public atom::CSingleton<OfficerListSetup>
{
public:
    // 从二进制文件中加载所有的军官
    void    Load(const String& path);

    // 根据编号得到某个军官的配置
    const tagOfficer*   GetOfficer(const String& index) const;

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

#endif // COMMON_SETUP_OFFICERLIST_H
