#ifndef IEVENTRECEIVER_H
#define IEVENTRECEIVER_H
//Begin section for file IEventReceiver.h
//TODO: Add definitions that you want preserved
//End section for file IEventReceiver.h
#include "IEmbedInterface.h"
#include "../pattern/event/tagEvent.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IEventReceiver : public IEmbedInterface
	{

		//Begin section for atom::IEventReceiver
		//TODO: Add attributes that you want preserved
		//End section for atom::IEventReceiver



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool OnEvent(const tagEvent & event) = 0; 



	};  //end class IEventReceiver


} //end namespace atom



#endif
