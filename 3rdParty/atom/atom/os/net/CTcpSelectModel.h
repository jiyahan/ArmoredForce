#ifndef CTCPSELECTMODEL_H
#define CTCPSELECTMODEL_H
#include "../../pattern/object/CReferencedObject.h"
#include "../thread/CReference.h"
#include "CTcpSelectModelImplement.h"
#include "CTcpSelectModelThread.h"
#include "CTcpSelectModelLife.h"
#include "../../pattern/container/CInstanceContainer.h"
#include "../../pattern/container/CInstanceContainerListener.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CTcpSelectModel : public CReferencedObject
	{


		private:


			CTcpSelectModelImplement model;



			CTcpSelectModelThread thread;



			CTcpSelectModelLife life;



			CInstanceContainer container;



			CInstanceContainerListener listener;




		public:

			CTcpSelectModel(); 



			virtual ~CTcpSelectModel(); 



			virtual const char * ToString(); 



			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CTcpSelectModel



} //end namespace atom



#endif
