#ifndef IINSTANCEFACTORYENTRY_H
#define IINSTANCEFACTORYENTRY_H
//Begin section for file IInstanceFactoryEntry.h
//TODO: Add definitions that you want preserved
//End section for file IInstanceFactoryEntry.h
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IInstanceFactoryEntry : public IEmbedInterface
	{

		//Begin section for atom::IInstanceFactoryEntry
		//TODO: Add attributes that you want preserved
		//End section for atom::IInstanceFactoryEntry



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U64 Product(U32 type) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual CObjectPtr Inquire(U64 instance) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Destroy(U64 instance) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Recycle() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Initiate() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Shutdown() = 0; 



	};  //end class IInstanceFactoryEntry



} //end namespace atom



#endif
