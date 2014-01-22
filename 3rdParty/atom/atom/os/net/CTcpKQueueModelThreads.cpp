#include "CTcpKQueueModelThreads.h"
#include "../../interface/ITcpKQueueIOModel.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpKQueueModelThreads::CTcpKQueueModelThreads() : 
nest(NULL),amount(1)
{
}

atom::CTcpKQueueModelThreads::~CTcpKQueueModelThreads() 
{
}

int atom::CTcpKQueueModelThreads::IncRef() 
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

int atom::CTcpKQueueModelThreads::DecRef() 
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

int atom::CTcpKQueueModelThreads::GetRef() 
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

atom::IInterface * atom::CTcpKQueueModelThreads::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpKQueueModelThreads::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CTcpKQueueModelThreads::OnBegin() 
{
	#ifdef __APPLE__
    CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object )
    {
		CInterface<ITcpKQueueIOModel> segment;
		if( segment.Mount(this, IID_TCP_KQUEUE_IO_MODEL) ) {
			amount = segment -> GetAmount();
			amount = atom_max( amount, 1 );
			amount = atom_min( amount, MAX_KQUEUE_THREAD );
		}

        for( U32 i = 0; i < amount; ++ i )
        {
			worker[i].SetSerial( i );
            worker[i].SetObject( object );
			worker[i].Begin( TP_BELOW_NORMAL );
        }
    }
    return true;
	#else
	return false;
	#endif
}

bool atom::CTcpKQueueModelThreads::OnClose() 
{
	#ifdef __APPLE__
    CObjectPtr object;
    for( size_t i = 0; i < amount; ++ i )
    {
        worker[i].Close( U64(INFINITE) );
        worker[i].SetObject( object );
    }
    return true;
	#else
	return false;
	#endif
}

void atom::CTcpKQueueModelThreads::OnAwake() 
{
}

bool atom::CTcpKQueueModelThreads::OnBegin(U32 index) 
{
	UNREFERENCED_PARAMETER( index );
    return false;
}

bool atom::CTcpKQueueModelThreads::OnClose(U32 index) 
{
	UNREFERENCED_PARAMETER( index );
    return false;
}

void atom::CTcpKQueueModelThreads::OnAwake(U32 index) 
{
	UNREFERENCED_PARAMETER( index );
}

void atom::CTcpKQueueModelThreads::SetThreadAmount(U32 value) 
{
	UNREFERENCED_PARAMETER( value );
}

U32 atom::CTcpKQueueModelThreads::GetThreadAmount() 
{
	return amount;
}
