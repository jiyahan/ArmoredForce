#include "CCharset.h"


bool atom::CCharset::IsUtf8(const char * string) 
{
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
		}
	}
    return result;
}
