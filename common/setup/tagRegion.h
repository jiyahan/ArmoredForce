#ifndef COMMON_SETUP_REGION_H
#define COMMON_SETUP_REGION_H

#include <cstdint>
#include <string>
#include <map>
#include <array>

namespace setup {

// 胜利后获得奖励
struct tagPrize
{
    std::string     name;       // 奖励物品名称
    std::string     index;      // 奖励物品编号
    int32_t         count;      // 奖励物品数量
};


// 三个阶段
struct tagRegionStage
{
    // 6个位置的卡片
    std::string   pos_1;
    std::string   pos_2;
    std::string   pos_3;
    std::string   pos_4;
    std::string   pos_5;
    std::string   pos_6;

    tagPrize    prize;
};

// 地图
struct tagRegion
{
    std::string      name;       // 名称
    std::string      index;      // 编号
    std::string      picture;    // 背景图片

    // 三个阶段
    enum {MAX_STAGE = 3};
    std::array<tagRegionStage, MAX_STAGE>  stages;
};

// 所有的地图配置，key为编号
typedef std::map<std::string, tagRegion>     RegionMap;

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
    for (int i = 0; i < tagRegion::MAX_STAGE; ++i)
    {
        Serialize(archive, value.stages[i], isSave);
    }
}

#endif // COMMON_SETUP_REGION_H
