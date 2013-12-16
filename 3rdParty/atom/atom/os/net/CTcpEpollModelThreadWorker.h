#ifndef CTCPEPOLLMODELTHREADWORKER_H
#define CTCPEPOLLMODELTHREADWORKER_H
//Begin section for file CTcpEpollModelThreadWorker.h
//TODO: Add definitions that you want preserved
//End section for file CTcpEpollModelThreadWorker.h
#include "../thread/CThread.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CTcpEpollModelThreadWorker : public CThread
	{

		//Begin section for atom::CTcpEpollModelThreadWorker
		//TODO: Add attributes that you want preserved
		//End section for atom::CTcpEpollModelThreadWorker

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CObjectPtr object;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U32 serial;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpEpollModelThreadWorker(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CTcpEpollModelThreadWorker(); 



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



	};  //end class CTcpEpollModelThreadWorker



} //end namespace atom



#endif
