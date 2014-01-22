#ifndef CFLUSHABLEWRAPPER_H
#define CFLUSHABLEWRAPPER_H
#include "../../interface/IFlushable.h"
#include "../../interface/IInterface.h"
#include "../../interface/IExportStream.h"
#include "../../interface/IStream.h"
#include "tagWrapper.h"



namespace atom
{



    class CFlushableWrapper : public IFlushable
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

            CFlushableWrapper(); 



            virtual ~CFlushableWrapper(); 



            void Verify(); 



            void Attach(IInterface * nest); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual void Flush(); 



    };  //end class CFlushableWrapper


}//end namespace atom


#endif
