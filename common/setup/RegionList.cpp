#include "RegionList.h"
#include "LoadBinaryFile.h"


namespace setup {

// �Ӷ������ļ��м��ص�ͼ
bool    RegionListSetup::Load(const a_string& path)
{
    regions_ = LoadBinaryFile<RegionList>(path);
    return !regions_.empty();
}

// �������Ʋ��ҵ�ͼ
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
