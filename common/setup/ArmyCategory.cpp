#include "ArmyCategory.h"
#include "LoadBinaryFile.h"

namespace setup {

// �Ӷ������ļ��ж�ȡ��������
bool  ArmyCategorySetup::Load(const String& path)
{
    categories_ = LoadBinaryFile<ArmyCategoryList>(path);
    return !categories_.empty(); 
}

// �������Ʋ��ұ���
const tagArmyCategory*  ArmyCategorySetup::GetCategory(const String& name) const
{
    auto iter = categories_.find(name);
    if(iter != categories_.end())
    {
        return std::addressof(iter->second);
    }
    return nullptr;
}

} // namespace setup
