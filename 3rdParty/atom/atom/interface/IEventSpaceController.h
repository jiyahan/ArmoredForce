#ifndef IEVENTSPACECONTROLLER_H
#define IEVENTSPACECONTROLLER_H
//Begin section for file IEventSpaceController.h
//TODO: Add definitions that you want preserved
//End section for file IEventSpaceController.h
#include "IEventReceiver.h"
#include "../utility/tool/CObjectPtr.h"
#include "../pattern/event/tagEvent.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IEventSpaceController : public IEventReceiver
	{

		//Begin section for atom::IEventSpaceController
		//TODO: Add attributes that you want preserved
		//End section for atom::IEventSpaceController



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Initiate() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Shutdown() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Attach(CObjectPtr & receiver, const char * name = NULL) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Detach(U64 receiver) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void OnProcess() = 0; 



	};  //end class IEventSpaceController



} //end namespace atom



#endif
