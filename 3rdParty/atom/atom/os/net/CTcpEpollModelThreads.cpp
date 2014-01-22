#include "CTcpEpollModelThreads.h"
#include "../../interface/ITcpEpollIOModel.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpEpollModelThreads::CTcpEpollModelThreads() : 
nest(NULL),amount(1)
{
}

atom::CTcpEpollModelThreads::~CTcpEpollModelThreads() 
{
}

int atom::CTcpEpollModelThreads::IncRef() 
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

int atom::CTcpEpollModelThreads::DecRef() 
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

int atom::CTcpEpollModelThreads::GetRef() 
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

atom::IInterface * atom::CTcpEpollModelThreads::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpEpollModelThreads::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CTcpEpollModelThreads::OnBegin() 
{
	#ifdef __linux
    CObjectPtr object =
        CInstanceUtility::MakeObject( nest );
    if( object )
    {
		CInterface<ITcpEpollIOModel> segment;
		if( segment.Mount(this, IID_TCP_EPOLL_IO_MODEL) ) {
			amount = segment -> GetAmount();
			amount = atom_max( amount, 1 );
			amount = atom_min( amount, MAX_EPOLL_THREAD );
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

bool atom::CTcpEpollModelThreads::OnClose() 
{
	#ifdef __linux
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

void atom::CTcpEpollModelThreads::OnAwake() 
{
}

bool atom::CTcpEpollModelThreads::OnBegin(U32 index) 
{
	UNREFERENCED_PARAMETER( index );
    return false;
}

bool atom::CTcpEpollModelThreads::OnClose(U32 index) 
{
	UNREFERENCED_PARAMETER( index );
    return false;
}

void atom::CTcpEpollModelThreads::OnAwake(U32 index) 
{
	UNREFERENCED_PARAMETER( index );
}

void atom::CTcpEpollModelThreads::SetThreadAmount(U32 value) 
{
	UNREFERENCED_PARAMETER( value );
}

U32 atom::CTcpEpollModelThreads::GetThreadAmount() 
{
	return amount;
}
