#ifndef CELECTRONINSTANCEALLOCATOR_H
#define CELECTRONINSTANCEALLOCATOR_H
#include "../Common.h"



namespace electron
{



    class CElectronInstanceAllocator : public IInstanceAllocator
    {


        private:


            IInterface * nest;




        public:

            CElectronInstanceAllocator(); 



            virtual ~CElectronInstanceAllocator(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual CReferencedObject * Product(U32 type); 



            virtual void Destroy(CReferencedObject * value); 



            virtual void Confine(U32 & lower, U32 & upper); 



    };  //end class CElectronInstanceAllocator



} //end namespace electron



#endif
