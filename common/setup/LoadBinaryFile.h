#ifndef COMMON_SETUP_LOADBINARYFILE_H
#define COMMON_SETUP_LOADBINARYFILE_H

#include "../Config.h"

namespace setup {

// 从二进制文件读取数据结构
// 使用方式:
//      auto region = LoadBinaryFile<RegionMap>(path); 
//      auto category = LoadBinaryFile<ArmyCategoryMap>(path);
//      auto officer = LoadBinaryFile<OfficerMap>(path);

#ifdef __APPLE__
template <typename T>
T   LoadBinaryFile(const a_string& path)
{
    using namespace atom;
    T value = T();
    CMemory data;
    string strPath = CCFileUtils::
        sharedFileUtils() -> fullPathForFilename(path.c_str());
    if( strPath.empty() ) return value;    

    data = CFile::LoadFile(strPath.c_str());
    if (data.GetLength() > 0)
    {
        CArchive ar;
        ar.Assign(data);
        int version = 0;
        ar >> version >> value;
    }
    return value;
}
#endif

#ifdef __ANDROID__
template <typename T>
T   LoadBinaryFile(const a_string& path)
{
    using namespace atom;
    T value = T();
    CMemory data;
    unsigned long   mems = 0;
    unsigned char * memo = CCFileUtils::sharedFileUtils() -> getFileData(path.c_str(), "r", & mems );
    if( memo )
    {
        if( data.Alloc( mems + 1 ) ) {
            data.Store( memo, mems );
        }
        SAFE_DELETE_ARRAY( memo );
    }
    if (data.GetLength() > 0)
    {
        CArchive ar;
        ar.Assign(data);
        int version = 0;
        ar >> version >> value;
    }
    return value;
}
#endif

#ifdef __WINDOWS__
template <typename T>
T   LoadBinaryFile(const a_string& path)
{
    using namespace atom;
    T value = T();
    CMemory data;
    data = CFile::LoadFile(path.c_str());
    if (data.GetLength() > 0)
    {
        CArchive ar;
        ar.Assign(data);
        int version = 0;
        ar >> version >> value;
    }
    return std::move(value);
}
#endif

} // namespace setup

#endif // COMMON_SETUP_LOADBINARYFILE_H
