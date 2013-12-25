#ifndef COMMON_OFFICERCOMMON_H
#define COMMON_OFFICERCOMMON_H

#include "Config.h"
#include "../3rdParty/atom/atom/CAtom.h"


// 军官基本属性
struct OfficerCommon
{
    a_string    name;           // 名称
    I32         id;             // 编号
    I16         level;          // 等级
    I32         attack;         // 攻击
    I32         force;          // 兵力(血量)
    I32         blast;          // 暴击
    I32         accuracy;       // 精准 
    I32         command_force;  // 指挥力
    I32         leadership;     // 统率力
};

template<class Archive>
inline void Serialize(Archive& ar, OfficerCommon& value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	ar.Bind( value.name);
    ar.Bind( value.id);
    ar.Bind( value.level);
    ar.Bind( value.attack);
    ar.Bind( value.force);
    ar.Bind( value.blast);
    ar.Bind( value.accuracy);
    ar.Bind( value.command_force);
    ar.Bind( value.leadership);
}

#endif // COMMON_OFFICERCOMMON_H
