#ifndef CHGAME_RoleCommon_H
#define CHGAME_RoleCommon_H

#include "Config.h"
#include "../3rdParty/atom/atom/CAtom.h"

using namespace atom;


//角色基本属性
struct RoleCommon
{	
	String  name;           // 角色名
    I32     id;             // 角色ID
    I16     level;          // 角色等级
    I16     official_title; // 军衔等级
    I32     exp;            // 角色经验
    I32     action_point;   // 行动力
    I32     money;          // 金钱
    I32     gems;           // 钻石数量
};

template<class Archive>
inline void Serialize(Archive & archive, RoleCommon & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.name);
    archive.Bind( value.id);
    archive.Bind( value.level);
    archive.Bind( value.official_title);
    archive.Bind( value.exp);
    archive.Bind( value.action_point);
    archive.Bind( value.money);
    archive.Bind( value.gems);
}

#endif