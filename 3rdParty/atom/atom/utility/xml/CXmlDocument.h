#ifndef CXMLDOCUMENT_H
#define CXMLDOCUMENT_H
//Begin section for file CXmlDocument.h
//TODO: Add definitions that you want preserved
//End section for file CXmlDocument.h
#include "../../pattern/object/CReferencedObject.h"
#include "CXmlDocumentLife.h"
#include "CXmlDocumentNode.h"
#include "../../interface/IInterface.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CXmlDocument : public CReferencedObject
	{

		//Begin section for atom::CXmlDocument
		//TODO: Add attributes that you want preserved
		//End section for atom::CXmlDocument

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CXmlDocumentLife life;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CXmlDocumentNode node;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CXmlDocument(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CXmlDocument(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual const char * ToString(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CXmlDocument



} //end namespace atom



#endif
