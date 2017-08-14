#ifndef COMMON_SETUP_OFFICERLIST_H
#define COMMON_SETUP_OFFICERLIST_H


#include "../Config.h"
#include <map>
#include "../../3rdParty/atom/atom/CAtom.h"

namespace setup {
    
// ����,��Ƭ
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

    String          name;               // ��������
    String          index;              // ���ٱ��
    String          category;           // ��������
    Quality         quality;            // Ʒ��    
    I32             command_force;      // ָ����
    I32             leadership;         // �쵼��
    I32             base_hp;            // ����Ѫ��
    I32             base_atk;           // ��������
    I32             atk_upgrade;        // �����ɳ�
    I32             base_force;         // ��������
    I32             force_upgrade;      // �����ɳ�
    I32             max_level;          // ���ȼ�
    I32             price;              // ���ۼ۸�
    String          picture_large;      // ��ͼƬ
    String          picture_small;      // СͼƬ
    String          intro;              // ˵������
};


// ���еľ��٣�keyΪ���
typedef std::map<String, tagOfficer>     OfficerList;

class OfficerListSetup : public atom::CSingleton<OfficerListSetup>
{
public:
    // �Ӷ������ļ��м������еľ���
    void    Load(const String& path);

    // ���ݱ�ŵõ�ĳ�����ٵ�����
    const tagOfficer*   GetOfficer(const String& index) const;

private:
    OfficerList      officer_list_;
};

} // namespace setup


template<typename Archive>
inline void Serialize(Archive& archive, setup::tagOfficer& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.category );
    archive.Bind( (I32&)value.quality );
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

#endif // COMMON_SETUP_OFFICERLIST_H
