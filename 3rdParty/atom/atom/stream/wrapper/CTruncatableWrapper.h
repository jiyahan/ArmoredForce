#ifndef CTRUNCATABLEWRAPPER_H
#define CTRUNCATABLEWRAPPER_H
#include "../../interface/ITruncatable.h"
#include "../../interface/IInterface.h"
#include "../../interface/IImportStream.h"
#include "../../interface/IStream.h"
#include "tagWrapper.h"



namespace atom
{



    class CTruncatableWrapper : public ITruncatable
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

            CTruncatableWrapper(); 



            virtual ~CTruncatableWrapper(); 



            void Verify(); 



            void Attach(IInterface * nest); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual void Truncate(); 



    };  //end class CTruncatableWrapper


}//end namespace atom


#endif
