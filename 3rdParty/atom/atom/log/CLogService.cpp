#include "CLogService.h"
#include "../maintainer/CMaintainer.h"
#include "../enumeration/SINGLETON_OBJECT_ID.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CLogService.cpp
//TODO: Add definitions that you want preserved
//End section for file CLogService.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLogService::CLogService()
{
    //TODO Auto-generated method stub
    controller.SetNest( this );
	maintainer.SetNest( this );
	life      .SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLogService::~CLogService() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogService::SetName(U64 name) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CLogService::GetName() 
{
    //TODO Auto-generated method stub
    return OID_LOG_SERVICE;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogService::SetType(U32 type) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( type );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CLogService::GetType() 
{
    //TODO Auto-generated method stub
    return OID_LOG_SERVICE;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CLogService::ToString() 
{
    //TODO Auto-generated method stub
	static char name[] = "Log Service";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CLogService::IncRef() 
{
    //TODO Auto-generated method stub
	return lock.Increase();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CLogService::DecRef() 
{
    //TODO Auto-generated method stub
    return lock.Decrease();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CLogService::GetRef() 
{
    //TODO Auto-generated method stub
    return lock.GetReference();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CLogService::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_LOG_SERVICE_CONTROLLER:
		if( controller.IncRef() )
			result = & controller;
        break;
	case IID_MAINTAINABLE:
		if( maintainer.IncRef() )
			result = & maintainer;
        break;
	case IID_INSTANCE_LIFE:
		if( life      .IncRef() )
			result = & life;
        break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CLogService::Initiate() 
{
    //TODO Auto-generated method stub
    return life.Initiate();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CLogService::Shutdown() 
{
    //TODO Auto-generated method stub
    return life.Shutdown();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogService::Attach(U08 display_level, IInterface * output) 
{
    //TODO Auto-generated method stub
    controller.Setup( display_level, output );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogService::Record(U08 level, const char * log) 
{
    //TODO Auto-generated method stub
    controller.Write( level, log );
}
