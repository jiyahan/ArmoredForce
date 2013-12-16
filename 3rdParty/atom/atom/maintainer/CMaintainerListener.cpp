#include "CMaintainerListener.h"
#include "../pattern/life/CInstanceLife.h"
#include "../os/timer/CMilisecondTimer.h"
#include "../utility/tool/CInterface.h"
#include "../interface/IMaintainerTimeline.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CMaintainerListener.cpp
//TODO: Add definitions that you want preserved
//End section for file CMaintainerListener.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMaintainerListener::CMaintainerListener() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMaintainerListener::~CMaintainerListener() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CMaintainerListener::IncRef() 
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
int atom::CMaintainerListener::DecRef() 
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
int atom::CMaintainerListener::GetRef() 
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
atom::IInterface * atom::CMaintainerListener::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMaintainerListener::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMaintainerListener::OnInsertInstance(CObjectPtr & instance) 
{
    //TODO Auto-generated method stub
    if( instance )
    {
		CInstanceLife::GetInstance() -> Increase( instance -> GetName() );

        CInterface<IMaintainerTimeline> timeline;
        if( timeline.Mount(this, IID_MAINTAINER_TIMELINE) ) {
            timeline -> Mark( CMilisecondTimer::Now(), instance -> GetName() );
        }
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMaintainerListener::OnRemoveInstance(CObjectPtr & instance) 
{
    //TODO Auto-generated method stub
	if( instance )
	{
		CInstanceLife::GetInstance() -> Decrease( instance -> GetName() );
	}
}
