#ifndef CHGAME_RoleCommon_H
#define CHGAME_RoleCommon_H

// linux�½�֧��`/`��Ϊ·���ָ���
#include "../3rdparty/atom/atom/catom.h"

using namespace atom;


//��ɫ��������
struct RoleCommon
{
	//��ɫ��
	a_string name;
};

template<class Archive>
inline void Serialize(Archive & archive, RoleCommon & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.name);
}

#endif