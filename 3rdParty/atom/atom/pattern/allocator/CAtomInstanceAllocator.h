#ifndef CATOMINSTANCEALLOCATOR_H
#define CATOMINSTANCEALLOCATOR_H
//Begin section for file CAtomInstanceAllocator.h
//TODO: Add definitions that you want preserved
//End section for file CAtomInstanceAllocator.h
#include "../../interface/IInstanceAllocator.h"
#include "../../interface/IInterface.h"
#include "../../interface/IReferencedObject.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CAtomInstanceAllocator : public IInstanceAllocator
	{

		//Begin section for atom::CAtomInstanceAllocator
		//TODO: Add attributes that you want preserved
		//End section for atom::CAtomInstanceAllocator

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IInterface * nest;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CAtomInstanceAllocator(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CAtomInstanceAllocator(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int IncRef(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int DecRef(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int GetRef(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual IInterface * QueryInterface(U32 iid); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void SetNest(IInterface * nest); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual CReferencedObject * Product(U32 type); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Destroy(CReferencedObject * value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Confine(U32 & lower, U32 & upper); 



	};  //end class CAtomInstanceAllocator



} //end namespace atom



#endif
