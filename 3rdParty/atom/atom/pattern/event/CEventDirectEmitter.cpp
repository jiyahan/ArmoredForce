#include "CEventDirectEmitter.h"
#include "../factory/CInstanceFactory.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../interface/IEventReceiver.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CEventDirectEmitter.cpp
//TODO: Add definitions that you want preserved
//End section for file CEventDirectEmitter.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventDirectEmitter::CEventDirectEmitter() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventDirectEmitter::~CEventDirectEmitter() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CEventDirectEmitter::IncRef() 
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
int atom::CEventDirectEmitter::DecRef() 
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
int atom::CEventDirectEmitter::GetRef() 
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
atom::IInterface * atom::CEventDirectEmitter::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventDirectEmitter::SetNest(IInterface * value) 
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
bool atom::CEventDirectEmitter::Attach(U64 object) 
{
    //TODO Auto-generated method stub
	CObjectPtr instance = CInstanceFactory::GetInstance() -> Inquire( object );
	return Attach( instance );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventDirectEmitter::Attach(CObjectPtr & object) 
{
    //TODO Auto-generated method stub
	bool result = false;
	CCriticalSectionScope scope( section );
	if( object && node == NULL ) {
		node = object; result = true;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventDirectEmitter::Detach() 
{
    //TODO Auto-generated method stub
	CCriticalSectionScope scope( section );
    node = NULL;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventDirectEmitter::Report(const tagEvent & value) 
{
    //TODO Auto-generated method stub
	bool result = false; 
	CCriticalSectionScope scope( section );
	if( node )
	{
		CInterface<IEventReceiver> segment;
		if( segment.Mount(node, IID_EVENT_RECEIVER) ) {
			result = segment -> OnEvent( value );
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventDirectEmitter::Report(const char * target, const tagEvent & value) 
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
