#ifndef TAGDOMAIN_H
#define TAGDOMAIN_H
//Begin section for file tagDomain.h
//TODO: Add definitions that you want preserved
//End section for file tagDomain.h
#include "../../utility/stl/a_string.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	struct tagDomain
	{

		//Begin section for atom::tagDomain
		//TODO: Add attributes that you want preserved
		//End section for atom::tagDomain



		public:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			a_string host;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U16 port;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagDomain(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagDomain(const tagDomain & value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~tagDomain(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagDomain & operator=(const tagDomain & value); 



	};  //end struct tagDomain



} //end namespace atom



#endif
