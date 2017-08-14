#ifndef COMMON_SETUP_LOADBINARYFILE_H
#define COMMON_SETUP_LOADBINARYFILE_H

#include "../Config.h"

namespace setup {

// �Ӷ������ļ���ȡ���ݽṹ
// ʹ�÷�ʽ:
//      auto region = LoadBinaryFile<RegionMap>(path); 
//      auto category = LoadBinaryFile<ArmyCategoryMap>(path);
//      auto officer = LoadBinaryFile<OfficerMap>(path);
template <typename T>
T   LoadBinaryFile(const String& path)
{
    using namespace atom;
    T value = T();
    CMemory data = CFile::LoadFile(path.c_str());
    if (data.GetLength() > 0)
    {
        CArchive ar;
        ar.Assign(data);
        int version = 0;
        ar >> version >> value;
    }
    return std::move(value);
}

} // namespace setup

#endif // COMMON_SETUP_LOADBINARYFILE_H
