#include "CTcpSelectModelThread.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/ITcpSelectIOModel.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpSelectModelThread.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpSelectModelThread.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpSelectModelThread::CTcpSelectModelThread() : 
CThread("Tcp Select Model"),nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpSelectModelThread::~CTcpSelectModelThread() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpSelectModelThread::IncRef() 
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
int atom::CTcpSelectModelThread::DecRef() 
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
int atom::CTcpSelectModelThread::GetRef() 
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
atom::IInterface * atom::CTcpSelectModelThread::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpSelectModelThread::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelThread::OnThreadBegin() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelThread::OnThreadClose() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CTcpSelectModelThread::Run() 
{
    //TODO Auto-generated method stub
	U32 result = 0;
	CInterface<ITcpSelectIOModel> segment;
	if( segment.Mount(this, IID_TCP_SELECT_IO_MODEL) ) {
		segment -> OnProcess();
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelThread::OnBegin() 
{
    //TODO Auto-generated method stub
	CInterface<ITcpSelectIOModel> segment;
	if( segment.Mount(this, IID_TCP_SELECT_IO_MODEL) ) {
	    segment -> SetActive( true );
	}
    return Begin( TP_BELOW_NORMAL );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelThread::OnClose() 
{
    //TODO Auto-generated method stub
	CInterface<ITcpSelectIOModel> segment;
	if( segment.Mount(this, IID_TCP_SELECT_IO_MODEL) ) {
	    segment -> SetActive( false );
	}
    Close( U64(INFINITE) );
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpSelectModelThread::OnAwake() 
{
    //TODO Auto-generated method stub
    return;
}
