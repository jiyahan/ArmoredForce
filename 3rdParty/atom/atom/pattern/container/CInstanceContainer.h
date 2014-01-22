#ifndef CINSTANCECONTAINER_H
#define CINSTANCECONTAINER_H
#include "CInstanceContainable.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/IInterface.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../../utility/stl/CU64Array.h"



namespace atom
{


    
    class CInstanceContainer : public IInstanceContainer
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
            CInstanceContainable instances[CONTAINER_QUEUE];



            void OnInsertInstance(CObjectPtr & instance); 



            void OnRemoveInstance(CObjectPtr & instance); 




        public:

            CInstanceContainer(); 



            virtual ~CInstanceContainer(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool Insert(CObjectPtr & instance); 



            virtual CObjectPtr Obtain(U64 instance_name); 



            virtual void Obtain(CU64Array & instances); 



            virtual bool Inside(U64 instance_name); 



            virtual U64 Amount(); 



            virtual bool Remove(U64 instance_name); 



            virtual void RemoveAll(); 



    };  //end class CInstanceContainer



} //end namespace atom



#endif
