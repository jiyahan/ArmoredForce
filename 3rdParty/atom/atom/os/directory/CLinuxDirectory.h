#ifndef CLINUXDIRECTORY_H
#define CLINUXDIRECTORY_H
#include "../../utility/stl/a_string.h"
#include "../../utility/stl/CStringArray.h"
#include "../../utility/stl/CWStringArray.h"


namespace atom
{



    class CLinuxDirectory
    {


		// Linux ext2, ext3, ext4 file system support stream-style file name, that will be the nightmare, 
        // it does not have to use some constraint character set, so, input ansi path name will never been 
		// change, user should use the correct character set to visit directory,  unicode input will be 
        // convert to utf8 format, and output will be convert to utf8 or unicode ucs string.

        private:


            a_string path;



            void EnumFiles(const char * path, CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            void EnumFiles(const char * path, CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 



            void EnumDirectories(const char * path, CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            void EnumDirectories(const char * path, CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 




        public:

            CLinuxDirectory(const char * path); 



            CLinuxDirectory(const wchar_t * path); 



            ~CLinuxDirectory(); 



            void EnumFiles(CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            void EnumFiles(CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 



            void EnumDirectories(CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            void EnumDirectories(CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 



            bool CreateDirectory(); 



            bool RemoveDirectory(bool withfile = false); 



    };  //end class CLinuxDirectory



} //end namespace atom



#endif
