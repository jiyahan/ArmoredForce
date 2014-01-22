#ifndef CCONNECTORSTUBFRAME_H
#define CCONNECTORSTUBFRAME_H
#include "../interface/IConnectorStubFrame.h"
#include "../message/CMessage.h"
#include "tagFrame.h"



namespace electron
{



    class CConnectorStubFrame : public IConnectorStubFrame
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
			//<p>Current frame's length</p>
            U64 length;



            //<p>Largest frame length record</p>
            U64 record;



            //<p>last receive data time</p>
            U64 lasted;



            //<p>connector's instance name</p>
            U64 entity;



            CReference locker;



            //<p>Connector's stream reader</p>
            CDataReader reader;



            //<p>Connector's stream writer</p>
            CDataWriter writer;



            //<p>Connector's instance</p>
            CObjectPtr object;



            //<p>Message queue's object pointer</p>
            CObjectPtr queues;



            tagFrame::CFrameArray frames;



            CCriticalSection stream_region;



            CCriticalSection import_region;



            CCriticalSection export_region;



            CCriticalSection frames_region;



            void OnSendFrame(); 



            bool PreReadFrame(tagFrame & frame); 



            bool PreSendFrame(tagFrame & frame); 




        public:

            CConnectorStubFrame(); 



            virtual ~CConnectorStubFrame(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool Open(U64 connector, U64 msg_queue); 



            virtual bool Shut(); 



            virtual bool Read(U64 time); 



            virtual bool Send(CMessage * msg); 



            virtual U64 LastReceive(); 



    };  //end class CConnectorStubFrame



} //end namespace atom



#endif
