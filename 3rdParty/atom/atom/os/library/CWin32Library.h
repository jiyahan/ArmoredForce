#ifndef CWIN32LIBRARY_H
#define CWIN32LIBRARY_H
#include "../../utility/stl/a_string.h"
#include "../../utility/stl/a_wstring.h"



namespace atom
{



    class CWin32Library
    {

        private:


            void * handle;



            a_wstring locate;




        public:

            CWin32Library(); 



            virtual ~CWin32Library(); 



            virtual bool Open(const char * file); 



            virtual bool Open(const wchar_t * file); 



            virtual void * GetFunction(const char * name); 



            virtual bool Close(); 



            // return utf8 charset as default;
            virtual a_string GetPath(); 



    };  //end class CWin32Library


}//end namespace atom


#endif
