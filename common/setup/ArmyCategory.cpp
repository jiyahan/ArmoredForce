#include "ArmyCategory.h"
#include "LoadBinaryFile.h"

namespace setup {

void  ArmyCategorySetup::Load(const String& path)
{
    categories_ = LoadBinaryFile<ArmyCategoryList>(path);
}


const tagArmyCategory&  ArmyCategorySetup::GetCategory(const String& name) const
{
    static const tagArmyCategory dummy = {};
    auto iter = categories_.find(name);
    return (iter != categories_.end() ? iter->second : dummy);
}

} // namespace setup
