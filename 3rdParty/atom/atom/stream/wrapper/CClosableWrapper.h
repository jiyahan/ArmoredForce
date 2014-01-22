#ifndef CCLOSABLEWRAPPER_H
#define CCLOSABLEWRAPPER_H
#include "../../interface/IClosable.h"
#include "../../interface/IInterface.h"



namespace atom
{



    class CClosableWrapper : public IClosable
    {

        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
            IInterface * bind;



            U32 wrap[3];



            U08 size;




        public:

            CClosableWrapper(); 



            virtual ~CClosableWrapper(); 



            void Verify(); 



            void Attach(IInterface * stream); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual void Close(); 



    };  //end class CClosableWrapper


}//end namespace atom


#endif
