#ifndef CTCPIOCPMODELTHREADWORKER_H
#define CTCPIOCPMODELTHREADWORKER_H
//Begin section for file CTcpIocpModelThreadWorker.h
//TODO: Add definitions that you want preserved
//End section for file CTcpIocpModelThreadWorker.h
#include "../thread/CThread.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CTcpIocpModelThreadWorker : public CThread
	{

		//Begin section for atom::CTcpIocpModelThreadWorker
		//TODO: Add attributes that you want preserved
		//End section for atom::CTcpIocpModelThreadWorker

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CObjectPtr object;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U32 serial;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpIocpModelThreadWorker(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CTcpIocpModelThreadWorker(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U32 Run(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool OnThreadBegin(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool OnThreadClose(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void SetObject(CObjectPtr & value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void SetSerial(U32 value);



	};  //end class CTcpIocpModelThreadWorker



} //end namespace atom



#endif
