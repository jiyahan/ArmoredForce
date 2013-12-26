#ifndef CHGAME_RoleCommon_H
#define CHGAME_RoleCommon_H

#include "Config.h"
#include "OfficerCommon.h"
#include "../3rdparty/atom/atom/catom.h"

using namespace atom;


//角色基本属性
struct RoleCommon
{	
	a_string    name;           // 角色名
    I32         id;             // 唯一编号
    I16         level;          // 等级
    I16         title;          // 军衔
    I32         exp;            // 经验
    I32         action_point;   // 行动力
    I32         gold;           // 金钱
    I32         gems;           // 钻石

    std::vector<OfficerCommon>  officer_list;   // 角色拥有的军官
};

template<class Archive>
inline void Serialize(Archive & archive, RoleCommon & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.name);
    archive.Bind( value.id);
    archive.Bind( value.level);
    archive.Bind( value.title);
    archive.Bind( value.exp);
    archive.Bind( value.action_point);
    archive.Bind( value.gold);
    archive.Bind( value.gems);
    archive.Bind( value.officer_list );
}

#endif