#ifndef CAPPLESIGNAL_H
#define CAPPLESIGNAL_H
//Begin section for file CAppleSignal.h
//TODO: Add definitions that you want preserved
//End section for file CAppleSignal.h
#include "../../Common.h"


namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CAppleSignal
	{

		//Begin section for atom::CAppleSignal
		//TODO: Add attributes that you want preserved
		//End section for atom::CAppleSignal

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool state;



            #ifdef __APPLE__
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            pthread_mutex_t region;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            pthread_cond_t  signal;
            #endif



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CAppleSignal(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			explicit CAppleSignal(const char * name); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			~CAppleSignal(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool Reset(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool Awake(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool Await(U64 timeout); 



	};  //end class CAppleSignal



} //end namespace atom



#endif
