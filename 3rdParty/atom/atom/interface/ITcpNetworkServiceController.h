#ifndef ITCPNETWORKSERVICECONTROLLER_H
#define ITCPNETWORKSERVICECONTROLLER_H
//Begin section for file ITcpNetworkServiceController.h
//TODO: Add definitions that you want preserved
//End section for file ITcpNetworkServiceController.h
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class ITcpNetworkServiceController : public IEmbedInterface
	{

		//Begin section for atom::ITcpNetworkServiceController
		//TODO: Add attributes that you want preserved
		//End section for atom::ITcpNetworkServiceController



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Initiate() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Shutdown() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual CObjectPtr GetModel(U32 io_model) = 0; 



	};  //end class ITcpNetworkServiceController



} //end namespace atom



#endif
