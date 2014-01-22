#ifndef CELECTRONALLOCATOR_H
#define CELECTRONALLOCATOR_H
#include "../Common.h"
#include "CElectronAllocatorSingletonBind.h"
#include "CElectronInstanceAllocator.h"



namespace electron
{



    class CElectronAllocator : public IReferencedObject, public CElectronAllocatorSingletonBind
    {


        private:


            CElectronInstanceAllocator allocator;



            CReference counter;




        public:

            CElectronAllocator(); 



            virtual ~CElectronAllocator(); 



            virtual void SetName(U64 name); 



            virtual U64 GetName(); 



            virtual void SetType(U32 type); 



            virtual U32 GetType(); 



            virtual const char * ToString(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



    };  //end class CElectronAllocator



} //end namespace electron



#endif
