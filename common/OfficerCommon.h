#ifndef COMMON_OFFICERCOMMON_H
#define COMMON_OFFICERCOMMON_H

#include "Config.h"
#include "../3rdParty/atom/atom/CAtom.h"


// 军官基本属性
struct OfficerCommon
{
    a_string    name;           // 名称
    a_string    category;       // 兵种
    I32         id;             // 编号
    I16         level;          // 等级
    U08         postion;        // 当前所在位置(1-6)
    I32         attack;         // 攻击
    I32         hp;             // 血量(兵力)
    I32         blast;          // 暴击
    I32         accuracy;       // 精准 
    I32         command_force;  // 指挥力
    I32         leadership;     // 统率力
};

typedef std::vector<OfficerCommon, atom_allocator<OfficerCommon>>  OfficerCommonList ;

template<class Archive>
inline void Serialize(Archive& ar, OfficerCommon& value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	ar.Bind( value.name);
    ar.Bind( value.category);
    ar.Bind( value.id);
    ar.Bind( value.level);
    ar.Bind( value.postion);
    ar.Bind( value.attack);
    ar.Bind( value.hp);
    ar.Bind( value.blast);
    ar.Bind( value.accuracy);
    ar.Bind( value.command_force);
    ar.Bind( value.leadership);
}

#endif // COMMON_OFFICERCOMMON_H
