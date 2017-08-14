#ifndef COMMON_OFFICERCOMMON_H
#define COMMON_OFFICERCOMMON_H

#include "Config.h"
#include "../3rdParty/atom/atom/CAtom.h"


// ���ٻ�������
struct OfficerCommon
{
    a_string    name;           // ����
    a_string    category;       // ����
    I32         id;             // ���
    I16         level;          // �ȼ�
    U08         postion;        // ��ǰ����λ��(1-6)
    I32         attack;         // ����
    I32         hp;             // Ѫ��(����)
    I32         blast;          // ����
    I32         accuracy;       // ��׼ 
    I32         command_force;  // ָ����
    I32         leadership;     // ͳ����
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
