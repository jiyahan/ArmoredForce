#include "CWin32Directory.h"
#include "../path/CPath.h"
#include "../character/CCharacter.h"
#include "../file/CFile.h"
#include "../../utility/charset/CUtf8Charset.h"
//Begin section for file CWin32Directory.cpp
//TODO: Add definitions that you want preserved
//End section for file CWin32Directory.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CWin32Directory::CWin32Directory(const char * value) 
{
    //TODO Auto-generated method stub
    if( value ) 
    {
        if( CUtf8Charset::IsUtf8(value) ) {
            path = CCharacter::Utf8ToUnicode      ( value );
        } else {
            path = CCharacter::MultiBytesToUnicode( value );
        }
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CWin32Directory::CWin32Directory(const wchar_t * value) 
{
    //TODO Auto-generated method stub
    if( value ) {
        path = value;
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CWin32Directory::~CWin32Directory() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CWin32Directory::EnumFiles(const wchar_t * directory, CStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    if( directory )
    {
        a_wstring current = directory;
        a_wstring fileext = current + L"/*.*";
            
        _wfinddata_t item;
        intptr_t handle = _wfindfirst( fileext.c_str(), & item );
        if( handle != -1L )
        {
            do 
            {
                if( item.attrib & _A_SUBDIR )
                {
                    // �������Ŀ¼����ô���ݱ�־����������Ŀ¼
                    if( sub_directory && wcscmp(L".", item.name) != 0 && wcscmp(L"..", item.name) != 0 )
                    {
                        a_wstring subpath = current + L"/" + item.name;
                        EnumFiles( subpath.c_str(), files, sub_directory, absolute_path );
                    }
                }
                else
                {
                    // ������ļ����������������ڡ�
                    a_wstring file = current + L"/" + item.name;
                    if( absolute_path )
                    {
                        wchar_t fullpath[MAX_PATH];
                        _wfullpath( fullpath, file.c_str(), MAX_PATH );
                        file = fullpath;
                    } 

                    // output utf8 filename as default.
                    files.push_back( CCharacter::UnicodeToUtf8( file.c_str() ) );
                }
            } 
            while( _wfindnext(handle, & item) == 0 );
            _findclose( handle );
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
void atom::CWin32Directory::EnumFiles(const wchar_t * directory, CWStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    if( directory )
    {
        a_wstring current = directory;
        a_wstring fileext = current + L"/*.*";
            
        _wfinddata_t item;
        intptr_t handle = _wfindfirst( fileext.c_str(), & item );
        if( handle != -1L )
        {
            do 
            {
                if( item.attrib & _A_SUBDIR )
                {
                    // �������Ŀ¼����ô���ݱ�־����������Ŀ¼
                    if( sub_directory && wcscmp(L".", item.name) != 0 && wcscmp(L"..", item.name) != 0 )
                    {
                        a_wstring subpath = current + L"/" + item.name;
                        EnumFiles( subpath.c_str(), files, sub_directory, absolute_path );
                    }
                }
                else
                {
                    // ������ļ����������������ڡ�
                    a_wstring file = current + L"/" + item.name;
                    if( absolute_path )
                    {
                        wchar_t fullpath[MAX_PATH];
                        _wfullpath( fullpath, file.c_str(), MAX_PATH );
                        file = fullpath;
                    } 

                    // output platform default ucs code.
                    files.push_back( file );
                }
            } 
            while( _wfindnext(handle, & item) == 0 );
            _findclose( handle );
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
void atom::CWin32Directory::EnumDirectories(const wchar_t * directory, CStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    if( directory )
    {
        a_wstring current = directory;
        a_wstring fileext = current + L"/*.*";
            
        _wfinddata_t item;
        intptr_t handle = _wfindfirst( fileext.c_str(), & item );
        if( handle != -1L )
        {
            do 
            {
                if( item.attrib & _A_SUBDIR )
                {
                    // ��¼��Ŀ¼
                    if( wcscmp(L".", item.name) != 0 && wcscmp(L"..", item.name) != 0 )
                    {
                        a_wstring subpath = current + L"/" + item.name;

                        // �������Ŀ¼����ô���ݱ�־����������Ŀ¼
                        if( sub_directory )
                        {
                            EnumDirectories( subpath.c_str(), files, sub_directory, absolute_path );
                        }
                            
                        if( absolute_path )
                        {
                            wchar_t fullpath[MAX_PATH];
                            _wfullpath( fullpath, subpath.c_str(), MAX_PATH );
                            subpath = fullpath;                            
                        }

                        // output utf8 as default output
                        files.push_back( CCharacter::UnicodeToUtf8( subpath.c_str() ) );
                    }
                }
            } 
            while( _wfindnext(handle, & item) == 0 );
            _findclose( handle );
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
void atom::CWin32Directory::EnumDirectories(const wchar_t * directory, CWStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    if( directory )
    {
        a_wstring current = directory;
        a_wstring fileext = current + L"/*.*";
            
        _wfinddata_t item;
        intptr_t handle = _wfindfirst( fileext.c_str(), & item );
        if( handle != -1L )
        {
            do 
            {
                if( item.attrib & _A_SUBDIR )
                {
                    // ��¼��Ŀ¼
                    if( wcscmp(L".", item.name) != 0 && wcscmp(L"..", item.name) != 0 )
                    {
                        a_wstring subpath = current + L"/" + item.name;

                        // �������Ŀ¼����ô���ݱ�־����������Ŀ¼
                        if( sub_directory )
                        {
                            EnumDirectories( subpath.c_str(), files, sub_directory, absolute_path );
                        }
                            
                        if( absolute_path )
                        {
                            wchar_t fullpath[MAX_PATH];
                            _wfullpath( fullpath, subpath.c_str(), MAX_PATH );
                            subpath = fullpath;                            
                        }
                        files.push_back( subpath );
                    }
                }
            } 
            while( _wfindnext(handle, & item) == 0 );
            _findclose( handle );
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
void atom::CWin32Directory::EnumFiles(CStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    EnumFiles( path.c_str(), files, sub_directory, absolute_path );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CWin32Directory::EnumFiles(CWStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    EnumFiles( path.c_str(), files, sub_directory, absolute_path );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CWin32Directory::EnumDirectories(CStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    EnumDirectories( path.c_str(), files, sub_directory, absolute_path );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CWin32Directory::EnumDirectories(CWStringArray & files, bool sub_directory, bool absolute_path) 
{
    //TODO Auto-generated method stub
    EnumDirectories( path.c_str(), files, sub_directory, absolute_path );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CWin32Directory::CreateDirectory() 
{
    //TODO Auto-generated method stub
    bool result = false;
    #ifdef _WIN32
    result = ( _wmkdir( path.c_str() ) == 0 );
    #endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CWin32Directory::RemoveDirectory(bool withfile) 
{
    //TODO Auto-generated method stub
    bool result = false;
    
    #ifdef _WIN32
    CWStringArray files;
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
                if( _wrmdir( files[i].c_str() ) != 0 ) {
                    result = false;
                }
            }
        }

        // ����Ƴ��ɹ�����ɾ��Ŀ��Ŀ¼��
        if( result ) {
            result = _wrmdir( path.c_str() ) == 0; 
        }
    }

    #else
    UNREFERENCED_PARAMETER( withfile );
    #endif

    return result;
}
