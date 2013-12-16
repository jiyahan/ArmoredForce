#include "CEventService.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../enumeration/SINGLETON_OBJECT_ID.h"
//Begin section for file CEventService.cpp
//TODO: Add definitions that you want preserved
//End section for file CEventService.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventService::CEventService() 
{
    //TODO Auto-generated method stub
	thread   .SetNest( this );
	container.SetNest( this );
	timeline .SetNest( this );
	entry    .SetNest( this );
	life     .SetNest( this );
	listener .SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventService::~CEventService() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventService::SetName(U64 name) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CEventService::GetName() 
{
    //TODO Auto-generated method stub
	return OID_EVENT_SERVICE;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventService::SetType(U32 type) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( type );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CEventService::GetType() 
{
    //TODO Auto-generated method stub
	return OID_EVENT_SERVICE;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CEventService::ToString() 
{
    //TODO Auto-generated method stub
	static char name[] = "Event Service";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CEventService::IncRef() 
{
    //TODO Auto-generated method stub
	return counter.Increase();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CEventService::DecRef() 
{
    //TODO Auto-generated method stub
	return counter.Decrease();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CEventService::GetRef() 
{
    //TODO Auto-generated method stub
	return counter.GetReference();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CEventService::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_INSTANCE_CONTAINER:
		if( container.IncRef() )
			result = & container;
        break;
    case IID_INSTANCE_CONTAINER_LISTENER:
		if( listener .IncRef() )
			result = & listener;
        break;
	case IID_EVENT_SERVICE_TIMELINE:
		if( timeline .IncRef() )
			result = & timeline;
        break;
	case IID_INSTANCE_LIFE:
		if( life     .IncRef() )
			result = & life;
		break;
	case IID_THREAD_CONTROL:
		if( thread   .IncRef() )
			result = & thread;
		break;
	case IID_EVENT_SERVICE_ENTRY:
		if( entry    .IncRef() )
			result = & entry;
		break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CEventService::Create() 
{
    //TODO Auto-generated method stub
	return entry.Create();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventService::Remove(U64 name) 
{
    //TODO Auto-generated method stub
	entry.Remove( name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventService::Notify(U64 name) 
{
    //TODO Auto-generated method stub
	timeline.Mark( CMilisecondTimer::Now(), name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventService::Initiate() 
{
    //TODO Auto-generated method stub
	return life.Initiate();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventService::Shutdown() 
{
    //TODO Auto-generated method stub
	return life.Shutdown();
}
