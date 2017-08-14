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
    std::string     name;       // ������Ʒ����
    std::string     index;      // ������Ʒ���
    int32_t         count;      // ������Ʒ����
};


// �����׶�
struct tagRegionStage
{
    // 6��λ�õĿ�Ƭ
    std::string   pos_1;
    std::string   pos_2;
    std::string   pos_3;
    std::string   pos_4;
    std::string   pos_5;
    std::string   pos_6;

    tagPrize    prize;
};

// ��ͼ
struct tagRegion
{
    std::string      name;       // ����
    std::string      index;      // ���
    std::string      picture;    // ����ͼƬ

    // �����׶�
    enum {MAX_STAGE = 3};
    std::array<tagRegionStage, MAX_STAGE>  stages;
};

// ���еĵ�ͼ���ã�keyΪ���
typedef std::map<std::string, tagRegion>     RegionMap;

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
