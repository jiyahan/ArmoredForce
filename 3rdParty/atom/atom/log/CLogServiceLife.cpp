#include "CLogServiceLife.h"
#include "../maintainer/CMaintainer.h"
#include "../interface/ILogServiceController.h"
#include "../enumeration/INTERFACE_ID.h"
#include "../utility/tool/CInterface.h"
#include "../utility/tool/CInstanceUtility.h"
//Begin section for file CLogServiceLife.cpp
//TODO: Add definitions that you want preserved
//End section for file CLogServiceLife.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLogServiceLife::CLogServiceLife() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLogServiceLife::~CLogServiceLife() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CLogServiceLife::IncRef() 
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
int atom::CLogServiceLife::DecRef() 
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
int atom::CLogServiceLife::GetRef() 
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
atom::IInterface * atom::CLogServiceLife::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogServiceLife::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CLogServiceLife::Initiate() 
{
    //TODO Auto-generated method stub
    CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object ) {
	    CMaintainer::GetInstance() -> Attach( object );
    }
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CLogServiceLife::Shutdown() 
{
    //TODO Auto-generated method stub
    CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object ) {
	    CMaintainer::GetInstance() -> Detach( object );
    }

    CInterface<ILogServiceController> segment;
    if( segment.Mount(this, IID_LOG_SERVICE_CONTROLLER) ) {
        segment -> Flush();
        segment -> Clear();
    }
    return true;
}
