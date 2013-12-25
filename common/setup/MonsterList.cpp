#include "MonsterList.h"
#include "LoadBinaryFile.h"

namespace setup {

// 从二进制文件中加载所有的军官
bool    MonsterListSetup::Load(const String& path)
{
    monster_list_ = LoadBinaryFile<MonsterList>(path);
    return !monster_list_.empty();
}

// 根据编号得到某个军官的配置
const tagMonster*   MonsterListSetup::GetMonster(const String& index) const
{
    auto iter = monster_list_.find(index);
    if(iter != monster_list_.end())
    {
        return std::addressof(iter->second);
    }
    return nullptr;
}

} // namespace setup
