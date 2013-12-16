#include "CXmlElement.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CXmlElement.cpp
//TODO: Add definitions that you want preserved
//End section for file CXmlElement.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CXmlElement::CXmlElement() 
{
    //TODO Auto-generated method stub
	node.SetNest( this );
	life.SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CXmlElement::~CXmlElement() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CXmlElement::ToString() 
{
    //TODO Auto-generated method stub
	static char name[] = "Xml Element";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CXmlElement::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    switch( iid )
    {
	case IID_INSTANCE_LIFE:
		if( life      .IncRef() )
			result = & life;
        break;
	case IID_XML_ELEMENT_NODE:
		if( node      .IncRef() )
			result = & node;
        break;
    }
    return result;
}
