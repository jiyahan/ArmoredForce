#ifndef CAPPLEDIRECTORY_H
#define CAPPLEDIRECTORY_H
#include "../../utility/stl/a_string.h"
#include "../../utility/stl/CStringArray.h"
#include "../../utility/stl/CWStringArray.h"



namespace atom
{



	class CAppleDirectory
	{


		// mac os only support utf-8 format file system, so, input ansi path will be 
		// converted to utf-8 format, and under apple os, all file and directory api
		// output will be also utf-8 format.

        // in our project, the input path under different platform can be different, 
        // we can check char * 's format: utf8 or multi-bytes, and convert to platform
        // accepted format.

        // in our project, the output under different platform will be the same, 
        // char * means utf8 charset, and wchar_t means unicode.

		private:


			a_string path;



			void EnumFiles(const char * path, CStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			void EnumFiles(const char * path, CWStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			void EnumDirectories(const char * path, CStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			void EnumDirectories(const char * path, CWStringArray & files, bool sub_directory=true, bool absolute_path=true); 




		public:

			CAppleDirectory(const char * path); 



			CAppleDirectory(const wchar_t * path); 



			~CAppleDirectory(); 



			void EnumFiles(CStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			void EnumFiles(CWStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			void EnumDirectories(CStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			void EnumDirectories(CWStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			bool CreateDirectory(); 



			bool RemoveDirectory(bool withfile=false); 



	};  //end class CAppleDirectory



} //end namespace atom



#endif
