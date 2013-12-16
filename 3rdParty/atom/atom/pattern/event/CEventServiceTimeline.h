#ifndef CEVENTSERVICETIMELINE_H
#define CEVENTSERVICETIMELINE_H
//Begin section for file CEventServiceTimeline.h
//TODO: Add definitions that you want preserved
//End section for file CEventServiceTimeline.h
#include "../../interface/IEventServiceTimeline.h"
#include "../../interface/IInterface.h"
#include "CEventServiceTimelineBind.h"
#include "../../utility/stl/CU64Array.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CEventServiceTimeline : public IEventServiceTimeline
	{

		//Begin section for atom::CEventServiceTimeline
		//TODO: Add attributes that you want preserved
		//End section for atom::CEventServiceTimeline

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IInterface * nest;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CEventServiceTimelineBind line;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CEventServiceTimeline(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CEventServiceTimeline(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int IncRef(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int DecRef(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int GetRef(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual IInterface * QueryInterface(U32 iid); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void SetNest(IInterface * nest); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Mark(U64 time, U64 instance); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Forward(U64 time, CU64Array & instances); 



	};  //end class CEventServiceTimeline



} //end namespace atom



#endif
