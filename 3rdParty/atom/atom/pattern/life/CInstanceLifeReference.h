#ifndef CINSTANCELIFEREFERENCE_H
#define CINSTANCELIFEREFERENCE_H
#include "../../interface/IInstanceLifeReference.h"
#include "../../interface/IInterface.h"
#include "CInstanceLifeWakeReferenceX.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../../utility/stl/CU64Array.h"



namespace atom
{



    class CInstanceLifeReference : public IInstanceLifeReference
    {


        private:


            IInterface * nest;



            CInstanceLifeWakeReferenceX references;



            CObjectPtr receiver;




        public:

            CInstanceLifeReference(); 



            virtual ~CInstanceLifeReference(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool Insert(U64 instance); 



            virtual bool Remove(U64 instance); 



            virtual int Increase(U64 instance); 



            virtual int Decrease(U64 instance); 



            virtual int GetReference(U64 instance); 



            virtual void GetInstances(CU64Array & instances); 



            virtual void SetReceiver(CObjectPtr & value); 



            virtual CObjectPtr GetReceiver(); 



			virtual bool Initiate();



			virtual bool Shutdown();



	};  //end class CInstanceLifeReference



} //end namespace atom



#endif
