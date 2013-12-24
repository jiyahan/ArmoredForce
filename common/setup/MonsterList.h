#ifndef COMMON_SETUP_MONSTERLIST_H
#define COMMON_SETUP_MONSTERLIST_H

#include "../Config.h"
#include <map>
#include "../3rdParty/atom/atom/CAtom.h"

namespace setup {
    
// 怪物掉落道具
struct tagDropThing
{
    String      index;  // 编号
    I32         num;    // 数量
    I32         rate;   // 几率
};

// 怪物,卡片
struct tagMonster
{
    String          name;               // 怪物名称
    String          index;              // 怪物编号
    String          category;           // 兵种类型 
    I32             type;               // 怪物类型
    I32             attack;             // 攻击
    I32             force;              // 兵力
    I32             blast;              // 暴击
    I32             accuracy;           // 精准

    vector<tagDropThing> drop_things;   // 掉落
};


// 所有的军官，key为编号
typedef std::map<String, tagMonster>     MonsterList;

class MonsterListSetup : public atom::CSingleton<MonsterListSetup>
{
public:
    // 从二进制文件中加载所有的军官
    void    Load(const String& path);

    // 根据编号得到某个军官的配置
    const tagMonster&   GetMonster(const String& index) const;

private:
    MonsterList      monster_list_;
};

} // namespace setup

template<typename Archive>
inline void Serialize(Archive& archive, setup::tagDropThing& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.index );
    archive.Bind( value.num );
    archive.Bind( value.rate );
}


template<typename Archive>
inline void Serialize(Archive& archive, setup::tagMonster& value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.name );
    archive.Bind( value.index );
    archive.Bind( value.category );
    archive.Bind( value.type );
    archive.Bind( value.attack );
    archive.Bind( value.force );
    archive.Bind( value.blast );
    archive.Bind( value.accuracy );
    archive.Bind( value.drop_things );
}

#endif // COMMON_SETUP_MONSTERLIST_H
