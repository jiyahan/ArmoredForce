#ifndef TAGIOCPOPERATION_H
#define TAGIOCPOPERATION_H
//Begin section for file tagIocpOperation.h
//TODO: Add definitions that you want preserved
//End section for file tagIocpOperation.h
#include "CIocpOverlap.h"
#include "CIocpBuffer.h"
#include "../memory/CMemory.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	struct tagIocpOperation
	{

		//Begin section for atom::tagIocpOperation
		//TODO: Add attributes that you want preserved
		//End section for atom::tagIocpOperation

		private:


			#ifdef _WIN32
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CObjectPtr ob;
			#endif



		public:


			#ifdef _WIN32
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U08 op;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			SOCKET hs;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CIocpOverlap ol;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CIocpBuffer wb;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CMemory mb;
			#endif



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagIocpOperation(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			~tagIocpOperation(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Reset(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool Attach(CObjectPtr & object); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Detach(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U64 GetObjectName(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CObjectPtr GetObject(); 



	};  //end struct tagIocpOperation



} //end namespace atom



#endif
