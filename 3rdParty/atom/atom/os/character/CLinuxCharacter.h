#ifndef CLINUXCHARACTER_H
#define CLINUXCHARACTER_H
#include "../memory/CMemory.h"
#include "../../utility/stl/a_wstring.h"
#include "../../utility/stl/a_string.h"



namespace atom
{



    class CLinuxCharacter
    {



        public:

            inline static a_wstring MultiBytesToUnicode (const char * value, const char * codepage = DEFAULT_CODEPAGE);



            inline static a_string MultiBytesToUtf8     (const char * value, const char * codepage = DEFAULT_CODEPAGE); 



            inline static a_string Utf8ToMultiBytes     (const char * value, const char * codepage = DEFAULT_CODEPAGE); 



            inline static a_wstring Utf8ToUnicode       (const char * value); 



            inline static a_string UnicodeToMultiBytes  (const wchar_t * value, const char * codepage = DEFAULT_CODEPAGE); 



            inline static a_string UnicodeToUtf8        (const wchar_t * value); 



    };  //end class CLinuxCharacter


}//end namespace atom



atom::a_wstring atom::CLinuxCharacter::MultiBytesToUnicode(const char * value, const char * codepage) 
{
    a_wstring result;
    if( value && codepage )
    {
        #ifdef __linux
        size_t length = strlen( value );
        size_t amount = sizeof( wchar_t ) * ( length + 1 );
            
        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, amount );
                    
                iconv_t env = iconv_open( "WCHAR_T", codepage );
                if( env != (iconv_t)-1 )
                {
                    char* out = data.Query<char>();
                    iconv( env, (char**)&value, &length, &out, &amount );
                    iconv_close( env );
                }

                result = data.Query<wchar_t>();
            }
        }
        #endif
    }
    return result;
}

atom::a_string atom::CLinuxCharacter::MultiBytesToUtf8(const char * value, const char * codepage) 
{
    a_string result;
    if( value && codepage )
    {
        #ifdef __linux
        size_t length = strlen( value );
        size_t amount = ( length + 1 ) * 3;
            
        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, amount );
                                
                iconv_t env = iconv_open( "UTF8", codepage );
                if( env != (iconv_t)-1 )
                {
                    char* out = data.Query<char>();
                    iconv( env, (char**)&value, &length, &out, &amount );
                    iconv_close( env );
                }
            }
            result = data.Query<char>();
        }
        #endif
    }
    return result;
}

atom::a_string atom::CLinuxCharacter::Utf8ToMultiBytes(const char * value, const char * codepage) 
{
    a_string result;
    if( value && codepage )
    {
        #ifdef __linux
        size_t length = strlen( value );
        size_t amount = length + 1;
            
        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, amount );
    
                iconv_t env = iconv_open( codepage, "UTF8" );
                if( env != (iconv_t)-1 )
                {
                    char* out = data.Query<char>();
                    iconv( env, (char**)&value, &length, &out, &amount );
                    iconv_close( env );
                }
            }
            result = data.Query<char>();
        }
        #endif
    }
    return result;
}

atom::a_wstring atom::CLinuxCharacter::Utf8ToUnicode(const char * value) 
{
    a_wstring result;
    if( value )
    {
        #ifdef __linux
        size_t length = strlen( value );
        size_t amount = sizeof( wchar_t ) * ( length + 1 );
            
        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, amount );
                    
                iconv_t env = iconv_open( "WCHAR_T", "UTF8" );
                if( env != (iconv_t)-1 )
                {
                    char* out = data.Query<char>();
                    iconv( env, (char**)&value, &length, &out, &amount );
                    iconv_close( env );
                }

                result = data.Query<wchar_t>();
            }
        }
        #endif
    }
    return result;
}

atom::a_string atom::CLinuxCharacter::UnicodeToMultiBytes(const wchar_t * value, const char * codepage) 
{
    a_string result;
    if( value && codepage )
    {
        #ifdef __linux
        size_t length = wcslen( value );
        size_t amount = length * sizeof( wchar_t ) + 1;
            
        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, amount );
                    
                iconv_t env = iconv_open( codepage , "WCHAR_T" );
                if( env != (iconv_t)-1 )
                {
                    char* out = data.Query<char>();
                    size_t il = length * sizeof( wchar_t );
                    iconv( env, (char**)&value, &il, &out, &amount );
                    iconv_close( env );
                }

                result = data.Query<char>();
            }
        }
        #endif
    }
    return result;
}

atom::a_string atom::CLinuxCharacter::UnicodeToUtf8(const wchar_t * value) 
{
    a_string result;
    if( value )
    {
        #ifdef __linux
        size_t length = wcslen( value );
        size_t amount = ( length + 1 ) * 3;

        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, amount );
                    
                iconv_t env;
                env = iconv_open( "UTF8", "WCHAR_T" );
                if( env != (iconv_t)-1 )
                {
                    char* out = data.Query<char>();
                    size_t il = length * sizeof( wchar_t );
                    iconv( env, (char**)&value, &il, &out, &amount );
                    iconv_close( env );
                }

                result = data.Query<char>();
            }
        }
        #endif
    }
    return result;
}

#endif
