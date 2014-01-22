#ifndef CLOGSERVICE_H
#define CLOGSERVICE_H
#include "../interface/IReferencedObject.h"
#include "CLogServiceSingletonBind.h"
#include "../os/thread/CReference.h"
#include "CLogServiceLife.h"
#include "CLogServiceMaintainer.h"
#include "CLogServiceController.h"
#include "../interface/IInterface.h"



namespace atom
{



    class CLogService : public IReferencedObject, public CLogServiceSingletonBind
    {


        private:


            CReference lock;



            CLogServiceLife life;



            CLogServiceMaintainer maintainer;



            CLogServiceController controller;




        public:

            CLogService(); 



            virtual ~CLogService(); 



            virtual void SetName(U64 name); 



            virtual U64 GetName(); 



            virtual void SetType(U32 type); 



            virtual U32 GetType(); 



            virtual const char * ToString(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            bool Initiate(); 



            bool Shutdown(); 



            void Attach(U08 display_level, IInterface * output); 



            void Record(U08 level, const char * log); 



    };  //end class CLogService



} //end namespace atom



#endif
