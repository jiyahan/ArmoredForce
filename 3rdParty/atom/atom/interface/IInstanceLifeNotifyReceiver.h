#ifndef IINSTANCELIFENOTIFYRECEIVER_H
#define IINSTANCELIFENOTIFYRECEIVER_H
//Begin section for file IInstanceLifeNotifyReceiver.h
//TODO: Add definitions that you want preserved
//End section for file IInstanceLifeNotifyReceiver.h
#include "IEmbedInterface.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IInstanceLifeNotifyReceiver : public IEmbedInterface
	{

		//Begin section for atom::IInstanceLifeNotifyReceiver
		//TODO: Add attributes that you want preserved
		//End section for atom::IInstanceLifeNotifyReceiver



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool OnCreateInstance(U64 name) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool OnRemoveInstance(U64 name) = 0; 



	};  //end class IInstanceLifeNotifyReceiver



} //end namespace atom



#endif
