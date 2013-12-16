#ifndef CTCPCONNECTOR_H
#define CTCPCONNECTOR_H
//Begin section for file CTcpConnector.h
//TODO: Add definitions that you want preserved
//End section for file CTcpConnector.h
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



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CTcpConnector : public CReferencedObject
	{

		//Begin section for atom::CTcpConnector
		//TODO: Add attributes that you want preserved
		//End section for atom::CTcpConnector

		private:



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpConnectorController controller;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CImportStream import_stream;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CExportStream export_stream;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpConnectorEventEmitter emitter;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpConnectorFlushDevice flush;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpConnectorLife life;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpConnector(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CTcpConnector(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual const char * ToString(); 

	
	
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CTcpConnector



} //end namespace atom



#endif
