#ifndef CHGAME_RoleCommon_H
#define CHGAME_RoleCommon_H

#include "Config.h"
#include "OfficerCommon.h"
#include "../3rdparty/atom/atom/catom.h"

using namespace atom;


//��ɫ��������
struct RoleCommon
{	
	a_string    name;           // ��ɫ��
    I32         id;             // Ψһ���
    I16         level;          // �ȼ�
    I16         title;          // ����
    I32         exp;            // ����
    I32         action_point;   // �ж���
    I32         gold;           // ��Ǯ
    I32         gems;           // ��ʯ

    std::vector<OfficerCommon>  officer_list;   // ��ɫӵ�еľ���
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