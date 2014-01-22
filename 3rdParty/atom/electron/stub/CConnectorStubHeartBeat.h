#ifndef CCONNECTORSTUBHEARTBEAT_H
#define CCONNECTORSTUBHEARTBEAT_H
#include "../Common.h"
#include "../interface/IConnectorStubHeartBeat.h"
#include "../message/CMessage.h"



namespace electron
{
    


    class CConnectorStubHeartBeat : public IConnectorStubHeartBeat
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
            U32 count;



            bool doing;



            CMilisecondTimer timer;




        public:

            CConnectorStubHeartBeat(); 



            virtual ~CConnectorStubHeartBeat(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual void OnMessage(CMessage * message); 



            virtual U64 OnProcess(U64 now); 



            virtual void Reset(); 



    };  //end class CConnectorStubHeartBeat



} //end namespace atom



#endif
