#ifndef CTCPEPOLLMODEL_H
#define CTCPEPOLLMODEL_H
#include "../../pattern/object/CReferencedObject.h"
#include "../../pattern/container/CInstanceContainerListener.h"
#include "../../pattern/container/CInstanceContainer.h"
#include "CTcpEpollModelLife.h"
#include "CTcpEpollModelThreads.h"
#include "CTcpEpollIOModelImplement.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CTcpEpollModel : public CReferencedObject
	{


		private:


			CInstanceContainerListener listener;



			CInstanceContainer container;



			CTcpEpollModelLife life;



			CTcpEpollModelThreads threads;



			CTcpEpollIOModelImplement implement;




		public:

			CTcpEpollModel(); 



			virtual ~CTcpEpollModel(); 



			virtual const char * ToString(); 



			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CTcpEpollModel



} //end namespace atom



#endif
