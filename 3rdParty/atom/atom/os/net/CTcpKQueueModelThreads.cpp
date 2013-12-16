#include "CTcpKQueueModelThreads.h"
#include "../../interface/ITcpKQueueIOModel.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpKQueueModelThreads.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpKQueueModelThreads.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpKQueueModelThreads::CTcpKQueueModelThreads() : 
nest(NULL),amount(1)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpKQueueModelThreads::~CTcpKQueueModelThreads() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpKQueueModelThreads::IncRef() 
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
int atom::CTcpKQueueModelThreads::DecRef() 
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
int atom::CTcpKQueueModelThreads::GetRef() 
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
atom::IInterface * atom::CTcpKQueueModelThreads::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpKQueueModelThreads::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueModelThreads::OnBegin() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueModelThreads::OnClose() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpKQueueModelThreads::OnAwake() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueModelThreads::OnBegin(U32 index) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( index );
    return false;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueModelThreads::OnClose(U32 index) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( index );
    return false;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpKQueueModelThreads::OnAwake(U32 index) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( index );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpKQueueModelThreads::SetThreadAmount(U32 value) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CTcpKQueueModelThreads::GetThreadAmount() 
{
    //TODO Auto-generated method stub
	return amount;
}
