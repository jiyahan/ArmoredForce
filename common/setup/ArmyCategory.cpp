#include "ArmyCategory.h"
#include "LoadBinaryFile.h"

namespace setup {

// �Ӷ������ļ��ж�ȡ��������
bool  ArmyCategorySetup::Load(const a_string& path)
{
    categories_ = LoadBinaryFile<ArmyCategoryList>(path);
    return !categories_.empty(); 
}

// �������Ʋ��ұ���
const tagArmyCategory*  ArmyCategorySetup::GetCategory(const a_string& name) const
{
    ArmyCategoryList::const_iterator iter = categories_.find(name);
    if(iter != categories_.end())
    {
        return &(iter->second);
    }
    return NULL;
}

} // namespace setup
