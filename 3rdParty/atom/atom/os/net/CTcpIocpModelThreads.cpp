#include "CTcpIocpModelThreads.h"
#include "../../interface/ITcpIocpIOModel.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpIocpModelThreads.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpIocpModelThreads.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpIocpModelThreads::CTcpIocpModelThreads() : 
nest(NULL)
#ifdef _WIN32
,amount(IOCP_TH_RATIO)
#endif
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpIocpModelThreads::~CTcpIocpModelThreads() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpIocpModelThreads::IncRef() 
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
int atom::CTcpIocpModelThreads::DecRef() 
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
int atom::CTcpIocpModelThreads::GetRef() 
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
atom::IInterface * atom::CTcpIocpModelThreads::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpIocpModelThreads::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpIocpModelThreads::OnBegin() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpIocpModelThreads::OnClose() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpIocpModelThreads::OnAwake() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpIocpModelThreads::OnBegin(U32 index) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( index );
    return false;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpIocpModelThreads::OnClose(U32 index) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( index );
    return false;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpIocpModelThreads::OnAwake(U32 index) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( index );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpIocpModelThreads::SetThreadAmount(U32 value) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CTcpIocpModelThreads::GetThreadAmount() 
{
    //TODO Auto-generated method stub
	#ifdef _WIN32
	return amount;
	#else
	return 0;
	#endif
}
