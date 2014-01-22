#include "CXmlDocument.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CXmlDocument::CXmlDocument() 
{
	node.SetNest( this );
	life.SetNest( this );
}

atom::CXmlDocument::~CXmlDocument() 
{
}

const char * atom::CXmlDocument::ToString() 
{
	static char name[] = "Xml Document";
    return name;
}

atom::IInterface * atom::CXmlDocument::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
	case IID_INSTANCE_LIFE:
		if( life      .IncRef() )
			result = & life;
        break;
	case IID_XML_ELEMENT_NODE:
	case IID_XML_DOCUMENT_NODE:
		if( node      .IncRef() )
			result = & node;
        break;
    }
    return result;
}
