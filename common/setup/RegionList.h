#ifndef COMMON_SETUP_REGIONLIST_H
#define COMMON_SETUP_REGIONLIST_H

#include "../Config.h"
#include <map>
#include <array>
#include "../3rdParty/atom/atom/CAtom.h"

namespace setup {

// ʤ�����ý�������
struct tagPrize
{
    String     name;       // ������Ʒ����
    String     index;      // ������Ʒ���
    I32        count;      // ������Ʒ����
};


// ս���е������׶�����
struct tagRegionStage
{
    // 6��λ�õĿ�Ƭ
    String   pos_1;
    String   pos_2;
    String   pos_3;
    String   pos_4;
    String   pos_5;
    String   pos_6;

    tagPrize    prize;
};

// ��ͼ����
struct tagRegion
{
    String      name;       // ����
    String      index;      // ���
    String      picture;    // ����ͼƬ

    // �����׶�
    enum {MAX_STAGE = 3};
    std::array<tagRegionStage, MAX_STAGE>  stages;
};


typedef std::map<String, tagRegion>     RegionList;

//////////////////////////////////////////////////////////////////////////
//
// ���е�ͼ����
//
class RegionListSetup : public atom::CSingleton<RegionListSetup>
{
public:
    // �Ӷ������ļ��м��ص�ͼ
    void    Load(const String& path);

    // �������Ʋ��ҵ�ͼ
    const tagRegion&  GetRegion(const String& name) const;

private:
    RegionList       regions_;
};

} // namespace setup


template<typename Archive>
inline void Serialize(Archive& archive, setup::tagPrize& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.count );
}

template<typename Archive>
inline void Serialize(Archive& archive, setup::tagRegionStage& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.pos_1 );
    archive.Bind( value.pos_2 );
    archive.Bind( value.pos_3 );
    archive.Bind( value.pos_4 );
    archive.Bind( value.pos_5 );
    archive.Bind( value.pos_6 );
    Serialize(archive, value.prize, isSave);
}


template<typename Archive>
inline void Serialize(Archive& archive, setup::tagRegion& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.picture );
    for (const auto& item : value.stages)
    {
        //Serialize(archive, item, isSave);
    }
}

#endif // COMMON_SETUP_REGIONLIST_H
