#include "CFile.h"
#include "../character/CCharacter.h"
#include "../../utility/charset/CUtf8Charset.h"
#include "../../utility/tool/CInterface.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CFile.cpp
//TODO: Add definitions that you want preserved
//End section for file CFile.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CFile::CFile(const char * name) 
{
    //TODO Auto-generated method stub
    stream.SetNest( this );
    if( name ) 
	{
		#if defined(__APPLE__)
		if( CUtf8Charset::IsUtf8(name) ) {
			stream.SetDevice( name );
		} else {
			stream.SetDevice( CCharacter::MultiBytesToUtf8(name).c_str() );
		}
        #endif

        #if defined(_WIN32)
        if( CUtf8Charset::IsUtf8(name) ) {
            stream.SetDevice( CCharacter::Utf8ToUnicode      (name).c_str() );
        } else {
            stream.SetDevice( CCharacter::MultiBytesToUnicode(name).c_str() );
        }
        #endif

        #if defined(__linux)
        stream.SetDevice( name );
		#endif
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CFile::CFile(const wchar_t * name) 
{
    //TODO Auto-generated method stub
    stream.SetNest( this );
    if( name ) 
	{
		#if defined(__APPLE__) || defined(__linux)
        stream.SetDevice( CCharacter::UnicodeToUtf8( name ).c_str() );
        #endif

        #if defined(_WIN32)
        stream.SetDevice( name );
		#endif
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CFile::~CFile() 
{
    //TODO Auto-generated method stub
    stream.Close();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CFile::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_STREAM:
    case IID_FILE_STREAM:
        result = & stream;
        break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CFile::Open() 
{
    //TODO Auto-generated method stub
    return stream.Open();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFile::Mark(U64 position) 
{
    //TODO Auto-generated method stub
    stream.Mark( position );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFile::Close() 
{
    //TODO Auto-generated method stub
    stream.Close();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CFile::Length() 
{
    //TODO Auto-generated method stub
    return stream.Length();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CFile::IsReadOnly()
{
    //TODO Auto-generated method stub
    return stream.IsReadOnly();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CFile::Erase(const char * file) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( file ) 
	{
		#if defined(__APPLE__)
		if( CUtf8Charset::IsUtf8(file) ) {
            result = ( 0 == remove( file ) );
		} else {
            result = ( 0 == remove( CCharacter::MultiBytesToUtf8(file).c_str() ) );
		}
        #endif

        #if defined(_WIN32)
		if( CUtf8Charset::IsUtf8(file) ) {
            result = ( 0 == _wremove( CCharacter::Utf8ToUnicode      (file).c_str() ) );
		} else {
            result = ( 0 == _wremove( CCharacter::MultiBytesToUnicode(file).c_str() ) );
		}
        #endif

        #if defined(__linux)
        result = ( 0 == remove( file ) );
		#endif
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CFile::Erase(const wchar_t * file) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( file ) 
	{
		#if defined(__APPLE__) || defined(__linux)
        result = ( 0 == remove( CCharacter::UnicodeToUtf8(file).c_str() ) );
        #endif

        #if defined(_WIN32)
        result = ( 0 == _wremove(file) );
		#endif
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemory atom::CFile::LoadFile(const char * name) 
{
    //TODO Auto-generated method stub
    CMemory result;

    CFile file( name );
    if( file.Open() )
    {
        CInterface<IFileStream> segment;
        if( segment.Mount(&file, IID_FILE_STREAM) ) {
            segment -> Clone( result );
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemory atom::CFile::LoadFile(const wchar_t * name) 
{
    //TODO Auto-generated method stub
    CMemory result;

    CFile file( name );
    if( file.Open() )
    {
        CInterface<IFileStream> segment;
        if( segment.Mount(&file, IID_FILE_STREAM) ) {
            segment -> Clone( result );
        }
    }
    return result;
}
