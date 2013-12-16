#ifndef CATOMALLOCATOR_H
#define CATOMALLOCATOR_H
//Begin section for file CAtomAllocator.h
//TODO: Add definitions that you want preserved
//End section for file CAtomAllocator.h
#include "CAtomAllocatorSingletonBind.h"
#include "CAtomInstanceAllocator.h"
#include "../../interface/IReferencedObject.h"
#include "../../os/thread/CReference.h"
#include "../../interface/IInterface.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CAtomAllocator : public IReferencedObject, public CAtomAllocatorSingletonBind
	{

		//Begin section for atom::CAtomAllocator
		//TODO: Add attributes that you want preserved
		//End section for atom::CAtomAllocator

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CAtomInstanceAllocator allocator;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CReference counter;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CAtomAllocator(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CAtomAllocator(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void SetName(U64 name); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U64 GetName(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void SetType(U32 type); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U32 GetType(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual const char * ToString(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int IncRef(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int DecRef(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int GetRef(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CAtomAllocator



} //end namespace atom



#endif
