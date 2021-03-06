#ifndef CTCPCONNECTOREVENTEMITTER_H
#define CTCPCONNECTOREVENTEMITTER_H
#include "../../interface/IEventEmitter.h"
#include "../../interface/IInterface.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../thread/CCriticalSection.h"
#include "../../pattern/event/tagEvent.h"



namespace atom
{



	class CTcpConnectorEventEmitter : public IEventEmitter
	{


		private:


			IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif



			CObjectPtr node;



			CCriticalSection section;




		public:

			CTcpConnectorEventEmitter(); 



			virtual ~CTcpConnectorEventEmitter(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Attach(U64 object); 



			virtual bool Attach(CObjectPtr & space); 



			virtual void Detach(); 



			virtual bool Report(const tagEvent & event); 



			virtual bool Report(const char * target, const tagEvent & event); 



	};  //end class CTcpConnectorEventEmitter



} //end namespace atom



#endif
