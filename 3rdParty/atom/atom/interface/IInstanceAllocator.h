#ifndef IINSTANCEALLOCATOR_H
#define IINSTANCEALLOCATOR_H
//Begin section for file IInstanceAllocator.h
//TODO: Add definitions that you want preserved
//End section for file IInstanceAllocator.h
#include "IEmbedInterface.h"
#include "../pattern/object/CReferencedObject.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IInstanceAllocator : public IEmbedInterface
	{

		//Begin section for atom::IInstanceAllocator
		//TODO: Add attributes that you want preserved
		//End section for atom::IInstanceAllocator



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual CReferencedObject * Product(U32 type) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Destroy(CReferencedObject * value) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Confine(U32 & lower, U32 & upper) = 0; 



	};  //end class IInstanceAllocator



} //end namespace atom



#endif
