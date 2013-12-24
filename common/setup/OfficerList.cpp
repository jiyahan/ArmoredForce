#include "OfficerList.h"
#include "LoadBinaryFile.h"

namespace setup {

// 从二进制文件中加载所有的军官
void   OfficerListSetup::Load(const String& path)
{
    officer_list_ = LoadBinaryFile<OfficerList>(path);
}

// 根据编号得到某个军官的配置
const tagOfficer&   OfficerListSetup::GetOfficer(const String& index) const
{
    static const tagOfficer dummy = {};
    auto iter = officer_list_.find(index);
    return (iter != officer_list_.end() ? iter->second : dummy);
}

} // namespace setup
