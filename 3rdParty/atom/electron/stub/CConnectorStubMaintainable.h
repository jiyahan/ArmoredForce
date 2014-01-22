#ifndef CCONNECTORSTUBMAINTAINABLE_H
#define CCONNECTORSTUBMAINTAINABLE_H
#include "../Common.h"



namespace electron
{



    class CConnectorStubMaintainable : public IMaintainable
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif




        public:

            CConnectorStubMaintainable(); 



            virtual ~CConnectorStubMaintainable(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual U64 OnMaintenance(U64 now); 



    };  //end class CConnectorStubMaintainable



} //end namespace electron



#endif
