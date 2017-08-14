#ifndef CHGAME_RoleCommon_H
#define CHGAME_RoleCommon_H

#include "Config.h"
#include "../3rdparty/atom/atom/catom.h"

using namespace atom;


//��ɫ��������
struct RoleCommon
{
	//��ɫ��
	String name;
};

template<class Archive>
inline void Serialize(Archive & archive, RoleCommon & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.name);
}

#endif