#include "OfficerList.h"
#include "LoadBinaryFile.h"

namespace setup {

// �Ӷ������ļ��м������еľ���
bool   OfficerListSetup::Load(const a_string& path)
{
    officer_list_ = LoadBinaryFile<OfficerList>(path);
    return !officer_list_.empty();
}

// ���ݱ�ŵõ�ĳ�����ٵ�����
const tagOfficer*   OfficerListSetup::GetOfficer(const a_string& index) const
{   
    OfficerList::const_iterator iter = officer_list_.find(index);
    if(iter != officer_list_.end())
    {
        return &(iter->second);
    }
    return NULL;
}

} // namespace setup
