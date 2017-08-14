#ifndef COMMON_SETUP_REGION_H
#define COMMON_SETUP_REGION_H

#include <cstdint>
#include <string>
#include <map>
#include <array>

namespace setup {

// ʤ�����ý���
struct tagPrize
{
    String     name;       // ������Ʒ����
    String     index;      // ������Ʒ���
    I32        count;      // ������Ʒ����
};


// �����׶�
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

// ��ͼ
struct tagRegion
{
    String      name;       // ����
    String      index;      // ���
    String      picture;    // ����ͼƬ

    // �����׶�
    enum {MAX_STAGE = 3};
    std::array<tagRegionStage, MAX_STAGE>  stages;
};

// ���еĵ�ͼ���ã�keyΪ���
typedef std::map<String, tagRegion>     RegionMap;

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
    for (int i = 0; i < tagRegion::MAX_STAGE; ++i)
    {
        Serialize(archive, value.stages[i], isSave);
    }
}

#endif // COMMON_SETUP_REGION_H
