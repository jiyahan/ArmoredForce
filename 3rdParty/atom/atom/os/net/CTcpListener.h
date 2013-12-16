#ifndef CTCPLISTENER_H
#define CTCPLISTENER_H
//Begin section for file CTcpListener.h
//TODO: Add definitions that you want preserved
//End section for file CTcpListener.h
#include "../../pattern/object/CReferencedObject.h"
#include "../thread/CReference.h"
#include "CTcpListenerController.h"
#include "CTcpListenerLife.h"
#include "../../pattern/event/CEventDirectEmitter.h"
#include "../../interface/IInterface.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CTcpListener : public CReferencedObject
	{

		//Begin section for atom::CTcpListener
		//TODO: Add attributes that you want preserved
		//End section for atom::CTcpListener

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpListenerController controller;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpListenerLife life;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CEventDirectEmitter emitter;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpListener(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CTcpListener(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual const char * ToString(); 




			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CTcpListener



} //end namespace atom



#endif
