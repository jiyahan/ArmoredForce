#ifndef IINSTANCELIFENOTIFY_H
#define IINSTANCELIFENOTIFY_H
//Begin section for file IInstanceLifeNotify.h
//TODO: Add definitions that you want preserved
//End section for file IInstanceLifeNotify.h
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IInstanceLifeNotify : public IEmbedInterface
	{

		//Begin section for atom::IInstanceLifeNotify
		//TODO: Add attributes that you want preserved
		//End section for atom::IInstanceLifeNotify



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void SetReceiver(CObjectPtr & value) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual CObjectPtr GetReceiver() = 0; 



	};  //end class IInstanceLifeNotify



} //end namespace atom



#endif
