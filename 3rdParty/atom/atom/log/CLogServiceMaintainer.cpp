#include "CLogServiceMaintainer.h"
#include "../utility/tool/CInterface.h"
#include "../interface/ILogServiceController.h"
#include "../enumeration/INTERFACE_ID.h"


atom::CLogServiceMaintainer::CLogServiceMaintainer() : 
nest(NULL)
{
}

atom::CLogServiceMaintainer::~CLogServiceMaintainer() 
{
}

int atom::CLogServiceMaintainer::IncRef() 
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

int atom::CLogServiceMaintainer::DecRef() 
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

int atom::CLogServiceMaintainer::GetRef() 
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

atom::IInterface * atom::CLogServiceMaintainer::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CLogServiceMaintainer::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

U64 atom::CLogServiceMaintainer::OnMaintenance(U64 now) 
{
	CInterface<ILogServiceController> segment;
    if( segment.Mount(this, IID_LOG_SERVICE_CONTROLLER) ) {
		segment -> Flush();
	}
	return now + 2000;
}
