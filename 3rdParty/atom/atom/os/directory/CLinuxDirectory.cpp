#include "CLinuxDirectory.h"
#include "../character/CCharacter.h"
#include "../file/CFile.h"
#include "../../utility/charset/CUtf8Charset.h"


atom::CLinuxDirectory::CLinuxDirectory(const char * value) 
{
    if( value ) path = value;
}

atom::CLinuxDirectory::CLinuxDirectory(const wchar_t * value) 
{
    if( value ) {
        path = CCharacter::UnicodeToUtf8( value );
    }
}

atom::CLinuxDirectory::~CLinuxDirectory() 
{
}

void atom::CLinuxDirectory::EnumFiles(const char * directory, CStringArray & files, bool sub_directory, bool absolute_path) 
{
    #ifdef __linux
    if( directory )
    {
        a_string current = directory;
        DIR * handle = opendir( directory );
        if( handle )
        {
            dirent * entry = NULL;
            while( ( entry = readdir(handle) ) != NULL )
            {
                if( strcmp(".", entry -> d_name) != 0 && strcmp("..", entry -> d_name) != 0 )
                {
                    a_string subentry = current + "/" + entry -> d_name; 
                    struct stat info;
                    if( lstat(subentry.c_str(), & info) == 0 )
                    {
                        if( S_ISDIR(info.st_mode) )
                        {
                            // 如果是子目录，则递归访问。
                            if( sub_directory  )
                            {
                                EnumFiles( subentry.c_str(), files, sub_directory, absolute_path );
                            }
                        }
                        else
                        if( S_ISLNK(info.st_mode) )
                        {
                            // 如果是连接，什么都不做。
                        }
                        else
                        if( S_ISREG(info.st_mode) )
                        {
                            // 文件，记录在输出向量内。
                            if( absolute_path )
                            {
                                char fullpath[PATH_MAX];
                                realpath( subentry.c_str(), fullpath );
                                subentry = fullpath;
                            }

                            // output will be utf8 charset.
                            if( CUtf8Charset::IsUtf8( subentry.c_str() ) ) {
                                files.push_back( subentry );
                            } else {
                                files.push_back( CCharacter::MultiBytesToUtf8( subentry.c_str() ) );
                            }
                        }
                    }
                }
            }
            closedir( handle );
        }
    }
    #else
    UNREFERENCED_PARAMETER( directory );
    UNREFERENCED_PARAMETER( files );
    UNREFERENCED_PARAMETER( sub_directory );
    UNREFERENCED_PARAMETER( absolute_path );
    #endif
}

void atom::CLinuxDirectory::EnumFiles(const char * directory, CWStringArray & files, bool sub_directory, bool absolute_path) 
{
    #ifdef __linux
    if( directory )
    {
        a_string current = directory;
        DIR * handle = opendir( directory );
        if( handle )
        {
            dirent * entry = NULL;
            while( ( entry = readdir(handle) ) != NULL )
            {
                if( strcmp(".", entry -> d_name) != 0 && strcmp("..", entry -> d_name) != 0 )
                {
                    a_string subentry = current + "/" + entry -> d_name; 
                    struct stat info;
                    if( lstat(subentry.c_str(), & info) == 0 )
                    {
                        if( S_ISDIR(info.st_mode) )
                        {
                            // 如果是子目录，则递归访问。
                            if( sub_directory  )
                            {
                                EnumFiles( subentry.c_str(), files, sub_directory, absolute_path );
                            }
                        }
                        else
                        if( S_ISLNK(info.st_mode) )
                        {
                            // 如果是连接，什么都不做。
                        }
                        else
                        if( S_ISREG(info.st_mode) )
                        {
                            // 文件，记录在输出向量内。
                            if( absolute_path )
                            {
                                char fullpath[PATH_MAX];
                                realpath( subentry.c_str(), fullpath );
                                subentry = fullpath;
                            }

                            // output will be unicode.
                            if( CUtf8Charset::IsUtf8( subentry.c_str() ) ) {
                                files.push_back( CCharacter::Utf8ToUnicode      ( subentry.c_str() ) );
                            } else {
                                files.push_back( CCharacter::MultiBytesToUnicode( subentry.c_str() ) );
                            }
                        }
                    }
                }
            }
            closedir( handle );
        }
    }
    #else
    UNREFERENCED_PARAMETER( directory );
    UNREFERENCED_PARAMETER( files );
    UNREFERENCED_PARAMETER( sub_directory );
    UNREFERENCED_PARAMETER( absolute_path );
    #endif
}

void atom::CLinuxDirectory::EnumDirectories(const char * directory, CStringArray & files, bool sub_directory, bool absolute_path) 
{
    #ifdef __linux
    if( directory )
    {
        a_string current = directory;
        DIR * handle = opendir( directory );
        if( handle )
        {
            dirent * entry = NULL;
            while( ( entry = readdir(handle) ) != NULL )
            {
                if( strcmp(".", entry -> d_name) != 0 && strcmp("..", entry -> d_name) != 0 )
                {
                    a_string subentry = current + "/" + entry -> d_name; 
                    struct stat info;
                    if( lstat(subentry.c_str(), &info) == 0 )
                    {
                        if( S_ISDIR(info.st_mode) )
                        {
                            // 如果是子目录，则递归访问。
                            if( sub_directory  )
                            {
                                EnumDirectories( subentry.c_str(), files, sub_directory, absolute_path );
                            }
                                
                            if( absolute_path )
                            {
                                char fullpath[PATH_MAX];
                                realpath( subentry.c_str(), fullpath );
                                subentry = fullpath;
                            }

                            // output will be utf8 charset.
                            if( CUtf8Charset::IsUtf8( subentry.c_str() ) ) {
                                files.push_back( subentry );
                            } else {
                                files.push_back( CCharacter::MultiBytesToUtf8( subentry.c_str() ) );
                            }
                        }
                    }
                }
            }
            closedir( handle );
        }
    }
    #else
    UNREFERENCED_PARAMETER( directory );
    UNREFERENCED_PARAMETER( files );
    UNREFERENCED_PARAMETER( sub_directory );
    UNREFERENCED_PARAMETER( absolute_path );
    #endif
}

void atom::CLinuxDirectory::EnumDirectories(const char * directory, CWStringArray & files, bool sub_directory, bool absolute_path) 
{
    #ifdef __linux
    if( directory )
    {
        a_string current = directory;
        DIR * handle = opendir( directory );
        if( handle )
        {
            dirent * entry = NULL;
            while( ( entry = readdir(handle) ) != NULL )
            {
                if( strcmp(".", entry -> d_name) != 0 && strcmp("..", entry -> d_name) != 0 )
                {
                    a_string subentry = current + "/" + entry -> d_name; 
                    struct stat info;
                    if( lstat(subentry.c_str(), &info) == 0 )
                    {
                        if( S_ISDIR(info.st_mode) )
                        {
                            // 如果是子目录，则递归访问。
                            if( sub_directory  )
                            {
                                EnumDirectories( subentry.c_str(), files, sub_directory, absolute_path );
                            }
                                
                            if( absolute_path )
                            {
                                char fullpath[PATH_MAX];
                                realpath( subentry.c_str(), fullpath );
                                subentry = fullpath;
                            }

                            // output will be unicode.
                            if( CUtf8Charset::IsUtf8( subentry.c_str() ) ) {
                                files.push_back( CCharacter::Utf8ToUnicode      ( subentry.c_str() ) );
                            } else {
                                files.push_back( CCharacter::MultiBytesToUnicode( subentry.c_str() ) );
                            }
                        }
                    }
                }
            }
            closedir( handle );
        }
    }
    #else
    UNREFERENCED_PARAMETER( directory );
    UNREFERENCED_PARAMETER( files );
    UNREFERENCED_PARAMETER( sub_directory );
    UNREFERENCED_PARAMETER( absolute_path );
    #endif
}

void atom::CLinuxDirectory::EnumFiles(CStringArray & files, bool sub_directory, bool absolute_path) 
{
    EnumFiles( path.c_str(), files, sub_directory, absolute_path );
}

void atom::CLinuxDirectory::EnumFiles(CWStringArray & files, bool sub_directory, bool absolute_path) 
{
    EnumFiles( path.c_str(), files, sub_directory, absolute_path );
}

void atom::CLinuxDirectory::EnumDirectories(CStringArray & files, bool sub_directory, bool absolute_path) 
{
    EnumDirectories( path.c_str(), files, sub_directory, absolute_path );
}

void atom::CLinuxDirectory::EnumDirectories(CWStringArray & files, bool sub_directory, bool absolute_path) 
{
    EnumDirectories( path.c_str(), files, sub_directory, absolute_path );
}

bool atom::CLinuxDirectory::CreateDirectory() 
{
    bool result = false;
    #ifdef __linux
    result = mkdir( path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH ) == 0;
    #endif
    return result;
}

bool atom::CLinuxDirectory::RemoveDirectory(bool withfile) 
{
    bool result = false;
    
    #ifdef __linux
    CStringArray files;
    EnumFiles( files, true, true );

    // 如果没有文件，或者同时删除文件，则继续；
    if( files.empty() || withfile )
    {
        // 删除所有的文件；
        bool retval = true;
        for( size_t i = 0, j = files.size(); i < j; ++ i )
        {
            if( !CFile::Erase( files[i].c_str() ) ) {
                retval = false;
            }
        }

        // 如果移除文件成功，则删除所有子目录；
        if( retval )
        {
            files.clear();
            EnumDirectories( files, true, true );

            result = true;
            for( size_t i = 0, j = files.size(); i < j; ++ i )
            {
                if( rmdir( files[i].c_str() ) != 0 ) {
                    result = false;
                }
            }
        }

        // 如果移除成功，则删除目标目录；
        if( result ) {
            result = rmdir( path.c_str() ) == 0; 
        }
    }

    #else
    UNREFERENCED_PARAMETER( withfile );
    #endif

    return result;
}
