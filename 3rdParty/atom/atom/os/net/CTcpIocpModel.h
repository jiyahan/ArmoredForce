#ifndef CTCPIOCPMODEL_H
#define CTCPIOCPMODEL_H
#include "../../pattern/object/CReferencedObject.h"
#include "../../pattern/container/CInstanceContainerListener.h"
#include "../../pattern/container/CInstanceContainer.h"
#include "CTcpIocpModelLife.h"
#include "CTcpIocpIOModelImplement.h"
#include "CTcpIocpModelAliasContainer.h"
#include "CTcpIocpModelThreads.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CTcpIocpModel : public CReferencedObject
	{


		private:


			CInstanceContainerListener listener;



			CInstanceContainer container;



			CTcpIocpModelLife life;



			CTcpIocpIOModelImplement implement;



			CTcpIocpModelAliasContainer alias;



			CTcpIocpModelThreads threads;




		public:

			CTcpIocpModel(); 



			~CTcpIocpModel(); 



			virtual const char * ToString(); 



			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CTcpIocpModel



} //end namespace atom



#endif
