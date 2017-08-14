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

    a_string        name;               // ��������
    a_string        index;              // ���ٱ��
    a_string        category;           // ��������
    Quality         quality;            // Ʒ��
    I32             command_force;      // ָ����
    I32             leadership;         // �쵼��
    I32             base_atk;           // ��������
    I32             atk_upgrade;        // �����ɳ�
    I32             base_force;         // ��������
    I32             force_upgrade;      // �����ɳ�
    I32             max_level;          // ���ȼ�
    I32             price;              // ���ۼ۸�
    a_string        picture_large;      // ��ͼƬ
    a_string        picture_small;      // СͼƬ
    a_string        intro;              // ˵������
};

//
// ������ж�
//
inline bool operator == (const tagOfficer& lhs, const tagOfficer& rhs)
{
    return (lhs.name == rhs.name 
        && lhs.index == rhs.index
        && lhs.category == rhs.category
        && lhs.quality == rhs.quality
        && lhs.command_force == rhs.command_force
        && lhs.leadership == rhs.leadership
        && lhs.base_atk == rhs.base_atk
        && lhs.atk_upgrade == rhs.atk_upgrade
        && lhs.base_force == rhs.base_force
        && lhs.force_upgrade == rhs.force_upgrade
        && lhs.max_level == rhs.max_level
        && lhs.price == rhs.price
        && lhs.picture_large == rhs.picture_large
        && lhs.picture_small == rhs.picture_small
        && lhs.intro == rhs.intro);
}


// ���еľ��٣�keyΪ���
typedef std::map<a_string, tagOfficer>     OfficerList;

class OfficerListSetup : public atom::CSingleton<OfficerListSetup>
{
public:
    // �Ӷ������ļ��м������еľ���
    bool    Load(const a_string& path);

    // ���ݱ�ŵõ�ĳ�����ٵ�����
    const tagOfficer*   GetOfficer(const a_string& index) const;

    // ������о����б�
    const OfficerList&  GetOfficerList() const {return officer_list_;}

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
    archive.Bind( value.leadership );
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
