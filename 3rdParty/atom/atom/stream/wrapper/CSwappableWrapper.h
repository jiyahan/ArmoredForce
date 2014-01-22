#ifndef CSWAPPABLEWRAPPER_H
#define CSWAPPABLEWRAPPER_H
#include "../../interface/ISwappable.h"
#include "../../interface/IInterface.h"
#include "../../os/memory/CMemory.h"



namespace atom
{



    class CSwappableWrapper : public ISwappable
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
            IInterface * bind;



            U32 wrap;




        public:

            CSwappableWrapper(); 



            virtual ~CSwappableWrapper(); 



            void SetTarget(U32 iid); 



            void Attach(IInterface * nest); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool Swap(CMemory & data); 



    };  //end class CSwappableWrapper


}//end namespace atom


#endif
