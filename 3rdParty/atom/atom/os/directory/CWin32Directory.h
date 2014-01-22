#ifndef CWIN32DIRECTORY_H
#define CWIN32DIRECTORY_H
#include "../../utility/stl/a_wstring.h"
#include "../../utility/stl/CStringArray.h"
#include "../../utility/stl/CWStringArray.h"


namespace atom
{
    


    class CWin32Directory
    {


        private:


            a_wstring path;



            void EnumFiles(const wchar_t * path, CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            void EnumFiles(const wchar_t * path, CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 



            void EnumDirectories(const wchar_t * path, CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            void EnumDirectories(const wchar_t * path, CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 




        public:

            CWin32Directory(const char * path); 



            CWin32Directory(const wchar_t * path); 



            ~CWin32Directory(); 



            void EnumFiles(CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            void EnumFiles(CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 



            void EnumDirectories(CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            void EnumDirectories(CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 



            bool CreateDirectory(); 



            bool RemoveDirectory(bool withfile = false); 



    };  //end class CWin32Directory



} //end namespace atom



#endif
