#include "RegionList.h"
#include "LoadBinaryFile.h"


namespace setup {

// �Ӷ������ļ��м��ص�ͼ
void    RegionListSetup::Load(const String& path)
{
    regions_ = LoadBinaryFile<RegionList>(path);
}

// �������Ʋ��ҵ�ͼ
const tagRegion*  RegionListSetup::GetRegion(const String& name) const
{
    auto iter = regions_.find(name);
    if (iter != regions_.end())
    {
        return std::addressof(iter->second);
    }
    return nullptr;
}

} // namespace setup
