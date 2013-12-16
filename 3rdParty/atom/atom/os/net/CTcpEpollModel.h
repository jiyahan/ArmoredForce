#ifndef CTCPEPOLLMODEL_H
#define CTCPEPOLLMODEL_H
//Begin section for file CTcpEpollModel.h
//TODO: Add definitions that you want preserved
//End section for file CTcpEpollModel.h
#include "../../pattern/object/CReferencedObject.h"
#include "../../pattern/container/CInstanceContainerListener.h"
#include "../../pattern/container/CInstanceContainer.h"
#include "CTcpEpollModelLife.h"
#include "CTcpEpollModelThreads.h"
#include "CTcpEpollIOModelImplement.h"
#include "../../interface/IInterface.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CTcpEpollModel : public CReferencedObject
	{

		//Begin section for atom::CTcpEpollModel
		//TODO: Add attributes that you want preserved
		//End section for atom::CTcpEpollModel

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceContainerListener listener;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceContainer container;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpEpollModelLife life;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpEpollModelThreads threads;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpEpollIOModelImplement implement;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpEpollModel(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CTcpEpollModel(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual const char * ToString(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CTcpEpollModel



} //end namespace atom



#endif
