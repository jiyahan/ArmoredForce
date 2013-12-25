#include "ArmyCategory.h"
#include "LoadBinaryFile.h"

namespace setup {

// 从二进制文件中读取兵种配置
bool  ArmyCategorySetup::Load(const a_string& path)
{
    categories_ = LoadBinaryFile<ArmyCategoryList>(path);
    return !categories_.empty(); 
}

// 根据名称查找兵种
const tagArmyCategory*  ArmyCategorySetup::GetCategory(const a_string& name) const
{
    auto iter = categories_.find(name);
    if(iter != categories_.end())
    {
        return std::addressof(iter->second);
    }
    return nullptr;
}

} // namespace setup
