#ifndef ITCPLISTENERCONTROLLER_H
#define ITCPLISTENERCONTROLLER_H
//Begin section for file ITcpListenerController.h
//TODO: Add definitions that you want preserved
//End section for file ITcpListenerController.h
#include "ITcpConnectionController.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class ITcpListenerController : public ITcpConnectionController
	{

		//Begin section for atom::ITcpListenerController
		//TODO: Add attributes that you want preserved
		//End section for atom::ITcpListenerController



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U64 Accept(SOCKET socket) = 0; 



	};  //end class ITcpListenerController



} //end namespace atom



#endif
