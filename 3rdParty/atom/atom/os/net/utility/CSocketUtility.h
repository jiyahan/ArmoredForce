#ifndef CSOCKETUTILITY_H
#define CSOCKETUTILITY_H
//Begin section for file CSocketUtility.h
//TODO: Add definitions that you want preserved
//End section for file CSocketUtility.h
#include "../../../Common.h"
#include "../../../utility/tool/CObjectPtr.h"
#include "../../../utility/stl/a_string.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CSocketUtility
	{

		//Begin section for atom::CSocketUtility
		//TODO: Add attributes that you want preserved
		//End section for atom::CSocketUtility



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static U32 DomainToIPV4(const char * address); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static bool Open(CObjectPtr & object, const char * host, U16 port, U32 io_model);



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static void Shut(CObjectPtr & object);



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static a_string GetSelfAddress(CObjectPtr & object);



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static U16 GetSelfPort(CObjectPtr & object);



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static a_string GetPeerAddress(CObjectPtr & object);



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static U16 GetPeerPort(CObjectPtr & object);



	};  //end class CSocketUtility
	


} //end namespace atom



#endif
