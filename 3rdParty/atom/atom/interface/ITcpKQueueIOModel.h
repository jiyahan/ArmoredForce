#ifndef ITCPKQUEUEIOMODEL_H
#define ITCPKQUEUEIOMODEL_H
//Begin section for file ITcpKQueueIOModel.h
//TODO: Add definitions that you want preserved
//End section for file ITcpKQueueIOModel.h
#include "ITcpIOModel.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class ITcpKQueueIOModel : public ITcpIOModel
	{

		//Begin section for atom::ITcpKQueueIOModel
		//TODO: Add attributes that you want preserved
		//End section for atom::ITcpKQueueIOModel



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual I32 OnProcess(U32 id) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U32 GetAmount() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void PreShutdown() = 0; 



	};  //end class ITcpKQueueIOModel



} //end namespace atom



#endif
