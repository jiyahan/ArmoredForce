#ifndef CEVENTSPACE_H
#define CEVENTSPACE_H
//Begin section for file CEventSpace.h
//TODO: Add definitions that you want preserved
//End section for file CEventSpace.h
#include "CEventSpaceController.h"
#include "CEventSpaceLife.h"
#include "../object/CReferencedObject.h"
#include "../container/CInstanceContainer.h"
#include "../container/CInstanceContainerListener.h"
#include "../../os/thread/CReference.h"
#include "../../interface/IInterface.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CEventSpace : public CReferencedObject
	{

		//Begin section for atom::CEventSpace
		//TODO: Add attributes that you want preserved
		//End section for atom::CEventSpace

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CEventSpaceController controller;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceContainer container;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceContainerListener listener;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CEventSpaceLife life;


			
		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CEventSpace(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CEventSpace(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual const char * ToString(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CEventSpace



} //end namespace atom



#endif
