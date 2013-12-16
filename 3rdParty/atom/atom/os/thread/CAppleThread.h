#ifndef CAPPLETHREAD_H
#define CAPPLETHREAD_H
//Begin section for file CAppleThread.h
//TODO: Add definitions that you want preserved
//End section for file CAppleThread.h
#include "CSignal.h"
#include "CCriticalSection.h"
#include "../../enumeration/THREAD_PRIORITY.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CAppleThread
	{

		//Begin section for atom::CAppleThread
		//TODO: Add attributes that you want preserved
		//End section for atom::CAppleThread

		private:



            #ifdef __APPLE__
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            pthread_t handle;
            #endif

			

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			std::string thread;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CSignal signal;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CCriticalSection region;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			explicit CAppleThread(const char * name); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CAppleThread(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			const char * GetName(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void CloseNotify();



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Begin(U08 priority = TP_NORMAL); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Close(U64 timeout); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool OnThreadBegin(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool OnThreadClose(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U32 Run(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static void Sleep(U64 time); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static U64 GetCurrentThreadID(); 



	};  //end class CAppleThread



} //end namespace atom



#endif
