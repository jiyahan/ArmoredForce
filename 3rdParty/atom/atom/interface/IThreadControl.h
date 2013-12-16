#ifndef ITHREADCONTROL_H
#define ITHREADCONTROL_H
//Begin section for file IThreadControl.h
//TODO: Add definitions that you want preserved
//End section for file IThreadControl.h
#include "IEmbedInterface.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IThreadControl : public IEmbedInterface
	{

		//Begin section for atom::IThreadControl
		//TODO: Add attributes that you want preserved
		//End section for atom::IThreadControl



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool OnBegin() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool OnClose() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void OnAwake() = 0; 



	};  //end class IThreadControl



} //end namespace atom



#endif
