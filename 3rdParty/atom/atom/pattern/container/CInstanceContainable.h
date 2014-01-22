#ifndef CINSTANCECONTAINABLE_H
#define CINSTANCECONTAINABLE_H
#include "CInstanceContainableBind.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../../utility/stl/CU64Array.h"



namespace atom
{
    


    class CInstanceContainable
    {


        private:


            CCriticalSection clog;



            CInstanceContainableBind instances;




        public:

            CInstanceContainable(); 



            ~CInstanceContainable(); 



            bool Insert(CObjectPtr & instance); 



            CObjectPtr Obtain(U64 instance_name); 



            void Obtain(CU64Array & instances); 



            bool Inside(U64 instance_name); 



            U64 Amount(); 



            bool Remove(U64 instance_name); 



            void RemoveAll(); 



    };  //end class CInstanceContainable



} //end namespace atom



#endif
