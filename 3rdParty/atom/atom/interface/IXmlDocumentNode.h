#ifndef IXMLDOCUMENTNODE_H
#define IXMLDOCUMENTNODE_H
//Begin section for file IXmlDocumentNode.h
//TODO: Add definitions that you want preserved
//End section for file IXmlDocumentNode.h
#include "IXmlElementNode.h"
#include "../os/memory/CMemory.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IXmlDocumentNode : public IXmlElementNode
	{

		//Begin section for atom::IXmlDocumentNode
		//TODO: Add attributes that you want preserved
		//End section for atom::IXmlDocumentNode



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Load(const char * file) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Load(CMemory & data) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Save(const char * file) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Save(CMemory & data) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void SetDeclaration(const char * version, const char * encoding) = 0; 



	};  //end class IXmlDocumentNode



} //end namespace atom



#endif
