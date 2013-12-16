#include "CTcpIocpModelLife.h"
#include "../../interface/ITcpIocpIOModel.h"
#include "../../interface/IMultiThreadControl.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/IInstanceAliasContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"
//Begin section for file CTcpIocpModelLife.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpIocpModelLife.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpIocpModelLife::CTcpIocpModelLife() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpIocpModelLife::~CTcpIocpModelLife() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpIocpModelLife::IncRef() 
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
int atom::CTcpIocpModelLife::DecRef() 
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
int atom::CTcpIocpModelLife::GetRef() 
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
atom::IInterface * atom::CTcpIocpModelLife::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpIocpModelLife::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpIocpModelLife::Initiate() 
{
    //TODO Auto-generated method stub
	bool result = false;
	CInterface<ITcpIocpIOModel> segment_1;
	if( segment_1.Mount(this, IID_TCP_IOCP_IO_MODEL) ) {
		result = segment_1 -> Initiate();
	}

	CInterface<IThreadControl> segment_2;
	if( segment_2.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_2 -> OnBegin() && result;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpIocpModelLife::Shutdown() 
{
    //TODO Auto-generated method stub
	bool result = false;
	CInterface<ITcpIocpIOModel> segment_0;
	if( segment_0.Mount(this, IID_TCP_IOCP_IO_MODEL) ) {
		segment_0 -> PreShutdown();
	}

	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnClose();
	}

	CInterface<ITcpIocpIOModel> segment_2;
	if( segment_2.Mount(this, IID_TCP_SELECT_IO_MODEL) ) {
		result = segment_2 -> Shutdown() && result;
	}

	CInterface<IInstanceAliasContainer<U32> > segment_3;
	if( segment_3.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) ) {
		segment_3 -> RemoveAll();
	}

	CInterface<IInstanceContainer> segment_4;
	if( segment_4.Mount(this, IID_INSTANCE_CONTAINER) ) {
		segment_4 -> RemoveAll();
	}
    return result;
}
