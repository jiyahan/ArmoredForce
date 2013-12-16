#ifndef CAPPLECHARACTER_H
#define CAPPLECHARACTER_H
//Begin section for file CAppleCharacter.h
//TODO: Add definitions that you want preserved
//End section for file CAppleCharacter.h
#include "../memory/CMemory.h"
#include "../../utility/stl/a_wstring.h"
#include "../../utility/stl/a_string.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CAppleCharacter
	{

		//Begin section for atom::CAppleCharacter
		//TODO: Add attributes that you want preserved
		//End section for atom::CAppleCharacter



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline static a_wstring MultiBytesToUnicode(const char * value, const char * codepage = DEFAULT_CODEPAGE); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline static a_string MultiBytesToUtf8    (const char * value, const char * codepage = DEFAULT_CODEPAGE); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline static a_string Utf8ToMultiBytes    (const char * value, const char * codepage = DEFAULT_CODEPAGE); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline static a_wstring Utf8ToUnicode      (const char * value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline static a_string UnicodeToMultiBytes (const wchar_t * value, const char * codepage = DEFAULT_CODEPAGE); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline static a_string UnicodeToUtf8       (const wchar_t * value); 



	};  //end class CAppleCharacter



} //end namespace atom



//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_wstring atom::CAppleCharacter::MultiBytesToUnicode(const char * value, const char * codepage) 
{
    //TODO Auto-generated method stub
    a_wstring result;
    if( value && codepage )
    {
        #ifdef __APPLE__
        size_t length = strlen( value );
        size_t amount = sizeof( wchar_t ) * ( length + 1 );
            
        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, data.GetCapacity() );
                    
                iconv_t env = iconv_open( "WCHAR_T", codepage );
                if( env != (iconv_t) -1 )
                {
                    char * is = const_cast<char *>( value );
                    char * os = data.Query<char>();

                    size_t il = length;
                    size_t ol = data.GetCapacity();

                    iconv( env, & is, & il, & os, & ol );
                    iconv_close( env );
                }

                result = data.Query<wchar_t>();
            }
        }
        #endif
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CAppleCharacter::MultiBytesToUtf8(const char * value, const char * codepage) 
{
    //TODO Auto-generated method stub
    a_string result;
    if( value && codepage )
    {
        #ifdef __APPLE__
        size_t length = strlen( value );
        size_t amount = ( length + 1 ) * 3;
            
        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, data.GetCapacity() );
                                
                iconv_t env = iconv_open( "UTF-8", codepage );
                if( env != (iconv_t)-1 )
                {
                    char * is = const_cast<char *>( value );
                    char * os = data.Query<char>();

                    size_t il = length;
                    size_t ol = data.GetCapacity();

                    iconv( env, & is, & il, & os, & ol );
                    iconv_close( env );
                }
            }
            result = data.Query<char>();
        }
        #endif
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CAppleCharacter::Utf8ToMultiBytes(const char * value, const char * codepage) 
{
    //TODO Auto-generated method stub
    a_string result;
    if( value && codepage )
    {
        #ifdef __APPLE__
        size_t length = strlen( value );
        size_t amount = length + 1;
            
        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, data.GetCapacity() );
    
                iconv_t env = iconv_open( codepage, "UTF8" );
                if( env != (iconv_t) -1 )
                {
                    char * is = const_cast<char *>( value );
                    char * os = data.Query<char>();

                    size_t il = length;
                    size_t ol = data.GetCapacity();

                    iconv( env, & is, & il, & os, & ol );
                    iconv_close( env );
                }
            }
            result = data.Query<char>();
        }
        #endif
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_wstring atom::CAppleCharacter::Utf8ToUnicode(const char * value) 
{
    //TODO Auto-generated method stub
    a_wstring result;
    if( value )
    {
        #ifdef __APPLE__
        size_t length = strlen( value );
        size_t amount = sizeof( wchar_t ) * ( length + 1 );
            
        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, data.GetCapacity() );
                    
                iconv_t env = iconv_open( "WCHAR_T", "UTF8" );
                if( env != (iconv_t) -1 )
                {
                    char * is = const_cast<char *>( value );
                    char * os = data.Query<char>();

                    size_t il = length;
                    size_t ol = data.GetCapacity();

                    iconv( env, & is, & il, & os, & ol );
                    iconv_close( env );
                }

                result = data.Query<wchar_t>();
            }
        }
        #endif
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CAppleCharacter::UnicodeToMultiBytes(const wchar_t * value, const char * codepage) 
{
    //TODO Auto-generated method stub
    a_string result;
    if( value && codepage )
    {
        #ifdef __APPLE__
        size_t length = wcslen( value );
        size_t amount = length * sizeof( wchar_t ) + 1;
            
        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, data.GetCapacity() );
                    
                iconv_t env = iconv_open( codepage , "WCHAR_T" );
                if( env != (iconv_t) -1 )
                {
                    char * is = reinterpret_cast<char *>( const_cast<wchar_t *>( value ) );
                    char * os = data.Query<char>();

                    size_t il = length * sizeof( wchar_t );
                    size_t ol = data.GetCapacity();

                    iconv( env, & is, & il, & os, & ol );
                    iconv_close( env );
                }

                result = data.Query<char>();
            }
        }
        #endif
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CAppleCharacter::UnicodeToUtf8(const wchar_t * value) 
{
    //TODO Auto-generated method stub
    a_string result;
    if( value )
    {
        #ifdef __APPLE__
        size_t length = wcslen( value );
        size_t amount = ( length + 1 ) * 3;

        // 如果长度不为0，则继续，否则直接返回一个空的字符串；
        if( length != 0 )
        {                
            CMemory data;
            if( data.Alloc(amount) )
            {
                memset( data, 0, data.GetCapacity() );
                    
                iconv_t env;
                env = iconv_open( "UTF8", "WCHAR_T" );
                if( env != (iconv_t) -1 )
                {
                    char * is = reinterpret_cast<char *>( const_cast<wchar_t *>( value ) );
                    char * os = data.Query<char>();

                    size_t il = length * sizeof( wchar_t );
                    size_t ol = data.GetCapacity();

                    iconv( env, & is, & il, & os, & ol );
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
