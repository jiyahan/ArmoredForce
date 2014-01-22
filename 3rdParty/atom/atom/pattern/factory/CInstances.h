#ifndef CINSTANCES_H
#define CINSTANCES_H
#include "CInstancesBind.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../utility/stl/CU64Array.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



    class CInstances
    {


        private:


            CInstancesBind instances;



            CCriticalSection section;




        public:

            CInstances(); 



            virtual ~CInstances(); 



            bool Insert(CReferencedObject * instance); 



            bool Inside(U64 name); 



            CObjectPtr Obtain(U64 name); 



            void Obtain(CU64Array & indices); 



            U64 Amount(); 



            CReferencedObject * Remove(U64 name, bool & exist, bool force=false); 



    };  //end class CInstances



} //end namespace atom



#endif
