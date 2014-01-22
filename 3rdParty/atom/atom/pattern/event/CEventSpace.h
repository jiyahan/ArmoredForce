#ifndef CEVENTSPACE_H
#define CEVENTSPACE_H
#include "CEventSpaceController.h"
#include "CEventSpaceLife.h"
#include "../object/CReferencedObject.h"
#include "../container/CInstanceContainer.h"
#include "../container/CInstanceContainerListener.h"
#include "../../os/thread/CReference.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CEventSpace : public CReferencedObject
	{


		private:


			CEventSpaceController controller;



			CInstanceContainer container;



			CInstanceContainerListener listener;



			CEventSpaceLife life;


			
		public:

			CEventSpace(); 



			virtual ~CEventSpace(); 



			virtual const char * ToString(); 



			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CEventSpace



} //end namespace atom



#endif
