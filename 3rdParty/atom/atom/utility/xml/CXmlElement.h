#ifndef CXMLELEMENT_H
#define CXMLELEMENT_H
//Begin section for file CXmlElement.h
//TODO: Add definitions that you want preserved
//End section for file CXmlElement.h
#include "../../pattern/object/CReferencedObject.h"
#include "CXmlElementNode.h"
#include "CXmlElementLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CXmlElement : public CReferencedObject
	{

		//Begin section for atom::CXmlElement
		//TODO: Add attributes that you want preserved
		//End section for atom::CXmlElement

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CXmlElementNode node;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CXmlElementLife life;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CXmlElement(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CXmlElement(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual const char * ToString(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CXmlElement



} //end namespace atom



#endif
