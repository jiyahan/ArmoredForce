#ifndef IINSTANCEFACTORYALLOCATOR_H
#define IINSTANCEFACTORYALLOCATOR_H
//Begin section for file IInstanceFactoryAllocator.h
//TODO: Add definitions that you want preserved
//End section for file IInstanceFactoryAllocator.h
#include "IEmbedInterface.h"
#include "../pattern/object/CReferencedObject.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IInstanceFactoryAllocator : public IEmbedInterface
	{

		//Begin section for atom::IInstanceFactoryAllocator
		//TODO: Add attributes that you want preserved
		//End section for atom::IInstanceFactoryAllocator



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Attach(CObjectPtr & allocator) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Detach(CObjectPtr & allocator) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual CReferencedObject * Product(U32 type) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Destroy(CReferencedObject * value) = 0; 



	};  //end class IInstanceFactoryAllocator



} //end namespace atom



#endif
