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
    RegionList::const_iterator iter = regions_.find(name);
    if (iter != regions_.end())
    {
        return &(iter->second);
    }
    return NULL;
}

} // namespace setup
