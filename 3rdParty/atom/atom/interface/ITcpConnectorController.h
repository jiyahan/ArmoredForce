#ifndef ITCPCONNECTORCONTROLLER_H
#define ITCPCONNECTORCONTROLLER_H
//Begin section for file ITcpConnectorController.h
//TODO: Add definitions that you want preserved
//End section for file ITcpConnectorController.h
#include "ITcpConnectionController.h"
#include "../utility/stl/a_string.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class ITcpConnectorController : public ITcpConnectionController
	{

		//Begin section for atom::ITcpConnectorController
		//TODO: Add attributes that you want preserved
		//End section for atom::ITcpConnectorController



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Open(SOCKET socket, U32 io_model) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual a_string GetPeerAddress() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U16 GetPeerPort() = 0; 



	};  //end class ITcpConnectorController



} //end namespace atom



#endif
