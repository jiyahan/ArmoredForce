#include "CXmlElementLife.h"
#include "../tool/CInterface.h"
#include "../../interface/IXmlElementNode.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CXmlElementLife::CXmlElementLife() : 
nest(NULL)
{
}

atom::CXmlElementLife::~CXmlElementLife() 
{
}

int atom::CXmlElementLife::IncRef() 
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

int atom::CXmlElementLife::DecRef() 
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

int atom::CXmlElementLife::GetRef() 
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

atom::IInterface * atom::CXmlElementLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CXmlElementLife::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CXmlElementLife::Initiate() 
{
    return true;
}

bool atom::CXmlElementLife::Shutdown() 
{
	CInterface<IXmlElementNode> segment;
	if( segment.Mount(this, IID_XML_ELEMENT_NODE) ) {
		segment -> Shutdown();
	}
    return true;
}
