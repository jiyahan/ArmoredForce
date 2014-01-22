#ifndef CWIN32THREAD_H
#define CWIN32THREAD_H
#include "../../Common.h"
#include "CCriticalSection.h"
#include "../../enumeration/THREAD_PRIORITY.h"



namespace atom
{



    class CWin32Thread
    {


        private:


            std::string thread;



            void * handle;



            CCriticalSection region;




        public:

            explicit CWin32Thread(const char * name); 



            virtual ~CWin32Thread(); 



            const char * GetName(); 



            virtual bool Begin(U08 priority = TP_NORMAL); 



            virtual bool Close(U64 timeout); 



            virtual bool OnThreadBegin(); 



            virtual bool OnThreadClose(); 



            virtual U32 Run(); 



            static void Sleep(U64 milisecond); 



            static U64 GetCurrentThreadID(); 



    };  //end class CWin32Thread


}//end namespace atom


#endif
