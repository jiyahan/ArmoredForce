#ifndef CTCPKQUEUEMODEL_H
#define CTCPKQUEUEMODEL_H
//Begin section for file CTcpKQueueModel.h
//TODO: Add definitions that you want preserved
//End section for file CTcpKQueueModel.h
#include "../../pattern/object/CReferencedObject.h"
#include "../../pattern/container/CInstanceContainer.h"
#include "../../pattern/container/CInstanceContainerListener.h"
#include "CTcpKQueueModelThreads.h"
#include "CTcpKQueueModelAliasContainer.h"
#include "CTcpKQueueModelLife.h"
#include "CTcpKQueueIOModelImplement.h"
#include "../../interface/IInterface.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CTcpKQueueModel : public CReferencedObject
	{

		//Begin section for atom::CTcpKQueueModel
		//TODO: Add attributes that you want preserved
		//End section for atom::CTcpKQueueModel

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceContainer container;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceContainerListener listener;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpKQueueModelThreads threads;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpKQueueModelAliasContainer alias;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpKQueueModelLife life;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpKQueueIOModelImplement implement;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpKQueueModel(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CTcpKQueueModel(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual const char * ToString(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CTcpKQueueModel



} //end namespace atom



#endif
