#include "ArmyCategory.h"
#include "LoadBinaryFile.h"

namespace setup {

void  ArmyCategorySetup::Load(const String& path)
{
    categories_ = LoadBinaryFile<ArmyCategoryList>(path);
}


const tagArmyCategory*  ArmyCategorySetup::GetCategory(const String& name) const
{
    static const tagArmyCategory dummy = {};
    auto iter = categories_.find(name);
    if(iter != categories_.end())
    {
        return std::addressof(iter->second);
    }
    return nullptr;
}

} // namespace setup
