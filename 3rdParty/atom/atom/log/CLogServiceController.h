#ifndef CLOGSERVICECONTROLLER_H
#define CLOGSERVICECONTROLLER_H
#include "../interface/ILogServiceController.h"
#include "../interface/IInterface.h"
#include "../stream/writer/CDataWriter.h"
#include "../os/thread/CCriticalSection.h"
#include "CLogServiceControllerBind.h"



namespace atom
{



    class CLogServiceController : public ILogServiceController
    {


        private:


            IInterface * nest;



            U64 time;



            U08 show;



            CLogServiceControllerBind logs;



            CDataWriter data;



            CCriticalSection lock;



            CCriticalSection clog;




        public:

            CLogServiceController(); 



            virtual ~CLogServiceController(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual void Setup(U08 display_level, IInterface * output); 



            virtual void Clear(); 



            virtual void Write(U08 level, const char * log); 



            virtual void Flush(); 



    };  //end class CLogServiceController



} //end namespace atom



#endif
