#ifndef CASSIGNABLEWRAPPER_H
#define CASSIGNABLEWRAPPER_H
#include "../../interface/IAssignable.h"
#include "../../interface/IInterface.h"
#include "../../interface/IImportStream.h"
#include "../../interface/IStream.h"
#include "../../os/memory/CMemory.h"
#include "tagWrapper.h"




namespace atom
{



    class CAssignableWrapper : public IAssignable
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
            IInterface * bind;



			tagWrapper port;



            U32 wrap;




        public:

            CAssignableWrapper(); 



            virtual ~CAssignableWrapper(); 



            void Verify(); 



            void Attach(IInterface * stream); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool Assign(CMemory & data); 



    };  //end class CAssignableWrapper


}//end namespace atom


#endif
