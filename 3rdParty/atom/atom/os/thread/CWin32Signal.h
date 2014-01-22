#ifndef CWIN32SIGNAL_H
#define CWIN32SIGNAL_H
#include "../../Common.h"


namespace atom
{



    class CWin32Signal
    {


        private:


            void * handle;




        public:

            CWin32Signal(); 



            explicit CWin32Signal(const char * name); 



            ~CWin32Signal(); 



            bool Reset(); 



            bool Awake(); 



            bool Await(U64 timeout); 



    };  //end class CWin32Signal


}//end namespace atom


#endif
