#include "CEventServiceEntry.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInstanceContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../enumeration/OBJECT_ID.h"
//Begin section for file CEventServiceEntry.cpp
//TODO: Add definitions that you want preserved
//End section for file CEventServiceEntry.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventServiceEntry::CEventServiceEntry() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventServiceEntry::~CEventServiceEntry() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CEventServiceEntry::IncRef() 
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
int atom::CEventServiceEntry::DecRef() 
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
int atom::CEventServiceEntry::GetRef() 
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
atom::IInterface * atom::CEventServiceEntry::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventServiceEntry::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CEventServiceEntry::Create() 
{
    //TODO Auto-generated method stub
	U64 result = 0;
	CObjectPtr instance = 
		CInstanceUtility::CreateInstance( OID_EVENT_SPACE );
	if( instance )
	{
		if( CInstanceUtility::InitiateInstance(instance) )
		{
			CInterface<IInstanceContainer> container;
			if( container.Mount(this, IID_INSTANCE_CONTAINER) )
			{
				if( container -> Insert(instance) ) {
					result = instance -> GetName();
				}
			}
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventServiceEntry::Remove(U64 space) 
{
    //TODO Auto-generated method stub
	if( space )
	{
		CInterface<IInstanceContainer> container;
		if( container.Mount(this, IID_INSTANCE_CONTAINER) )
		{
			CObjectPtr instance = container -> Obtain( space );
			if( instance )
			{
				// remove space from container;
				container -> Remove( space );

				// before life service destroy instance, invoke shutdown
				// method, do final clear;
				CInterface<IInstanceLife> life;
				if( life.Mount(instance, IID_INSTANCE_LIFE) ) {
					life -> Shutdown();
				}
			}
		}
	}
}
