#ifndef CMAINTAINERLIFE_H
#define CMAINTAINERLIFE_H
//Begin section for file CMaintainerLife.h
//TODO: Add definitions that you want preserved
//End section for file CMaintainerLife.h
#include "../interface/IInstanceLife.h"
#include "../interface/IInterface.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CMaintainerLife : public IInstanceLife
	{

		//Begin section for atom::CMaintainerLife
		//TODO: Add attributes that you want preserved
		//End section for atom::CMaintainerLife

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IInterface * nest;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CMaintainerLife(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CMaintainerLife(); 



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



	};  //end class CMaintainerLife



} //end namespace atom


	
#endif
