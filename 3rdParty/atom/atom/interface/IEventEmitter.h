#ifndef IEVENTEMITTER_H
#define IEVENTEMITTER_H
//Begin section for file IEventEmitter.h
//TODO: Add definitions that you want preserved
//End section for file IEventEmitter.h
#include "IEmbedInterface.h"
#include "../pattern/event/tagEvent.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IEventEmitter : public IEmbedInterface
	{

		//Begin section for atom::IEventEmitter
		//TODO: Add attributes that you want preserved
		//End section for atom::IEventEmitter



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Attach(U64 space) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Attach(CObjectPtr & space) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Detach() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Report(const tagEvent & event) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Report(const char * target, const tagEvent & event) = 0; 



	};  //end class IEventEmitter



} //end namespace atom



#endif
