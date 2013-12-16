#ifndef CINSTANCEFACTORYALLOCATOR_H
#define CINSTANCEFACTORYALLOCATOR_H
//Begin section for file CInstanceFactoryAllocator.h
//TODO: Add definitions that you want preserved
//End section for file CInstanceFactoryAllocator.h
#include "../../interface/IInstanceFactoryAllocator.h"
#include "../../interface/IInterface.h"
#include "tagAllocator.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../../interface/IReferencedObject.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CInstanceFactoryAllocator : public IInstanceFactoryAllocator
	{

		//Begin section for atom::CInstanceFactoryAllocator
		//TODO: Add attributes that you want preserved
		//End section for atom::CInstanceFactoryAllocator

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IInterface * nest;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagAllocator list[ALLOCATOR_TOTAL];



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceFactoryAllocator(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CInstanceFactoryAllocator(); 



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
			virtual bool Attach(CObjectPtr & allocator); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Detach(CObjectPtr & allocator); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual CReferencedObject * Product(U32 type); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Destroy(CReferencedObject * value); 



	};  //end class CInstanceFactoryAllocator



} //end namespace atom



#endif
