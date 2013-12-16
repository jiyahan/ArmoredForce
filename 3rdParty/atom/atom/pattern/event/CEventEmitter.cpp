#include "CEventEmitter.h"
#include "CEventService.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/IEventSpaceController.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../enumeration/OBJECT_ID.h"
//Begin section for file CEventEmitter.cpp
//TODO: Add definitions that you want preserved
//End section for file CEventEmitter.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventEmitter::CEventEmitter() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
node(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventEmitter::~CEventEmitter() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CEventEmitter::IncRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> IncRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CEventEmitter::DecRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> DecRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CEventEmitter::GetRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> GetRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CEventEmitter::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventEmitter::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventEmitter::Attach(U64 space) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( node == 0 && space ) {
		node = space; result = true;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventEmitter::Attach(CObjectPtr & object) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( object &&
		object -> GetType() == OID_EVENT_SPACE ) 
	{
		result = Attach( object -> GetName() );
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventEmitter::Detach() 
{
    //TODO Auto-generated method stub
    node = 0;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventEmitter::Report(const tagEvent & value) 
{
    //TODO Auto-generated method stub
	bool result = false; U64 space = node;
	if( space )
	{
		CInterface<IInstanceContainer> segment_1;
		if( segment_1.Mount( CEventService::GetInstance(), IID_INSTANCE_CONTAINER ) )
		{
			CObjectPtr object = segment_1 -> Obtain( space );
			if( object )
			{
				CInterface<IEventSpaceController> segment_2;
				if( segment_2.Mount(object, IID_EVENT_SPACE_CONTROLLER) ) {
                    result = segment_2 -> OnEvent( value );
				}
			}
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventEmitter::Report(const char * target, const tagEvent & value) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( target )
	{
		tagEvent e( value ); e.target = target;
		result = Report( e );
	}
	return result;
}
