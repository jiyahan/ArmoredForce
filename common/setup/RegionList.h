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
    // 6个位置的卡片
    a_string   pos_1;
    a_string   pos_2;
    a_string   pos_3;
    a_string   pos_4;
    a_string   pos_5;
    a_string   pos_6;

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
    return (lhs.pos_1 == rhs.pos_1
        && lhs.pos_2 == rhs.pos_2
        && lhs.pos_3 == rhs.pos_3
        && lhs.pos_4 == rhs.pos_4
        && lhs.pos_5 == rhs.pos_5
        && lhs.pos_6 == rhs.pos_6
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
    archive.Bind( value.type );
    archive.Bind( value.picture );
    for (auto& stage : value.stages)
    {
        Serialize(archive, stage, isSave);
    }
}



#endif // COMMON_SETUP_REGIONLIST_H
