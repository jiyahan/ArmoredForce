#ifndef COMMON_SETUP_LOADBINARYFILE_H
#define COMMON_SETUP_LOADBINARYFILE_H

#include "../Config.h"

// �Ӷ������ļ���ȡ���ݽṹ
// ʹ�÷�ʽ:
//      auto region = LoadBinaryFile<RegionMap>(path); 
//      auto category = LoadBinaryFile<ArmyCategoryMap>(path);
//      auto officer = LoadBinaryFile<OfficerMap>(path);
template <typename T>
T   LoadBinaryFile(const String& path)
{
    T value;
    CMemory data = CFile::LoadFile(path.c_str());
    if (data.GetLength() > 0)
    {
        CArchive ar;
        ar.Assign(data);
        ar >> value;
    }
    return std::move(value);
}

#endif // COMMON_SETUP_LOADBINARYFILE_H
