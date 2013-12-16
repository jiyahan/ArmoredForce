#ifndef CTCPIOCPMODEL_H
#define CTCPIOCPMODEL_H
//Begin section for file CTcpIocpModel.h
//TODO: Add definitions that you want preserved
//End section for file CTcpIocpModel.h
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



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CTcpIocpModel : public CReferencedObject
	{

		//Begin section for atom::CTcpIocpModel
		//TODO: Add attributes that you want preserved
		//End section for atom::CTcpIocpModel

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceContainerListener listener;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceContainer container;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpIocpModelLife life;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpIocpIOModelImplement implement;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpIocpModelAliasContainer alias;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpIocpModelThreads threads;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpIocpModel(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			~CTcpIocpModel(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual const char * ToString(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CTcpIocpModel



} //end namespace atom



#endif
