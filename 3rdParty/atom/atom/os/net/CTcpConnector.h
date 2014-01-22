#ifndef CTCPCONNECTOR_H
#define CTCPCONNECTOR_H
#include "../../pattern/object/CReferencedObject.h"
#include "../thread/CReference.h"
#include "CTcpConnectorController.h"
#include "CTcpConnectorEventEmitter.h"
#include "../../stream/memory/CImportStream.h"
#include "../../stream/memory/CExportStream.h"
#include "CTcpConnectorFlushDevice.h"
#include "CTcpConnectorLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CTcpConnector : public CReferencedObject
	{


		private:



			CTcpConnectorController controller;



			CImportStream import_stream;



			CExportStream export_stream;



			CTcpConnectorEventEmitter emitter;



			CTcpConnectorFlushDevice flush;



			CTcpConnectorLife life;




		public:

			CTcpConnector(); 



			virtual ~CTcpConnector(); 



			virtual const char * ToString(); 

	
	
			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CTcpConnector



} //end namespace atom



#endif
