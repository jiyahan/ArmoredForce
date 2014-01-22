#include "CTcpIocpModelThreads.h"
#include "../../interface/ITcpIocpIOModel.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpIocpModelThreads::CTcpIocpModelThreads() : 
nest(NULL)
#ifdef _WIN32
,amount(IOCP_TH_RATIO)
#endif
{
}

atom::CTcpIocpModelThreads::~CTcpIocpModelThreads() 
{
}

int atom::CTcpIocpModelThreads::IncRef() 
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

int atom::CTcpIocpModelThreads::DecRef() 
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

int atom::CTcpIocpModelThreads::GetRef() 
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

atom::IInterface * atom::CTcpIocpModelThreads::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpIocpModelThreads::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CTcpIocpModelThreads::OnBegin() 
{
	#ifdef _WIN32
    CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object )
    {
		CInterface<ITcpIocpIOModel> segment;
		if( segment.Mount(this, IID_TCP_IOCP_IO_MODEL) ) 
		{
			amount = segment -> GetAmount() * IOCP_TH_RATIO;
			amount = atom_max( amount, IOCP_TH_RATIO );
			amount = atom_min( amount, MAX_IOCP_THREAD );
		}

        for( U32 i = 0; i < amount; ++ i )
        {
            worker[i].SetObject( object );
			worker[i].SetSerial( i / IOCP_TH_RATIO );
			worker[i].Begin( TP_BELOW_NORMAL );
        }
    }
    return true;
	#else
	return false;
	#endif
}

bool atom::CTcpIocpModelThreads::OnClose() 
{
	#ifdef _WIN32
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

void atom::CTcpIocpModelThreads::OnAwake() 
{
}

bool atom::CTcpIocpModelThreads::OnBegin(U32 index) 
{
	UNREFERENCED_PARAMETER( index );
    return false;
}

bool atom::CTcpIocpModelThreads::OnClose(U32 index) 
{
	UNREFERENCED_PARAMETER( index );
    return false;
}

void atom::CTcpIocpModelThreads::OnAwake(U32 index) 
{
	UNREFERENCED_PARAMETER( index );
}

void atom::CTcpIocpModelThreads::SetThreadAmount(U32 value) 
{
	UNREFERENCED_PARAMETER( value );
}

U32 atom::CTcpIocpModelThreads::GetThreadAmount() 
{
	#ifdef _WIN32
	return amount;
	#else
	return 0;
	#endif
}
