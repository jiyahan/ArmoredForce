#ifndef CWIN32CHARACTER_H
#define CWIN32CHARACTER_H
//Begin section for file CWin32Character.h
//TODO: Add definitions that you want preserved
//End section for file CWin32Character.h
#include "CCodePage.h"
#include "../memory/CMemory.h"
#include "../../utility/stl/a_wstring.h"
#include "../../utility/stl/a_string.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CWin32Character
    {
        //Begin section for atom::CWin32Character
        //TODO: Add attributes that you want preserved
        //End section for atom::CWin32Character



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static a_wstring MultiBytesToUnicode (const char * value, const char * codepage = DEFAULT_CODEPAGE); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static a_string MultiBytesToUtf8     (const char * value, const char * codepage = DEFAULT_CODEPAGE); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static a_string Utf8ToMultiBytes     (const char * value, const char * codepage = DEFAULT_CODEPAGE); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static a_wstring Utf8ToUnicode       (const char * value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static a_string UnicodeToMultiBytes  (const wchar_t * value, const char * codepage = DEFAULT_CODEPAGE); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static a_string UnicodeToUtf8        (const wchar_t * value); 



    };  //end class CWin32Character


}//end namespace atom



//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_wstring atom::CWin32Character::MultiBytesToUnicode(const char * value, const char * codepage) 
{
    //TODO Auto-generated method stub
    a_wstring result;
    if( value && codepage )
    {
        #ifdef _WIN32
        size_t length = strlen( value );
        size_t amount = sizeof( wchar_t ) * ( length + 1 );

        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, amount );

                MultiByteToWideChar( CCodePage::GetInstance() -> CodePage(codepage), 0, 
                    value, static_cast<int>(length), data.Query<wchar_t>(), static_cast<int>(amount) );
                
                result = data.Query<wchar_t>();
            }
        }
        #endif
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CWin32Character::MultiBytesToUtf8(const char * value, const char * codepage) 
{
    //TODO Auto-generated method stub
    return UnicodeToUtf8( MultiBytesToUnicode( value, codepage ).c_str() );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CWin32Character::Utf8ToMultiBytes(const char * value, const char * codepage) 
{
    //TODO Auto-generated method stub
    return UnicodeToMultiBytes( Utf8ToUnicode(value).c_str(), codepage );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_wstring atom::CWin32Character::Utf8ToUnicode(const char * value) 
{
    //TODO Auto-generated method stub
    a_wstring result;
    if( value )
    {
        #ifdef _WIN32
        size_t length = strlen( value );
        size_t amount = sizeof( wchar_t ) * ( length + 1 );
            
        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, amount );
                                        
                MultiByteToWideChar( CP_UTF8, 0, value, static_cast<int>(length), 
                    data.Query<wchar_t>(), static_cast<int>(amount) );
    
                result = data.Query<wchar_t>();
            }
        }
        #endif
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CWin32Character::UnicodeToMultiBytes(const wchar_t * value, const char * codepage) 
{
    //TODO Auto-generated method stub
    a_string result;
    if( value && codepage )
    {
        #ifdef _WIN32
        size_t length = wcslen( value );
        size_t amount = length * sizeof( wchar_t ) + 1;
            
        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, amount );
                    
                WideCharToMultiByte( CCodePage::GetInstance() -> CodePage(codepage), 0, 
                    value, static_cast<int>(length), 
                    data.Query<char>(), static_cast<int>(amount), NULL, NULL );
    
                result = data.Query<char>();
            }
        }
        #endif
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CWin32Character::UnicodeToUtf8(const wchar_t * value) 
{
    //TODO Auto-generated method stub
    a_string result;
    if( value )
    {
        #ifdef _WIN32
        size_t length = wcslen( value );
        size_t amount = ( length + 1 ) * 3;

        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, amount );
                    
                WideCharToMultiByte( CP_UTF8, 0, value, static_cast<int>(length), 
                    data.Query<char>(), static_cast<int>(amount), NULL, NULL );

                result = data.Query<char>();
            }
        }
        #endif
    }
    return result;
}

#endif
