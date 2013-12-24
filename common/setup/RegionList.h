#ifndef COMMON_SETUP_REGIONLIST_H
#define COMMON_SETUP_REGIONLIST_H

#include "../Config.h"
#include <map>
#include <array>
#include "../3rdParty/atom/atom/CAtom.h"

namespace setup {

// 胜利后获得奖励配置
struct tagPrize
{
    String     name;       // 奖励物品名称
    String     index;      // 奖励物品编号
    I32        count;      // 奖励物品数量
};


// 战斗中的三个阶段配置
struct tagRegionStage
{
    // 6个位置的卡片
    String   pos_1;
    String   pos_2;
    String   pos_3;
    String   pos_4;
    String   pos_5;
    String   pos_6;

    tagPrize    prize;
};

// 地图配置
struct tagRegion
{
    String      name;       // 名称
    String      index;      // 编号
    String      picture;    // 背景图片

    // 三个阶段
    enum {MAX_STAGE = 3};
    std::array<tagRegionStage, MAX_STAGE>  stages;
};


typedef std::map<String, tagRegion>     RegionList;

//////////////////////////////////////////////////////////////////////////
//
// 所有地图配置
//
class RegionListSetup : public atom::CSingleton<RegionListSetup>
{
public:
    // 从二进制文件中加载地图
    void    Load(const String& path);

    // 根据名称查找地图
    const tagRegion&  GetRegion(const String& name) const;

private:
    RegionList       regions_;
};

} // namespace setup


template<typename Archive>
inline void Serialize(Archive& archive, setup::tagPrize& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.count );
}

template<typename Archive>
inline void Serialize(Archive& archive, setup::tagRegionStage& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.pos_1 );
    archive.Bind( value.pos_2 );
    archive.Bind( value.pos_3 );
    archive.Bind( value.pos_4 );
    archive.Bind( value.pos_5 );
    archive.Bind( value.pos_6 );
    Serialize(archive, value.prize, isSave);
}


template<typename Archive>
inline void Serialize(Archive& archive, setup::tagRegion& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.picture );
    for (const auto& item : value.stages)
    {
        //Serialize(archive, item, isSave);
    }
}

#endif // COMMON_SETUP_REGIONLIST_H
