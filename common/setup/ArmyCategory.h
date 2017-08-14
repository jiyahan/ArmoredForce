#ifndef COMMON_SETUP_ARMYCATEGORY_H
#define COMMON_SETUP_ARMYCATEGORY_H

#include "../Config.h"
#include <map>
#include "../../3rdParty/atom/atom/CAtom.h"


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

    String      name;           // ����
    ArmyType    type;           // ����
    String      picture_id;     // ����ͼƬ
    String      animation_id;   // �������
    String      general_skill;  // ��ͨ����
    String      active_skill;   // ��������
    String      passive_skill;  // ��������
    String      intro;          // ���ֽ���
    String      skill_desc;     // ������������
};

// ���б������Ͷ���
typedef std::map<String, tagArmyCategory>     ArmyCategoryList;


//////////////////////////////////////////////////////////////////////////
//
// �������͹���
//
class ArmyCategorySetup : public atom::CSingleton<ArmyCategorySetup>
{
public:
    // �Ӷ������ļ��ж�ȡ��������
    void    Load(const String& path);

    // �������Ʋ��ұ���
    const tagArmyCategory&  GetCategory(const String& name) const;

private:
    ArmyCategoryList       categories_;
};

} // namespace setup


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

#endif // COMMON_SETUP_ARMYCATEGORY_H
