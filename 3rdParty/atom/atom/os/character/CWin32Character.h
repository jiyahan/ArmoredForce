#ifndef CWIN32CHARACTER_H
#define CWIN32CHARACTER_H
#include "CCodePage.h"
#include "../memory/CMemory.h"
#include "../../utility/stl/a_wstring.h"
#include "../../utility/stl/a_string.h"



namespace atom
{



    class CWin32Character
    {



        public:

            inline static a_wstring MultiBytesToUnicode (const char * value, const char * codepage = DEFAULT_CODEPAGE); 



            inline static a_string MultiBytesToUtf8     (const char * value, const char * codepage = DEFAULT_CODEPAGE); 



            inline static a_string Utf8ToMultiBytes     (const char * value, const char * codepage = DEFAULT_CODEPAGE); 



            inline static a_wstring Utf8ToUnicode       (const char * value); 



            inline static a_string UnicodeToMultiBytes  (const wchar_t * value, const char * codepage = DEFAULT_CODEPAGE); 



            inline static a_string UnicodeToUtf8        (const wchar_t * value); 



    };  //end class CWin32Character


}//end namespace atom



atom::a_wstring atom::CWin32Character::MultiBytesToUnicode(const char * value, const char * codepage) 
{
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

atom::a_string atom::CWin32Character::MultiBytesToUtf8(const char * value, const char * codepage) 
{
    return UnicodeToUtf8( MultiBytesToUnicode( value, codepage ).c_str() );
}

atom::a_string atom::CWin32Character::Utf8ToMultiBytes(const char * value, const char * codepage) 
{
    return UnicodeToMultiBytes( Utf8ToUnicode(value).c_str(), codepage );
}

atom::a_wstring atom::CWin32Character::Utf8ToUnicode(const char * value) 
{
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

atom::a_string atom::CWin32Character::UnicodeToMultiBytes(const wchar_t * value, const char * codepage) 
{
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

atom::a_string atom::CWin32Character::UnicodeToUtf8(const wchar_t * value) 
{
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
