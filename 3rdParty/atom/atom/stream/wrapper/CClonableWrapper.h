#ifndef CCLONABLEWRAPPER_H
#define CCLONABLEWRAPPER_H
#include "../../interface/IClonable.h"
#include "../../interface/IInterface.h"
#include "../../interface/IExportStream.h"
#include "../../interface/IStream.h"
#include "../../os/memory/CMemory.h"
#include "tagWrapper.h"



namespace atom
{



    class CClonableWrapper : public IClonable
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

            CClonableWrapper(); 



            virtual ~CClonableWrapper(); 



            void Verify(); 



            void Attach(IInterface * stream); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool Clone(CMemory & data); 



    };  //end class CClonableWrapper


}//end namespace atom


#endif
