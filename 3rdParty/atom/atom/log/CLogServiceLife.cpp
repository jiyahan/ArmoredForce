#include "CLogServiceLife.h"
#include "../maintainer/CMaintainer.h"
#include "../interface/ILogServiceController.h"
#include "../enumeration/INTERFACE_ID.h"
#include "../utility/tool/CInterface.h"
#include "../utility/tool/CInstanceUtility.h"


atom::CLogServiceLife::CLogServiceLife() : 
nest(NULL)
{
}

atom::CLogServiceLife::~CLogServiceLife() 
{
}

int atom::CLogServiceLife::IncRef() 
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

int atom::CLogServiceLife::DecRef() 
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

int atom::CLogServiceLife::GetRef() 
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

atom::IInterface * atom::CLogServiceLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CLogServiceLife::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CLogServiceLife::Initiate() 
{
    CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object ) {
	    CMaintainer::GetInstance() -> Attach( object );
    }
    return true;
}

bool atom::CLogServiceLife::Shutdown() 
{
    CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object ) {
	    CMaintainer::GetInstance() -> Detach( object );
    }

    CInterface<ILogServiceController> segment;
    if( segment.Mount(this, IID_LOG_SERVICE_CONTROLLER) ) {
        segment -> Flush();
        segment -> Clear();
    }
    return true;
}
