#include "CTcpEpollModelLife.h"
#include "../../interface/ITcpEpollIOModel.h"
#include "../../interface/IThreadControl.h"
#include "../../interface/IInstanceAliasContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"
//Begin section for file CTcpEpollModelLife.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpEpollModelLife.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpEpollModelLife::CTcpEpollModelLife() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpEpollModelLife::~CTcpEpollModelLife() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpEpollModelLife::IncRef() 
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
int atom::CTcpEpollModelLife::DecRef() 
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
int atom::CTcpEpollModelLife::GetRef() 
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
atom::IInterface * atom::CTcpEpollModelLife::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpEpollModelLife::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollModelLife::Initiate() 
{
    //TODO Auto-generated method stub
	bool result = false;
	CInterface<ITcpEpollIOModel> segment_1;
	if( segment_1.Mount(this, IID_TCP_EPOLL_IO_MODEL) ) {
		result = segment_1 -> Initiate();
	}

	CInterface<IThreadControl> segment_2;
	if( segment_2.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_2 -> OnBegin() && result;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollModelLife::Shutdown() 
{
    //TODO Auto-generated method stub
	bool result = false;
	CInterface<ITcpEpollIOModel> segment_0;
	if( segment_0.Mount(this, IID_TCP_EPOLL_IO_MODEL) ) {
		segment_0 -> PreShutdown();
	}

	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnClose();
	}

	CInterface<ITcpEpollIOModel> segment_2;
	if( segment_2.Mount(this, IID_TCP_EPOLL_IO_MODEL) ) {
		result = segment_2 -> Shutdown() && result;
	}
    return result;
}
