#ifndef COMMON_SETUP_REGIONLIST_H
#define COMMON_SETUP_REGIONLIST_H

#include "../Config.h"
#include <map>
#include <array>
#include "../../3rdParty/atom/atom/CAtom.h"

namespace setup {

// ʤ�����ý�������
struct tagPrize
{
    a_string   name;       // ������Ʒ����
    a_string   index;      // ������Ʒ���
    I32        count;      // ������Ʒ����
};


// ս���е������׶�����
struct tagRegionStage
{
    // 6������
    std::array<a_string, GRID_AMOUNT>  monsters;

    // ����
    std::vector<tagPrize>    prize;
};

// ��ͼ����
struct tagRegion
{
    a_string      name;       // ����
    a_string      index;      // ���
    I32           type;
    a_string      picture;    // ����ͼƬ

    // �����׶�
    enum {MAX_STAGE = 3};
    std::array<tagRegionStage, MAX_STAGE>  stages;
};

//
// ������ж�
//
inline bool operator == (const setup::tagPrize& lhs, const setup::tagPrize& rhs)
{
    return (lhs.name == rhs.name 
        && lhs.index == rhs.index
        && lhs.count == rhs.count);
}

inline bool operator == (const setup::tagRegionStage& lhs, const setup::tagRegionStage& rhs)
{
    return (lhs.monsters == rhs.monsters
        && lhs.prize == rhs.prize);
}

inline bool operator == (const setup::tagRegion& lhs, const setup::tagRegion& rhs)
{
    return (lhs.name == rhs.name
        && lhs.index == rhs.index
        && lhs.type == rhs.type
        && lhs.picture == rhs.picture
        && lhs.stages == rhs.stages);
}

typedef std::map<a_string, tagRegion>     RegionList;

//////////////////////////////////////////////////////////////////////////
//
// ���е�ͼ����
//
class RegionListSetup : public atom::CSingleton<RegionListSetup>
{
public:
    // �Ӷ������ļ��м��ص�ͼ
    bool    Load(const a_string& path);

    // �������Ʋ��ҵ�ͼ
    const tagRegion*  GetRegion(const a_string& name) const;

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
    for (auto& item : value.monsters)
    {
        archive.Bind( item );
    }
    Serialize(archive, value.prize, isSave);
}


template<typename Archive>
inline void Serialize(Archive& archive, setup::tagRegion& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.type );
    archive.Bind( value.picture );
    for (auto& stage : value.stages)
    {
        Serialize(archive, stage, isSave);
    }
}



#endif // COMMON_SETUP_REGIONLIST_H
