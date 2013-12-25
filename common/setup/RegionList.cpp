#include "RegionList.h"
#include "LoadBinaryFile.h"


namespace setup {

// 从二进制文件中加载地图
bool    RegionListSetup::Load(const a_string& path)
{
    regions_ = LoadBinaryFile<RegionList>(path);
    return !regions_.empty();
}

// 根据名称查找地图
const tagRegion*  RegionListSetup::GetRegion(const a_string& name) const
{
    auto iter = regions_.find(name);
    if (iter != regions_.end())
    {
        return std::addressof(iter->second);
    }
    return nullptr;
}

} // namespace setup
