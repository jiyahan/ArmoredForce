#ifndef TAGTCPKQUEUEOPERATION_H
#define TAGTCPKQUEUEOPERATION_H
//Begin section for file tagTcpKQueueOperation.h
//TODO: Add definitions that you want preserved
//End section for file tagTcpKQueueOperation.h
#include "../../utility/tool/CObjectPtr.h"
#include "../memory/CMemory.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	struct tagTcpKQueueOperation
	{

		//Begin section for atom::tagTcpKQueueOperation
		//TODO: Add attributes that you want preserved
		//End section for atom::tagTcpKQueueOperation

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CObjectPtr object;




		public:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CMemory memory;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			size_t offset;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			size_t length;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagTcpKQueueOperation(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~tagTcpKQueueOperation(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Reset(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Attach(CObjectPtr & value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Detach(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CObjectPtr Object(); 



	};  //end struct tagTcpKQueueOperation



} //end namespace atom



#endif
