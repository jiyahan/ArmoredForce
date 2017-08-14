#include "RegionList.h"
#include "LoadBinaryFile.h"


namespace setup {

// �Ӷ������ļ��м��ص�ͼ
void    RegionListSetup::Load(const String& path)
{
    regions_ = LoadBinaryFile<RegionList>(path);
}

// �������Ʋ��ҵ�ͼ
const tagRegion&  RegionListSetup::GetRegion(const String& name) const
{
    static const tagRegion dummy = {};
    auto iter = regions_.find(name);
    return (iter != regions_.end() ? iter->second : dummy);
}

} // namespace setup
