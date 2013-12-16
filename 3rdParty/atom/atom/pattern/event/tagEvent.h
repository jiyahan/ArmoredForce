#ifndef TAGEVENT_H
#define TAGEVENT_H
//Begin section for file tagEvent.h
//TODO: Add definitions that you want preserved
//End section for file tagEvent.h
#include "../../utility/stl/a_string.h"
#include "../../utility/variant/CVariant.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	struct tagEvent
	{

		//Begin section for atom::tagEvent
		//TODO: Add attributes that you want preserved
		//End section for atom::tagEvent



		public:


			//<p>event type</p>
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U32 handle;



			//<p>event append data</p>
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CVariant append;



			//<p>source instance</p>
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U64 source;



			//<p>event target, empty means send to all.</p>
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			a_string target;



			//<p>event description</p>
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			a_string record;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagEvent(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagEvent(const tagEvent & value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~tagEvent(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagEvent & operator=(const tagEvent & value); 



	};  //end struct tagEvent



} //end namespace atom



#endif
