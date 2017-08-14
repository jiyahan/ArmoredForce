#include "CAppleDirectory.h"
#include "../character/CCharacter.h"
#include "../file/CFile.h"
#include "../../utility/charset/CUtf8Charset.h"
//Begin section for file CAppleDirectory.cpp
//TODO: Add definitions that you want preserved
//End section for file CAppleDirectory.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CAppleDirectory::CAppleDirectory(const char * value) 
{
    //TODO Auto-generated method stub
    if( value ) 
	{
		// mac os only support utf-8 format file system.
		if( CUtf8Charset::IsUtf8(value) ) {
			path = value;
		} else {
			path = CCharacter::MultiBytesToUtf8( value );
		}
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CAppleDirectory::CAppleDirectory(const wchar_t * value) 
{
    //TODO Auto-generated method stub
    if( value ) {
		// mac os only support utf-8 format file system.
		path = CCharacter::UnicodeToUtf8( value );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CAppleDirectory::~CAppleDirectory() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAppleDirectory::EnumFiles(const char * directory, CStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    #ifdef __APPLE__
    if( directory )
    {
        a_string current = directory;
        DIR* handle = opendir( directory );
        if( handle )
        {
            dirent* entry = NULL;
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
                            // �������Ŀ¼����ݹ���ʡ�
                            if( sub_directory  )
                            {
                                EnumFiles( subentry.c_str(), files, sub_directory, absolute_path );
                            }
                        }
                        else
                        if( S_ISLNK(info.st_mode) )
                        {
                            // ��������ӣ�ʲô��������
                        }
                        else
                        if( S_ISREG(info.st_mode) )
                        {
                            // �ļ�����¼����������ڡ�
                            if( absolute_path )
                            {
                                char fullpath[PATH_MAX];
                                realpath( subentry.c_str(), fullpath );
                                subentry = fullpath;
                            }

                            // Output will be utf8 charset;
                            files.push_back( subentry );
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAppleDirectory::EnumFiles(const char * directory, CWStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    #ifdef __APPLE__
    if( directory )
    {
        a_string current = directory;
        DIR* handle = opendir( directory );
        if( handle )
        {
            dirent* entry = NULL;
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
                            // �������Ŀ¼����ݹ���ʡ�
                            if( sub_directory  )
                            {
                                EnumFiles( subentry.c_str(), files, sub_directory, absolute_path );
                            }
                        }
                        else
                        if( S_ISLNK(info.st_mode) )
                        {
                            // ��������ӣ�ʲô��������
                        }
                        else
                        if( S_ISREG(info.st_mode) )
                        {
                            // �ļ�����¼����������ڡ�
                            if( absolute_path )
                            {
                                char fullpath[PATH_MAX];
                                realpath( subentry.c_str(), fullpath );
                                subentry = fullpath;
                            }

                            files.push_back( CCharacter::Utf8ToUnicode( subentry.c_str() ) );
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAppleDirectory::EnumDirectories(const char * directory, CStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    #ifdef __APPLE__
    if( directory )
    {
        a_string current = directory;
        DIR* handle = opendir( directory );
        if( handle )
        {
            dirent* entry = NULL;
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
                            // �������Ŀ¼����ݹ���ʡ�
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
                         
                            // Output will be multi-bytes, for same output.
                            files.push_back( subentry.c_str() );
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAppleDirectory::EnumDirectories(const char * directory, CWStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    #ifdef __APPLE__
    if( directory )
    {
        a_string current = directory;
        DIR* handle = opendir( directory );
        if( handle )
        {
            dirent* entry = NULL;
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
                            // �������Ŀ¼����ݹ���ʡ�
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

                            files.push_back( CCharacter::Utf8ToUnicode( subentry.c_str() ) );
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAppleDirectory::EnumFiles(CStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    EnumFiles( path.c_str(), files, sub_directory, absolute_path );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAppleDirectory::EnumFiles(CWStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    EnumFiles( path.c_str(), files, sub_directory, absolute_path );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAppleDirectory::EnumDirectories(CStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    EnumDirectories( path.c_str(), files, sub_directory, absolute_path );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAppleDirectory::EnumDirectories(CWStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    EnumDirectories( path.c_str(), files, sub_directory, absolute_path );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CAppleDirectory::CreateDirectory() 
{
    //TODO Auto-generated method stub
    bool result = false;
    #ifdef __APPLE__
    result = mkdir( path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH ) == 0;
    #endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CAppleDirectory::RemoveDirectory(bool withfile) 
{
    //TODO Auto-generated method stub
    bool result = false;
    
    #ifdef __APPLE__
    CStringArray files;
    EnumFiles( files, true, true );

    // ���û���ļ�������ͬʱɾ���ļ����������
    if( files.empty() || withfile )
    {
        // ɾ�����е��ļ���
        bool retval = true;
        for( size_t i = 0, j = files.size(); i < j; ++ i )
        {
            if( !CFile::Erase( files[i].c_str() ) ) {
                retval = false;
            }
        }

        // ����Ƴ��ļ��ɹ�����ɾ��������Ŀ¼��
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

        // ����Ƴ��ɹ�����ɾ��Ŀ��Ŀ¼��
        if( result ) {
            result = rmdir( path.c_str() ) == 0; 
        }
    }

    #else
    UNREFERENCED_PARAMETER( withfile );
    #endif

    return result;
}
