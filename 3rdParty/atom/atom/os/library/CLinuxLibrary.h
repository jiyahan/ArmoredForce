#ifndef CLINUXLIBRARY_H
#define CLINUXLIBRARY_H
#include "../../utility/stl/a_string.h"



namespace atom
{



    class CLinuxLibrary
    {

        private:


            void * handle;



            a_string locate;




        public:

            CLinuxLibrary(); 



            virtual ~CLinuxLibrary(); 



            virtual bool Open(const char * file); 



            virtual bool Open(const wchar_t * file); 



            virtual void * GetFunction(const char * name); 



            virtual bool Close(); 



            // return utf8 charset as default;
            virtual a_string GetPath(); 



    };  //end class CLinuxLibrary


}//end namespace atom


#endif
