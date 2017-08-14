#ifndef COMMON_SETUP_REGIONLIST_H
#define COMMON_SETUP_REGIONLIST_H

#include "../Config.h"
#include <map>
#include <vector>
#include "../../3rdParty/atom/atom/CAtom.h"

using atom::a_string;

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
    a_string  monsters[GRID_AMOUNT];

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
    tagRegionStage  stages[MAX_REGION_STAGE];
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
    for (int i = 0; i < GRID_AMOUNT; ++i)
    {
        if (lhs.monsters[i] != rhs.monsters[i])
            return false;
    }
    return lhs.prize == rhs.prize;
}

inline bool operator == (const setup::tagRegion& lhs, const setup::tagRegion& rhs)
{
    for (int i = 0; i < MAX_REGION_STAGE; ++i)
    {
        if (!(lhs.stages[i] == rhs.stages[i]))
            return false;
    }
    return (lhs.name == rhs.name
        && lhs.index == rhs.index
        && lhs.type == rhs.type
        && lhs.picture == rhs.picture);
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


template<typename Archive>
inline void Serialize(Archive& archive, tagPrize& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.count );
}

template<typename Archive>
inline void Serialize(Archive& archive, tagRegionStage& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    for (int i = 0; i < GRID_AMOUNT; ++i)
    {
        archive.Bind( value.monsters[i] );
    }
    archive.Bind(value.prize);    
}


template<typename Archive>
inline void Serialize(Archive& archive, tagRegion& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.type );
    archive.Bind( value.picture );
    for (int i = 0; i < MAX_REGION_STAGE; ++i)
    {
        Serialize(archive, value.stages[i], isSave);
    }
}


} // namespace setup




#endif // COMMON_SETUP_REGIONLIST_H
