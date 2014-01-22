#ifndef CTCPKQUEUEMODEL_H
#define CTCPKQUEUEMODEL_H
#include "../../pattern/object/CReferencedObject.h"
#include "../../pattern/container/CInstanceContainer.h"
#include "../../pattern/container/CInstanceContainerListener.h"
#include "CTcpKQueueModelThreads.h"
#include "CTcpKQueueModelAliasContainer.h"
#include "CTcpKQueueModelLife.h"
#include "CTcpKQueueIOModelImplement.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CTcpKQueueModel : public CReferencedObject
	{


		private:


			CInstanceContainer container;



			CInstanceContainerListener listener;



			CTcpKQueueModelThreads threads;



			CTcpKQueueModelAliasContainer alias;



			CTcpKQueueModelLife life;



			CTcpKQueueIOModelImplement implement;




		public:

			CTcpKQueueModel(); 



			virtual ~CTcpKQueueModel(); 



			virtual const char * ToString(); 



			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CTcpKQueueModel



} //end namespace atom



#endif
