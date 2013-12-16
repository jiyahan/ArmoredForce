#include "CTcpSelectModelLife.h"
#include "../../interface/ITcpSelectIOModel.h"
#include "../../interface/IThreadControl.h"
#include "../../interface/IInstanceContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"
//Begin section for file CTcpSelectModelLife.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpSelectModelLife.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpSelectModelLife::CTcpSelectModelLife() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpSelectModelLife::~CTcpSelectModelLife() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpSelectModelLife::IncRef() 
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
int atom::CTcpSelectModelLife::DecRef() 
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
int atom::CTcpSelectModelLife::GetRef() 
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
atom::IInterface * atom::CTcpSelectModelLife::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpSelectModelLife::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelLife::Initiate() 
{
    //TODO Auto-generated method stub
	bool result = false;
	CInterface<ITcpSelectIOModel> segment_1;
	if( segment_1.Mount(this, IID_TCP_SELECT_IO_MODEL) ) {
		result = segment_1 -> Initiate();
	}

	CInterface<IThreadControl> segment_2;
	if( segment_2.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_2 -> OnBegin() && result;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelLife::Shutdown() 
{
    //TODO Auto-generated method stub
	bool result = false;
	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnClose();
	}

	CInterface<ITcpSelectIOModel> segment_2;
	if( segment_2.Mount(this, IID_TCP_SELECT_IO_MODEL) ) {
		result = segment_2 -> Shutdown() && result;
	}

	CInterface<IInstanceContainer> segment_3;
	if( segment_3.Mount(this, IID_INSTANCE_CONTAINER) ) {
		segment_3 -> RemoveAll();
	}
    return result;
}
