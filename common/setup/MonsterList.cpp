#include "MonsterList.h"
#include "LoadBinaryFile.h"


namespace setup {

// 从二进制文件中加载所有的军官
bool    MonsterListSetup::Load(const a_string& path)
{
    monster_list_ = LoadBinaryFile<MonsterList>(path);
    return !monster_list_.empty();
}

// 根据编号得到某个军官的配置
const tagMonster*   MonsterListSetup::GetMonster(const a_string& index) const
{
    MonsterList::const_iterator iter = monster_list_.find(index);
    if(iter != monster_list_.end())
    {
        return &(iter->second);
    }
    return NULL;
}

const DropThingList*  MonsterListSetup::GetDropThing(const a_string& index) const
{
    const tagMonster* monster = GetMonster(index);
    return (monster ? &monster->drop_things : NULL);
}

} // namespace setup
