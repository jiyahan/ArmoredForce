#ifndef ITCPCONNECTORFLUSHDEVICE_H
#define ITCPCONNECTORFLUSHDEVICE_H
//Begin section for file ITcpConnectorFlushDevice.h
//TODO: Add definitions that you want preserved
//End section for file ITcpConnectorFlushDevice.h
#include "IFlushDevice.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class ITcpConnectorFlushDevice : public IFlushDevice
	{

		//Begin section for atom::ITcpConnectorFlushDevice
		//TODO: Add attributes that you want preserved
		//End section for atom::ITcpConnectorFlushDevice



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Bind(U32 iomodel) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool OnDataSent(size_t bytes) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Reset() = 0; 



	};  //end class ITcpConnectorFlushDevice



} //end namespace atom



#endif
