#include "MonsterList.h"
#include "LoadBinaryFile.h"

namespace setup {

// 从二进制文件中加载所有的军官
void    MonsterListSetup::Load(const String& path)
{
    monster_list_ = LoadBinaryFile<MonsterList>(path);
}

// 根据编号得到某个军官的配置
const tagMonster&   MonsterListSetup::GetMonster(const String& index) const
{
    static const tagMonster dummy = {};
    auto iter = monster_list_.find(index);
    return (iter != monster_list_.end() ? iter->second : dummy);
}

} // namespace setup
