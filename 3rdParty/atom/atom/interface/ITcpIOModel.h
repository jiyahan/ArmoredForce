#ifndef ITCPIOMODEL_H
#define ITCPIOMODEL_H
//Begin section for file ITcpIOModel.h
//TODO: Add definitions that you want preserved
//End section for file ITcpIOModel.h
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"
#include "../os/net/tagDomain.h"
#include "../os/memory/CMemory.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class ITcpIOModel : public IEmbedInterface
	{

		//Begin section for atom::ITcpIOModel
		//TODO: Add attributes that you want preserved
		//End section for atom::ITcpIOModel



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual SOCKET Create() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Remove(SOCKET socket) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Attach(U64 name) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Detach(U64 name) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual CObjectPtr Obtain(U64 name) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Initiate() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Shutdown() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Listen(U64 listener, const tagDomain & domain) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Connect(U64 connector, const tagDomain & domain) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Send(U64 connector, CMemory & data, size_t offset, size_t length) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Receive(U64 connector) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Accept(U64 listener) = 0; 



	};  //end class ITcpIOModel



} //end namespace atom



#endif
