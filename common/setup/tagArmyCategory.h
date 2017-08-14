#ifndef COMMON_SETUP_ARMYCATEGORY_H
#define COMMON_SETUP_ARMYCATEGORY_H


#include <cstdint>
#include <string>
#include <unordered_map>

namespace setup {

// ����
struct tagArmyCategory
{
    // ���ַ�Ϊ������������������
    enum ArmyType 
    {
        ARMY_ATK = 1, 
        ARMY_DEFENSE = 2, 
        ARMY_ASSIST = 3
    }; 

    std::string      name;           // ����
    ArmyType         type;           // ����
    std::string      picture_id;     // ����ͼƬ
    std::string      animation_id;   // �������
    std::string      general_skill;  // ��ͨ����
    std::string      active_skill;   // ��������
    std::string      passive_skill;  // ��������
    std::string      intro;          // ���ֽ���
    std::string      skill_desc;     // ������������
};

// ���еı��֣�keyΪ����
typedef std::unordered_map<std::string, tagArmyCategory>     ArmyCategoryMap;

} // namespace setup



template<class Archive>
inline void Serialize(Archive& archive, setup::tagArmyCategory& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( (int32_t&)value.type );
    archive.Bind( value.picture_id );
    archive.Bind( value.animation_id );
    archive.Bind( value.general_skill );
    archive.Bind( value.active_skill );
    archive.Bind( value.passive_skill );
    archive.Bind( value.intro );
    archive.Bind( value.skill_desc );
}


#endif // COMMON_SETUP_ARMYCATEGORY_H
