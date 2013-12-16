#ifndef IEVENTSERVICEENTRY_H
#define IEVENTSERVICEENTRY_H
//Begin section for file IEventServiceEntry.h
//TODO: Add definitions that you want preserved
//End section for file IEventServiceEntry.h
#include "IEmbedInterface.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IEventServiceEntry : public IEmbedInterface
	{

		//Begin section for atom::IEventServiceEntry
		//TODO: Add attributes that you want preserved
		//End section for atom::IEventServiceEntry



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U64 Create() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Remove(U64 space) = 0; 



	};  //end class IEventServiceEntry



} //end namespace atom



#endif
