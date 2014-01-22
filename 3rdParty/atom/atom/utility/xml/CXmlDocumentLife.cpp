#include "CXmlDocumentLife.h"
#include "../tool/CInterface.h"
#include "../../interface/IXmlDocumentNode.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CXmlDocumentLife::CXmlDocumentLife() : 
nest(NULL)
{
}

atom::CXmlDocumentLife::~CXmlDocumentLife() 
{
}

int atom::CXmlDocumentLife::IncRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
    return result;
}

int atom::CXmlDocumentLife::DecRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
    return result;
}

int atom::CXmlDocumentLife::GetRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
    return result;
}

atom::IInterface * atom::CXmlDocumentLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CXmlDocumentLife::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CXmlDocumentLife::Initiate() 
{
    return true;
}

bool atom::CXmlDocumentLife::Shutdown() 
{
	CInterface<IXmlDocumentNode> segment;
	if( segment.Mount(this, IID_XML_DOCUMENT_NODE) ) {
		segment -> Shutdown();
	}
    return true;
}
