#ifndef CINSTANCEFACTORYMAINTAINER_H
#define CINSTANCEFACTORYMAINTAINER_H
//Begin section for file CInstanceFactoryMaintainer.h
//TODO: Add definitions that you want preserved
//End section for file CInstanceFactoryMaintainer.h
#include "../../interface/IMaintainable.h"
#include "../../interface/IInterface.h"



namespace atom
{	



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CInstanceFactoryMaintainer : public IMaintainable
	{

		//Begin section for atom::CInstanceFactoryMaintainer
		//TODO: Add attributes that you want preserved
		//End section for atom::CInstanceFactoryMaintainer

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IInterface * nest;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceFactoryMaintainer(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CInstanceFactoryMaintainer(); 



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
			virtual U64 OnMaintenance(U64 now); 



	};  //end class CInstanceFactoryMaintainer



} //end namespace atom



#endif
