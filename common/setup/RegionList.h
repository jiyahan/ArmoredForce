#ifndef COMMON_SETUP_REGIONLIST_H
#define COMMON_SETUP_REGIONLIST_H

#include "../Config.h"
#include <map>
#include <array>
#include "../../3rdParty/atom/atom/CAtom.h"

namespace setup {

// 胜利后获得奖励配置
struct tagPrize
{
    a_string   name;       // 奖励物品名称
    a_string   index;      // 奖励物品编号
    I32        count;      // 奖励物品数量
};


// 战斗中的三个阶段配置
struct tagRegionStage
{
    // 6个怪物
    std::array<a_string, GRID_AMOUNT>  monsters;

    // 奖励
    std::vector<tagPrize>    prize;
};

// 地图配置
struct tagRegion
{
    a_string      name;       // 名称
    a_string      index;      // 编号
    I32           type;
    a_string      picture;    // 背景图片

    // 三个阶段
    enum {MAX_STAGE = 3};
    std::array<tagRegionStage, MAX_STAGE>  stages;
};

//
// 相等性判断
//
inline bool operator == (const setup::tagPrize& lhs, const setup::tagPrize& rhs)
{
    return (lhs.name == rhs.name 
        && lhs.index == rhs.index
        && lhs.count == rhs.count);
}

inline bool operator == (const setup::tagRegionStage& lhs, const setup::tagRegionStage& rhs)
{
    return (lhs.monsters == rhs.monsters
        && lhs.prize == rhs.prize);
}

inline bool operator == (const setup::tagRegion& lhs, const setup::tagRegion& rhs)
{
    return (lhs.name == rhs.name
        && lhs.index == rhs.index
        && lhs.type == rhs.type
        && lhs.picture == rhs.picture
        && lhs.stages == rhs.stages);
}

typedef std::map<a_string, tagRegion>     RegionList;

//////////////////////////////////////////////////////////////////////////
//
// 所有地图配置
//
class RegionListSetup : public atom::CSingleton<RegionListSetup>
{
public:
    // 从二进制文件中加载地图
    bool    Load(const a_string& path);

    // 根据名称查找地图
    const tagRegion*  GetRegion(const a_string& name) const;

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
    for (auto& item : value.monsters)
    {
        archive.Bind( item );
    }
    Serialize(archive, value.prize, isSave);
}


template<typename Archive>
inline void Serialize(Archive& archive, setup::tagRegion& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.type );
    archive.Bind( value.picture );
    for (auto& stage : value.stages)
    {
        Serialize(archive, stage, isSave);
    }
}



#endif // COMMON_SETUP_REGIONLIST_H
