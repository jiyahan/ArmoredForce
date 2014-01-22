#ifndef CCONNECTORSTUBSTATISTICS_H
#define CCONNECTORSTUBSTATISTICS_H
#include "../Common.h"
#include "../interface/IConnectorStubStatistics.h"
#include "tagFlowStatistics.h"



namespace electron
{



    class CConnectorStubStatistics : public IConnectorStubStatistics
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
            U64 large;



            tagFlowStatistics plain;



            tagFlowStatistics final;



            CCriticalSection section;




        public:

            CConnectorStubStatistics(); 



            virtual ~CConnectorStubStatistics(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual void OnReadFrame(U64 origin, U64 reduce); 



            virtual void OnSendFrame(U64 origin, U64 reduce); 



            virtual void OnLongFrame(U64 value); 



            virtual void GetStatistics(U64 & largest, tagFlowStatistics & plain, tagFlowStatistics & final); 



            virtual void Reset(); 



    };  //end class CConnectorStubStatistics



} //end namespace electron



#endif
