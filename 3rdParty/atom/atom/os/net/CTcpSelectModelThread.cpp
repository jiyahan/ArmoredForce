#include "CTcpSelectModelThread.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/ITcpSelectIOModel.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpSelectModelThread::CTcpSelectModelThread() : 
CThread("Tcp Select Model"),nest(NULL)
{
}

atom::CTcpSelectModelThread::~CTcpSelectModelThread() 
{
}

int atom::CTcpSelectModelThread::IncRef() 
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

int atom::CTcpSelectModelThread::DecRef() 
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

int atom::CTcpSelectModelThread::GetRef() 
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

atom::IInterface * atom::CTcpSelectModelThread::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpSelectModelThread::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CTcpSelectModelThread::OnThreadBegin() 
{
    return true;
}

bool atom::CTcpSelectModelThread::OnThreadClose() 
{
    return true;
}

U32 atom::CTcpSelectModelThread::Run() 
{
	U32 result = 0;
	CInterface<ITcpSelectIOModel> segment;
	if( segment.Mount(this, IID_TCP_SELECT_IO_MODEL) ) {
		segment -> OnProcess();
	}
	return result;
}

bool atom::CTcpSelectModelThread::OnBegin() 
{
	CInterface<ITcpSelectIOModel> segment;
	if( segment.Mount(this, IID_TCP_SELECT_IO_MODEL) ) {
	    segment -> SetActive( true );
	}
    return Begin( TP_BELOW_NORMAL );
}

bool atom::CTcpSelectModelThread::OnClose() 
{
	CInterface<ITcpSelectIOModel> segment;
	if( segment.Mount(this, IID_TCP_SELECT_IO_MODEL) ) {
	    segment -> SetActive( false );
	}
    Close( U64(INFINITE) );
    return true;
}

void atom::CTcpSelectModelThread::OnAwake() 
{
    return;
}
