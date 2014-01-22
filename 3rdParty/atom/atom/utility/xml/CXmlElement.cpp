#include "CXmlElement.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CXmlElement::CXmlElement() 
{
	node.SetNest( this );
	life.SetNest( this );
}

atom::CXmlElement::~CXmlElement() 
{
}

const char * atom::CXmlElement::ToString() 
{
	static char name[] = "Xml Element";
    return name;
}

atom::IInterface * atom::CXmlElement::QueryInterface(U32 iid) 
{
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
