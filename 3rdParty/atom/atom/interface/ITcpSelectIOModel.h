#ifndef ITCPSELECTIOMODEL_H
#define ITCPSELECTIOMODEL_H
//Begin section for file ITcpSelectIOModel.h
//TODO: Add definitions that you want preserved
//End section for file ITcpSelectIOModel.h
#include "ITcpIOModel.h"



namespace atom
{


	
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class ITcpSelectIOModel : public ITcpIOModel
	{

		//Begin section for atom::ITcpSelectIOModel
		//TODO: Add attributes that you want preserved
		//End section for atom::ITcpSelectIOModel



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void SetActive(bool value) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual I32 OnProcess() = 0; 



	};  //end class ITcpSelectIOModel



} //end namespace



#endif
