#include "MonsterList.h"
#include "LoadBinaryFile.h"

namespace setup {

// �Ӷ������ļ��м������еľ���
bool    MonsterListSetup::Load(const String& path)
{
    monster_list_ = LoadBinaryFile<MonsterList>(path);
    return !monster_list_.empty();
}

// ���ݱ�ŵõ�ĳ�����ٵ�����
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
