#ifndef ITCPCONNECTIONCONTROLLER_H
#define ITCPCONNECTIONCONTROLLER_H
//Begin section for file ITcpConnectionController.h
//TODO: Add definitions that you want preserved
//End section for file ITcpConnectionController.h
#include "IEmbedInterface.h"
#include "../utility/stl/a_string.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class ITcpConnectionController : public IEmbedInterface
	{

		//Begin section for atom::ITcpConnectionController
		//TODO: Add attributes that you want preserved
		//End section for atom::ITcpConnectionController



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Open(const char * address, U16 port, U32 io_model) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Shut() = 0; 



			//<p>Is connection active ?</p>
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool GetActive() = 0; 



			//<p>Get connection's socket</p>
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual SOCKET GetSocket() = 0; 



			//<p>Get connection's IO model's name</p>
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U32 GetIOMold() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual a_string GetSelfAddress() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U16 GetSelfPort() = 0; 



	};  //end class ITcpConnectionController



} //end namespace atom



#endif
