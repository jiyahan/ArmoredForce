#ifndef CHGAME_RoleCommon_H
#define CHGAME_RoleCommon_H

// linux下仅支持`/`作为路径分隔符
#include "../3rdparty/atom/atom/catom.h"

using namespace atom;


//角色基本属性
struct RoleCommon
{
	//角色名
	a_string name;
};

template<class Archive>
inline void Serialize(Archive & archive, RoleCommon & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.name);
}

#endif