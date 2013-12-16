#include "CEventSpaceLife.h"
#include "../../interface/IEventSpaceController.h"
#include "../../interface/IInstanceContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"
//Begin section for file CEventSpaceLife.cpp
//TODO: Add definitions that you want preserved
//End section for file CEventSpaceLife.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventSpaceLife::CEventSpaceLife() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventSpaceLife::~CEventSpaceLife() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CEventSpaceLife::IncRef() 
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
int atom::CEventSpaceLife::DecRef() 
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
int atom::CEventSpaceLife::GetRef() 
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
atom::IInterface * atom::CEventSpaceLife::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventSpaceLife::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventSpaceLife::Initiate() 
{
    //TODO Auto-generated method stub
	bool result = false;
	CInterface<IEventSpaceController> segment;
	if( segment.Mount(this, IID_EVENT_SPACE_CONTROLLER) ) {
		result = segment -> Initiate();
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventSpaceLife::Shutdown() 
{
    //TODO Auto-generated method stub
	bool result = false;
	CInterface<IEventSpaceController> segment_1;
	if( segment_1.Mount(this, IID_EVENT_SPACE_CONTROLLER) ) {
		result = segment_1 -> Shutdown();
	}

	CInterface<IInstanceContainer> segment_2;
	if( segment_2.Mount(this, IID_INSTANCE_CONTAINER) ) {
		segment_2 -> RemoveAll();
	}
	return result;
}
