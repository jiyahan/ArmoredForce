#ifndef COMMON_SETUP_OFFICER_H
#define COMMON_SETUP_OFFICER_H

#include <cstdint>
#include <string>
#include <map>

namespace setup {
    
// ���٣�����Ƭ���߹���
struct tagOfficer
{
    // ��Ƭ��Ʒ��
    enum Quality 
    {
        CARD_WHITE = 1,     // ��ɫƷ��
        CARD_BLUE = 2,      // ��ɫƷ��
        CARD_YELLOW = 3,    // ��ɫƷ��
        CARD_GREEN = 4,     // ��ɫƷ��
        CARD_PURPLE = 5,    // ��ɫƷ��
        CARD_ORANGE = 6,    // ��ɫƷ��
    }; 

    std::string     name;               // ��������
    std::string     index;              // ���ٱ��
    std::string     category;           // ��������
    Quality         quality;            // Ʒ��    
    int32_t         command_force;      // ָ����
    int32_t         leadership;         // �쵼��
    int32_t         base_hp;            // ����Ѫ��
    int32_t         base_atk;           // ��������
    int32_t         atk_upgrade;        // �����ɳ�
    int32_t         base_force;         // ��������
    int32_t         force_upgrade;      // �����ɳ�
    int32_t         max_level;          // ���ȼ�
    int32_t         price;              // ���ۼ۸�
    std::string     picture_large;      // ��ͼƬ
    std::string     picture_small;      // СͼƬ
    std::string     intro;              // ˵������
};


// ���еľ��٣�keyΪ���
typedef std::map<std::string, tagOfficer>     OfficerMap;

} // namespace setup


template<typename Archive>
inline void Serialize(Archive& archive, setup::tagOfficer& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.category );
    archive.Bind( (int32_t&)value.quality );
    archive.Bind( value.command_force );
    archive.Bind( value.base_hp );
    archive.Bind( value.base_atk );
    archive.Bind( value.atk_upgrade );
    archive.Bind( value.base_force );
    archive.Bind( value.force_upgrade );
    archive.Bind( value.max_level );
    archive.Bind( value.price );
    archive.Bind( value.picture_large );
    archive.Bind( value.picture_small );
    archive.Bind( value.intro );
}

#endif // COMMON_SETUP_OFFICER_H
