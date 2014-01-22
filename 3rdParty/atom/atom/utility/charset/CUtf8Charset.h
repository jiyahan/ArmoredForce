#ifndef CUTF8CHARSET_H
#define CUTF8CHARSET_H
#include "../../Common.h"
#include "../stl/CU08Array.h"



namespace atom
{



	class CUtf8Charset
	{




		public:

			static bool IsUtf8(const char * string); 



			static size_t Utf8Length(const char * string); 

    
    
            static size_t Utf8Section(const char * string, CU08Array & section); 



    };  //end class CUtf8Charset



} //end namespace atom



#endif
