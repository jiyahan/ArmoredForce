#include "RegionList.h"
#include "LoadBinaryFile.h"


namespace setup {

// 从二进制文件中加载地图
void    RegionListSetup::Load(const String& path)
{
    regions_ = LoadBinaryFile<RegionList>(path);
}

// 根据名称查找地图
const tagRegion&  RegionListSetup::GetRegion(const String& name) const
{
    static const tagRegion dummy = {};
    auto iter = regions_.find(name);
    return (iter != regions_.end() ? iter->second : dummy);
}

} // namespace setup
