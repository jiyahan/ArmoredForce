#ifndef TAGTCPSELECTOPERATION_H
#define TAGTCPSELECTOPERATION_H
//Begin section for file tagTcpSelectOperation.h
//TODO: Add definitions that you want preserved
//End section for file tagTcpSelectOperation.h
#include "../memory/CMemory.h"
#include "../../utility/stl/allocator.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	struct tagTcpSelectOperation
	{

		//Begin section for atom::tagTcpSelectOperation
		//TODO: Add attributes that you want preserved
		//End section for atom::tagTcpSelectOperation

		public:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			typedef std::set<tagTcpSelectOperation, less<tagTcpSelectOperation>, atom_allocator<tagTcpSelectOperation> >  CTcpSelectOperationBind ;



		public:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			SOCKET socket;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CMemory memory;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			size_t offset;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			size_t length;



			//<p>target connector</p>
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U64 target;



			//<p>operation serial no.</p>
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			I32 serial;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagTcpSelectOperation(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagTcpSelectOperation(const tagTcpSelectOperation & value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			~tagTcpSelectOperation(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagTcpSelectOperation & operator=(const tagTcpSelectOperation & value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool operator<(const tagTcpSelectOperation & value)const ; 



	};  //end struct tagTcpSelectOperation



} //end namespace atom



#endif
