#ifndef CTCPLISTENER_H
#define CTCPLISTENER_H
#include "../../pattern/object/CReferencedObject.h"
#include "../thread/CReference.h"
#include "CTcpListenerController.h"
#include "CTcpListenerLife.h"
#include "../../pattern/event/CEventDirectEmitter.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CTcpListener : public CReferencedObject
	{


		private:


			CTcpListenerController controller;



			CTcpListenerLife life;



			CEventDirectEmitter emitter;




		public:

			CTcpListener(); 



			virtual ~CTcpListener(); 



			virtual const char * ToString(); 




			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CTcpListener



} //end namespace atom



#endif
