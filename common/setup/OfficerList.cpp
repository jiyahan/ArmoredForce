#include "OfficerList.h"
#include "LoadBinaryFile.h"

namespace setup {

// 从二进制文件中加载所有的军官
bool   OfficerListSetup::Load(const a_string& path)
{
    officer_list_ = LoadBinaryFile<OfficerList>(path);
    return !officer_list_.empty();
}

// 根据编号得到某个军官的配置
const tagOfficer*   OfficerListSetup::GetOfficer(const a_string& index) const
{   
    auto iter = officer_list_.find(index);
    if(iter != officer_list_.end())
    {
        return std::addressof(iter->second);
    }
    return nullptr;
}

} // namespace setup
