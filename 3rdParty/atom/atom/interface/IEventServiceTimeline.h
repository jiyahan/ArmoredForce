#ifndef IEVENTSERVICETIMELINE_H
#define IEVENTSERVICETIMELINE_H
//Begin section for file IEventServiceTimeline.h
//TODO: Add definitions that you want preserved
//End section for file IEventServiceTimeline.h
#include "IEmbedInterface.h"
#include "../utility/stl/CU64Array.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IEventServiceTimeline : public IEmbedInterface
	{

		//Begin section for atom::IEventServiceTimeline
		//TODO: Add attributes that you want preserved
		//End section for atom::IEventServiceTimeline



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Mark(U64 time, U64 instance) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Forward(U64 time, CU64Array & instances) = 0; 



	};  //end class IEventServiceTimeline



} //end namespace atom



#endif
