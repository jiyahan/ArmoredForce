#include "MonsterList.h"
#include "LoadBinaryFile.h"


namespace setup {

// �Ӷ������ļ��м������еľ���
bool    MonsterListSetup::Load(const a_string& path)
{
    monster_list_ = LoadBinaryFile<MonsterList>(path);
    return !monster_list_.empty();
}

// ���ݱ�ŵõ�ĳ�����ٵ�����
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
