#ifndef CINSTANCELIFEWAKEREFERENCEX_H
#define CINSTANCELIFEWAKEREFERENCEX_H
#include "CInstanceLifeWakeReference.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../../utility/stl/CU64Array.h"




namespace atom
{



    
    class CInstanceLifeWakeReferenceX
    {


        private:


            CInstanceLifeWakeReference instances[INSTANCES_QUEUE];




        public:

            CInstanceLifeWakeReferenceX(); 



            virtual ~CInstanceLifeWakeReferenceX(); 



            bool Insert(U64 instance, CObjectPtr & receiver); 



            bool Remove(U64 instance, CObjectPtr & receiver); 



            int Increase(U64 instance); 



            int Decrease(U64 instance); 



            void Clear(CObjectPtr & receiver); 



            int GetReference(U64 instance); 



            void GetInstances(CU64Array & instances); 



    };  //end class CInstanceLifeWakeReferenceX



} //end namespace atom



#endif
