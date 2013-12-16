#ifndef IINSTANCELIFE_H
#define IINSTANCELIFE_H
//Begin section for file IInstanceLife.h
//TODO: Add definitions that you want preserved
//End section for file IInstanceLife.h
#include "IEmbedInterface.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IInstanceLife : public IEmbedInterface
	{

		//Begin section for atom::IInstanceLife
		//TODO: Add attributes that you want preserved
		//End section for atom::IInstanceLife



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Initiate() = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Shutdown() = 0; 



	};  //end class IInstanceLife



} //end namespace atom



#endif
