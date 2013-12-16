#ifndef ITCPIOCPIOMODEL_H
#define ITCPIOCPIOMODEL_H
//Begin section for file ITcpIocpIOModel.h
//TODO: Add definitions that you want preserved
//End section for file ITcpIocpIOModel.h
#include "ITcpIOModel.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class ITcpIocpIOModel : public ITcpIOModel
	{

		//Begin section for atom::ITcpIocpIOModel
		//TODO: Add attributes that you want preserved
		//End section for atom::ITcpIocpIOModel



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual I32 OnProcess(U32 index) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U32 GetAmount() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void PreShutdown() = 0; 



	};  //end class ITcpIocpIOModel



} //end namespace atom



#endif
