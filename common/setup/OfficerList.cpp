#include "OfficerList.h"
#include "LoadBinaryFile.h"

namespace setup {

// �Ӷ������ļ��м������еľ���
void   OfficerListSetup::Load(const String& path)
{
    officer_list_ = LoadBinaryFile<OfficerList>(path);
}

// ���ݱ�ŵõ�ĳ�����ٵ�����
const tagOfficer*   OfficerListSetup::GetOfficer(const String& index) const
{   
    auto iter = officer_list_.find(index);
    if(iter != officer_list_.end())
    {
        return std::addressof(iter->second);
    }
    return nullptr;
}

} // namespace setup
