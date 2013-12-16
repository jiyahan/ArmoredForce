#ifndef ITCPEPOLLIOMODEL_H
#define ITCPEPOLLIOMODEL_H
//Begin section for file ITcpEpollIOModel.h
//TODO: Add definitions that you want preserved
//End section for file ITcpEpollIOModel.h
#include "ITcpIOModel.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class ITcpEpollIOModel : public ITcpIOModel
	{

		//Begin section for atom::ITcpEpollIOModel
		//TODO: Add attributes that you want preserved
		//End section for atom::ITcpEpollIOModel



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual I32 OnProcess(U32 id) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U32 GetAmount() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void PreShutdown() = 0; 



	};  //end class ITcpEpollIOModel



} //end namespace atom



#endif
