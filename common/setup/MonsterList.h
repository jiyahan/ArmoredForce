#ifndef COMMON_SETUP_MONSTERLIST_H
#define COMMON_SETUP_MONSTERLIST_H

#include "../Config.h"
#include <map>
#include "../3rdParty/atom/atom/CAtom.h"

namespace setup {
    
// ����������
struct tagDropThing
{
    String      index;  // ���
    I32         num;    // ����
    I32         rate;   // ����
};

// ����,��Ƭ
struct tagMonster
{
    String          name;               // ��������
    String          index;              // ������
    String          category;           // �������� 
    I32             type;               // ��������
    I32             attack;             // ����
    I32             force;              // ����
    I32             blast;              // ����
    I32             accuracy;           // ��׼

    vector<tagDropThing> drop_things;   // ����
};


// ���еľ��٣�keyΪ���
typedef std::map<String, tagMonster>     MonsterList;

class MonsterListSetup : public atom::CSingleton<MonsterListSetup>
{
public:
    // �Ӷ������ļ��м������еľ���
    void    Load(const String& path);

    // ���ݱ�ŵõ�ĳ�����ٵ�����
    const tagMonster&   GetMonster(const String& index) const;

private:
    MonsterList      monster_list_;
};

} // namespace setup

template<typename Archive>
inline void Serialize(Archive& archive, setup::tagDropThing& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.index );
    archive.Bind( value.num );
    archive.Bind( value.rate );
}


template<typename Archive>
inline void Serialize(Archive& archive, setup::tagMonster& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.category );
    archive.Bind( value.type );
    archive.Bind( value.attack );
    archive.Bind( value.force );
    archive.Bind( value.blast );
    archive.Bind( value.accuracy );
    archive.Bind( value.drop_things );
}

#endif // COMMON_SETUP_MONSTERLIST_H
