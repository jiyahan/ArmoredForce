#include "CPath.h"
#include "../character/CCharacter.h"


bool FindInTestword(const char value, size_t placeholder, const char* testword, size_t length, size_t& offset)
{
    bool result = false;
    if( testword && offset < length )
    {
        if( 0 == value ) {
            result = ( placeholder <= length - offset );
            offset = length;
            return result;
        }

        for( size_t i = 0; offset < length; ++ offset, ++ i )
        {
            if( value == testword[offset] ) {
                result = ( placeholder <= i ); if( result ) break;
            }
        }
    }
    return result;
}

bool FindInWildcard(const char* wildcard, size_t length, size_t& offset, size_t& placeholder, char& value)
{
    placeholder = 0;
    bool result = false;
    if( wildcard && offset <= length )
    {
        for( ; offset < length; ++ offset )
        {
            if( wildcard[offset] == '?' ) {
                ++ placeholder;
            }
            else
            if( wildcard[offset] == '*' ) {
            }
            else
            {
                value  = wildcard[offset];
                result = true; break;
            }
        }
        if( offset == length ) result = true;
    }
    return result;
}

bool IsAnsiMatch(const char* wildcard, size_t length_1, size_t& offset_1, const char* testword, size_t length_2, size_t& offset_2)
{
    bool result = false;
    if( wildcard && length_1 && offset_1 < length_1 &&
        testword && length_2 && offset_2 < length_2 )
    {
        // 先决条件是测试字符串的长度必须大于等于通配符长度；
        result = ( length_1 <= length_2 );
        if( result )
        {
            for( ; offset_1 < length_1; ++ offset_1 )
            {
                if( wildcard[offset_1] == '*' )
                {
                    char value(0); 
					size_t  o1(0);
					size_t  o2(0);
					size_t  placeholder(0); 

                    while( result && offset_1 < length_1 )
                    {
                        result = false;
                        if( FindInWildcard(wildcard, length_1, offset_1, placeholder, value) )
                        {
                            result = ( !value && !placeholder ); if( result ) break;
                            while( offset_2 < length_2 )
                            {
                                if( FindInTestword(value, placeholder, testword, length_2, offset_2) )
                                {
                                    result = !value; if( result ) break;
                                    o1 = offset_1;
                                    o2 = offset_2 ++;
                                    result = IsAnsiMatch( wildcard, length_1, o1, testword, length_2, o2 );
                                    if( result ) {
                                        offset_1 = o1; offset_2 = o2; break;
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
                else
                if( wildcard[offset_1] == '?' )
                {
                    if( ++ offset_2 >= length_2 ) { 
                        result = false; break; 
                    }
                }
                else
                {
                    if( wildcard[offset_1] != testword[offset_2++] ) {
                        result = false; break; 
                    }
                }
            }
        }
    }
    return result;
}

atom::CPath::CPath(const char * value) 
{
    if( value ) path = value;
}

atom::CPath::CPath(const wchar_t * value) 
{
    if( value ) {
        path = CCharacter::UnicodeToMultiBytes( value );
    }
}

atom::CPath::~CPath() 
{
}

atom::a_string atom::CPath::GetFileName() 
{
    size_t offset = path.find_last_of( '\\' );
    if( offset == a_string::npos ) {
        offset = path.find_last_of( '/' );
    }

    a_string result;
    if( offset != a_string::npos ) {
        result = path.substr( offset + 1, path.length() - offset - 1 );
    }
    return result;
}

atom::a_string atom::CPath::GetFilePath() 
{
    size_t offset = path.find_last_of( '\\' );
    if( offset == a_string::npos ) {
        offset = path.find_last_of( '/' );
    }

    a_string result;
    if( offset != a_string::npos ) {
           result = path.substr( 0, offset + 1 );
    }
    return result;
}

bool atom::CPath::IsMatch(const char * wildcard) 
{
    bool result = false;
    if( wildcard )
    {
        size_t offset_1 = 0, offset_2 = 0;
        size_t length_1 = strlen( wildcard );
        size_t length_2 = path.length();

        result = IsAnsiMatch( 
            wildcard, length_1, offset_1, path.c_str(), length_2, offset_2 );
    }
    return result;
}

bool atom::CPath::IsMatch(const wchar_t * wildcard) 
{
    bool result = false;
    if( wildcard ) {
        result = IsMatch( CCharacter::UnicodeToMultiBytes(wildcard).c_str() );
    }
    return result;
}

atom::CPath::operator const char *() 
{
    return path.c_str();
}
