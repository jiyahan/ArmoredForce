#ifndef CTCPSELECTMODEL_H
#define CTCPSELECTMODEL_H
//Begin section for file CTcpSelectModel.h
//TODO: Add definitions that you want preserved
//End section for file CTcpSelectModel.h
#include "../../pattern/object/CReferencedObject.h"
#include "../thread/CReference.h"
#include "CTcpSelectModelImplement.h"
#include "CTcpSelectModelThread.h"
#include "CTcpSelectModelLife.h"
#include "../../pattern/container/CInstanceContainer.h"
#include "../../pattern/container/CInstanceContainerListener.h"
#include "../../interface/IInterface.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CTcpSelectModel : public CReferencedObject
	{

		//Begin section for atom::CTcpSelectModel
		//TODO: Add attributes that you want preserved
		//End section for atom::CTcpSelectModel

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpSelectModelImplement model;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpSelectModelThread thread;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpSelectModelLife life;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceContainer container;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceContainerListener listener;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpSelectModel(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CTcpSelectModel(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual const char * ToString(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CTcpSelectModel



} //end namespace atom



#endif
