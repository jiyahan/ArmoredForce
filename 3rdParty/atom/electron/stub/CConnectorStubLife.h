#ifndef CCONNECTORSTUBLIFE_H
#define CCONNECTORSTUBLIFE_H
#include "../Common.h"



namespace electron
{



    class CConnectorStubLife : public IInstanceLife
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif




        public:

            CConnectorStubLife(); 



            virtual ~CConnectorStubLife(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool Initiate(); 



            virtual bool Shutdown(); 



    };  //end class CConnectorStubLife



} //end namespace electron



#endif
