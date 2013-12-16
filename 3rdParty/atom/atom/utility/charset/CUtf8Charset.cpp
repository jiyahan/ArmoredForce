#include "CUtf8Charset.h"
//Begin section for file CUtf8Charset.cpp
//TODO: Add definitions that you want preserved
//End section for file CUtf8Charset.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CUtf8Charset::IsUtf8(const char * string) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( string )
	{
		result = true;
		unsigned char * sp = reinterpret_cast<unsigned char *>( const_cast<char *>(string) );
		unsigned char * ep = sp + strlen( string );

		while( sp < ep )
		{
			// is ascii code
			if( * sp < 0x80 ) 
			{
				// only one character
				++ sp;
			}
			else
			if( * sp < 0xC0 ) 
			{
				// invalid utf8 character
				result = false; break;
			}
			else
			if( * sp < 0xE0 ) 
			{
				// with two character,
				// check does utf8-string is correct or not.
				if( sp + 1 >= ep ) {
					result = false; break;
				}

				if( 0x80 != (sp[1] & 0xC0) ) {  
					result = false; break;  
				} 

				sp += 2;
			}
			else
			if( * sp < 0xF0 )
			{
				// with three character,
				// check does utf8-string is correct or not.
				if( sp + 2 >= ep ) {
					result = false; break;
				}

				if( 0x80 != (sp[1] & 0xC0) ||
					0x80 != (sp[2] & 0xC0) ) {  
					result = false; break;  
				} 

				sp += 3;
			}
			else
            if( * sp < 0xF8 )
			{
				// with four character,
				// check does utf8-string is correct or not.
				if( sp + 3 >= ep ) {
					result = false; break;
				}

				if( 0x80 != (sp[1] & 0xC0) ||
					0x80 != (sp[2] & 0xC0) ||
					0x80 != (sp[3] & 0xC0) ) {  
					result = false; break;  
				} 

				sp += 4;
			}
			else
            if( * sp < 0xFC )
			{
				// with five character,
				// check does utf8-string is correct or not.
				if( sp + 4 >= ep ) {
					result = false; break;
				}

				if( 0x80 != (sp[1] & 0xC0) ||
					0x80 != (sp[2] & 0xC0) ||
					0x80 != (sp[3] & 0xC0) ||
					0x80 != (sp[4] & 0xC0) ) {  
					result = false; break;  
				} 

				sp += 5;
			}
            else
			{
				// with six character,
				// check does utf8-string is correct or not.
				if( sp + 5 >= ep ) {
					result = false; break;
				}

				if( 0x80 != (sp[1] & 0xC0) ||
					0x80 != (sp[2] & 0xC0) ||
					0x80 != (sp[3] & 0xC0) ||
					0x80 != (sp[4] & 0xC0) ||
					0x80 != (sp[5] & 0xC0) ) {  
					result = false; break;  
				} 

				sp += 6;
			}
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
size_t atom::CUtf8Charset::Utf8Length(const char * string)
{
    //TODO Auto-generated method stub
	size_t result = 0;
	if( string )
	{
		unsigned char * sp = reinterpret_cast<unsigned char *>( const_cast<char *>(string) );
		unsigned char * ep = sp + strlen( string );

		while( sp < ep )
		{
			// is ascii code
			if( * sp < 0x80 ) 
			{
				// only one character
				++ sp; ++ result;
			}
			else
			if( * sp < 0xC0 ) 
			{
				// invalid utf8 character
				result = 0; break;
			}
			else
			if( * sp < 0xE0 ) 
			{
				// with two character,
				// check does utf8-string is correct or not.
				if( sp + 1 >= ep ) {
					result = 0; break;
				}

				if( 0x80 != (sp[1] & 0xC0) ) {  
					result = 0; break;  
				} 

				sp += 2; ++ result;
			}
			else
			if( * sp < 0xF0 )
			{
				// with three character,
				// check does utf8-string is correct or not.
				if( sp + 2 >= ep ) {
					result = 0; break;
				}

				if( 0x80 != (sp[1] & 0xC0) ||
					0x80 != (sp[2] & 0xC0) ) {  
					result = 0; break;  
				} 

				sp += 3; ++ result;
			}
			else
            if( * sp < 0xF8 )
			{
				// with four character,
				// check does utf8-string is correct or not.
				if( sp + 3 >= ep ) {
					result = 0; break;
				}

				if( 0x80 != (sp[1] & 0xC0) ||
					0x80 != (sp[2] & 0xC0) ||
					0x80 != (sp[3] & 0xC0) ) {  
					result = 0; break;  
				} 

				sp += 4; ++ result;
			}
			else
            if( * sp < 0xFC )
			{
				// with five character,
				// check does utf8-string is correct or not.
				if( sp + 4 >= ep ) {
					result = 0; break;
				}

				if( 0x80 != (sp[1] & 0xC0) ||
					0x80 != (sp[2] & 0xC0) ||
					0x80 != (sp[3] & 0xC0) ||
					0x80 != (sp[4] & 0xC0) ) {  
					result = 0; break;  
				} 

				sp += 5; ++ result;
			}
            else
			{
				// with six character,
				// check does utf8-string is correct or not.
				if( sp + 5 >= ep ) {
					result = 0; break;
				}

				if( 0x80 != (sp[1] & 0xC0) ||
					0x80 != (sp[2] & 0xC0) ||
					0x80 != (sp[3] & 0xC0) ||
					0x80 != (sp[4] & 0xC0) ||
					0x80 != (sp[5] & 0xC0) ) {  
					result = 0; break;  
				} 

				sp += 6; ++ result;
			}
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
size_t atom::CUtf8Charset::Utf8Section(const char * string, CU08Array & section)
{
    //TODO Auto-generated method stub
	size_t result = 0;
	if( string )
	{
        // calculate start pointer and end pointer.
		unsigned char * sp = reinterpret_cast<unsigned char *>( const_cast<char *>(string) );
		unsigned char * ep = sp + strlen( string );

        // reserve memory space first.
        section.reserve( ep - sp );

        // check characters is valid.
		while( sp < ep )
		{
			// is ascii code
			if( * sp < 0x80 ) 
			{
				// only one character
                ++ sp; ++ result; 
                section.push_back( 1 );
			}
			else
			if( * sp < 0xC0 ) 
			{
				// invalid utf8 character
				result = 0; section.clear();
                break;
			}
			else
			if( * sp < 0xE0 ) 
			{
				// with two character,
				// check does utf8-string is correct or not.
				if( sp + 1 >= ep ) {
				    result = 0; section.clear();
                    break;
				}

				if( 0x80 != (sp[1] & 0xC0) ) {  
				    result = 0; section.clear();
                    break;
				} 

				sp += 2; ++ result;
                section.push_back( 2 );
			}
			else
			if( * sp < 0xF0 )
			{
				// with three character,
				// check does utf8-string is correct or not.
				if( sp + 2 >= ep ) {
				    result = 0; section.clear();
                    break;
				}

				if( 0x80 != (sp[1] & 0xC0) ||
					0x80 != (sp[2] & 0xC0) ) {  
				    result = 0; section.clear();
                    break;
				} 

				sp += 3; ++ result;
                section.push_back( 3 );
			}
			else
            if( * sp < 0xF8 )
			{
				// with four character,
				// check does utf8-string is correct or not.
				if( sp + 3 >= ep ) {
				    result = 0; section.clear();
                    break;
				}

				if( 0x80 != (sp[1] & 0xC0) ||
					0x80 != (sp[2] & 0xC0) ||
					0x80 != (sp[3] & 0xC0) ) {  
				    result = 0; section.clear();
                    break;
				} 

				sp += 4; ++ result;
                section.push_back( 4 );
			}
			else
            if( * sp < 0xFC )
			{
				// with five character,
				// check does utf8-string is correct or not.
				if( sp + 4 >= ep ) {
				    result = 0; section.clear();
                    break;
				}

				if( 0x80 != (sp[1] & 0xC0) ||
					0x80 != (sp[2] & 0xC0) ||
					0x80 != (sp[3] & 0xC0) ||
					0x80 != (sp[4] & 0xC0) ) {  
				    result = 0; section.clear();
                    break;
				} 

				sp += 5; ++ result;
                section.push_back( 5 );
			}
            else
			{
				// with six character,
				// check does utf8-string is correct or not.
				if( sp + 5 >= ep ) {
				    result = 0; section.clear();
                    break;
				}

				if( 0x80 != (sp[1] & 0xC0) ||
					0x80 != (sp[2] & 0xC0) ||
					0x80 != (sp[3] & 0xC0) ||
					0x80 != (sp[4] & 0xC0) ||
					0x80 != (sp[5] & 0xC0) ) {  
				    result = 0; section.clear();
                    break;
				} 

				sp += 6; ++ result;
                section.push_back( 6 );
			}
		}
	}
    return result;
}
