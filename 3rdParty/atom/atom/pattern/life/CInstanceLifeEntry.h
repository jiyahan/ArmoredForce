#ifndef CINSTANCELIFEENTRY_H
#define CINSTANCELIFEENTRY_H
//Begin section for file CInstanceLifeEntry.h
//TODO: Add definitions that you want preserved
//End section for file CInstanceLifeEntry.h
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CInstanceLifeEntry : public IInstanceLife
	{

		//Begin section for atom::CInstanceLifeEntry
		//TODO: Add attributes that you want preserved
		//End section for atom::CInstanceLifeEntry

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IInterface * nest;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceLifeEntry(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CInstanceLifeEntry(); 



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
			virtual bool Initiate(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Shutdown(); 



	};  //end class CInstanceLifeEntry



} //end namespace atom



#endif
