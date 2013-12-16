#ifndef CINSTANCELIFEMAINTAINER_H
#define CINSTANCELIFEMAINTAINER_H
//Begin section for file CInstanceLifeMaintainer.h
//TODO: Add definitions that you want preserved
//End section for file CInstanceLifeMaintainer.h
#include "../../interface/IMaintainable.h"
#include "../../interface/IInterface.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CInstanceLifeMaintainer : public IMaintainable
	{

		//Begin section for atom::CInstanceLifeMaintainer
		//TODO: Add attributes that you want preserved
		//End section for atom::CInstanceLifeMaintainer

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IInterface * nest;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceLifeMaintainer(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CInstanceLifeMaintainer(); 



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



	};  //end class CInstanceLifeMaintainer



} //end namespace atom



#endif
