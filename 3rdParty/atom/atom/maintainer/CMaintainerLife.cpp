#include "CMaintainerLife.h"
#include "../interface/IThreadControl.h"
#include "../interface/IInstanceContainer.h"
#include "../enumeration/INTERFACE_ID.h"
#include "../utility/tool/CInterface.h"


atom::CMaintainerLife::CMaintainerLife() : 
nest(NULL)
{
}

atom::CMaintainerLife::~CMaintainerLife() 
{
}

int atom::CMaintainerLife::IncRef() 
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

int atom::CMaintainerLife::DecRef() 
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

int atom::CMaintainerLife::GetRef() 
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

atom::IInterface * atom::CMaintainerLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CMaintainerLife::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CMaintainerLife::Initiate() 
{
	bool result = false;
	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnBegin();
	}
    return result;
}

bool atom::CMaintainerLife::Shutdown() 
{
	bool result = false;
	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnClose();
	}

	CInterface<IInstanceContainer> segment_2;
	if( segment_2.Mount(this, IID_INSTANCE_CONTAINER) ) {
		segment_2 -> RemoveAll();
	}
    return result;
}
