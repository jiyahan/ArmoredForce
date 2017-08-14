#include "MonsterList.h"
#include "LoadBinaryFile.h"

namespace setup {

// �Ӷ������ļ��м������еľ���
void    MonsterListSetup::Load(const String& path)
{
    monster_list_ = LoadBinaryFile<MonsterList>(path);
}

// ���ݱ�ŵõ�ĳ�����ٵ�����
const tagMonster&   MonsterListSetup::GetMonster(const String& index) const
{
    static const tagMonster dummy = {};
    auto iter = monster_list_.find(index);
    return (iter != monster_list_.end() ? iter->second : dummy);
}

} // namespace setup
