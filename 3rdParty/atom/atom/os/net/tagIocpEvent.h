#ifndef TAGIOCPEVENT_H
#define TAGIOCPEVENT_H
//Begin section for file tagIocpEvent.h
//TODO: Add definitions that you want preserved
//End section for file tagIocpEvent.h
#include "tagIocpOperation.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	struct tagIocpEvent
	{

		//Begin section for atom::tagIocpEvent
		//TODO: Add attributes that you want preserved
		//End section for atom::tagIocpEvent



		public:


			#ifdef _WIN32
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			ULONG_PTR object;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			DWORD length;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool losted;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagIocpOperation * packet;
			#endif



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagIocpEvent(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Reset(); 



	};  //end struct tagIocpEvent



} //end namespace atom



#endif
