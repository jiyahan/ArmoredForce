#ifndef COMMON_SETUP_ARMYCATEGORY_H
#define COMMON_SETUP_ARMYCATEGORY_H

#include "../Config.h"
#include <map>
#include "../../3rdParty/atom/atom/CAtom.h"

using atom::a_string;

namespace setup {

//
// ���ֽṹ����
//
struct tagArmyCategory
{
    // ���ַ�Ϊ������������������
    enum ArmyType 
    {
        ARMY_ATK = 1, 
        ARMY_DEFENSE = 2, 
        ARMY_ASSIST = 3
    }; 

    a_string      name;           // ����
    ArmyType      type;           // ����
    a_string      picture_id;     // ����ͼƬ
    a_string      animation_id;   // �������
    a_string      general_skill;  // ��ͨ����
    a_string      active_skill;   // ��������
    a_string      passive_skill;  // ��������
    a_string      intro;          // ���ֽ���
    a_string      skill_desc;     // ������������
};

//
// ������ж�
//
inline bool operator == (const tagArmyCategory& lhs, const tagArmyCategory& rhs)
{
    return (lhs.name == rhs.name
        && lhs.type == rhs.type
        && lhs.picture_id == rhs.picture_id
        && lhs.animation_id == rhs.animation_id
        && lhs.general_skill == rhs.general_skill
        && lhs.active_skill == rhs.active_skill
        && lhs.passive_skill == rhs.passive_skill
        && lhs.intro == rhs.intro
        && lhs.skill_desc == rhs.skill_desc);
}

// ���б������Ͷ���
typedef std::map<a_string, tagArmyCategory>     ArmyCategoryList;


//////////////////////////////////////////////////////////////////////////
//
// �������͹���
//
class ArmyCategorySetup : public atom::CSingleton<ArmyCategorySetup>
{
public:
    // �Ӷ������ļ��ж�ȡ��������
    bool    Load(const a_string& path);

    // �������Ʋ��ұ���
    const tagArmyCategory*  GetCategory(const a_string& name) const;

private:
    ArmyCategoryList       categories_;
};


// ���л�֧��
template<typename Archive>
inline void Serialize(Archive& archive, setup::tagArmyCategory& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( (I32&)value.type );
    archive.Bind( value.picture_id );
    archive.Bind( value.animation_id );
    archive.Bind( value.general_skill );
    archive.Bind( value.active_skill );
    archive.Bind( value.passive_skill );
    archive.Bind( value.intro );
    archive.Bind( value.skill_desc );
}

} // namespace setup



#endif // COMMON_SETUP_ARMYCATEGORY_H
