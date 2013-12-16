#include "CTcpEpollModelThreads.h"
#include "../../interface/ITcpEpollIOModel.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpEpollModelThreads.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpEpollModelThreads.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpEpollModelThreads::CTcpEpollModelThreads() : 
nest(NULL),amount(1)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpEpollModelThreads::~CTcpEpollModelThreads() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpEpollModelThreads::IncRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpEpollModelThreads::DecRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpEpollModelThreads::GetRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CTcpEpollModelThreads::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpEpollModelThreads::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollModelThreads::OnBegin() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollModelThreads::OnClose() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpEpollModelThreads::OnAwake() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollModelThreads::OnBegin(U32 index) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( index );
    return false;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollModelThreads::OnClose(U32 index) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( index );
    return false;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpEpollModelThreads::OnAwake(U32 index) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( index );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpEpollModelThreads::SetThreadAmount(U32 value) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CTcpEpollModelThreads::GetThreadAmount() 
{
    //TODO Auto-generated method stub
	return amount;
}
