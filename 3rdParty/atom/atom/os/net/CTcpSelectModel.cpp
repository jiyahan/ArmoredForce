#include "CTcpSelectModel.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpSelectModel.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpSelectModel.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpSelectModel::CTcpSelectModel()
{
    //TODO Auto-generated method stub
	model    .SetNest( this );
	thread   .SetNest( this );
	life     .SetNest( this );
	container.SetNest( this );
	listener .SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpSelectModel::~CTcpSelectModel() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CTcpSelectModel::ToString() 
{
    //TODO Auto-generated method stub
	static char name[] = "Tcp Select Model";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CTcpSelectModel::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    switch( iid )
    {
	case IID_INSTANCE_CONTAINER:
		if( container  .IncRef() )
			result = & container;
        break;
	case IID_INSTANCE_CONTAINER_LISTENER:
		if( listener   .IncRef() )
			result = & listener;
        break;
	case IID_INSTANCE_LIFE:
		if( life       .IncRef() )
			result = & life;
        break;
	case IID_THREAD_CONTROL:
		if( thread     .IncRef() )
			result = & thread;
        break;
	case IID_TCP_IO_MODEL:
	case IID_TCP_SELECT_IO_MODEL:
		if( model      .IncRef() )
			result = & model;
		break;
    }
    return result;
}
