#ifndef CPATH_H
#define CPATH_H
#include "../../utility/stl/a_string.h"



namespace atom
{



    class CPath
    {


        private:


            a_string path;




        public:

            CPath(const char * path); 



            CPath(const wchar_t * path); 



            virtual ~CPath(); 



            a_string GetFileName(); 



            a_string GetFilePath(); 



            bool IsMatch(const char * wildcard); 



            bool IsMatch(const wchar_t * wildcard); 



            operator const char *(); 



    };  //end class CPath


}//end namespace atom


#endif
