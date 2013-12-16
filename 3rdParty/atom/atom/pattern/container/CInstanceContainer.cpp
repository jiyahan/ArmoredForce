#include "CInstanceContainer.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceContainerListener.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CInstanceContainer.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstanceContainer.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceContainer::CInstanceContainer() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceContainer::~CInstanceContainer() 
{
    //TODO Auto-generated method stub
    RemoveAll();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceContainer::OnInsertInstance(CObjectPtr & instance) 
{
    //TODO Auto-generated method stub
    CInterface<IInstanceContainerListener> listener;
    if( listener.Mount(this, IID_INSTANCE_CONTAINER_LISTENER) ) {
        listener -> OnInsertInstance( instance ); 
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceContainer::OnRemoveInstance(CObjectPtr & instance) 
{
    //TODO Auto-generated method stub
    CInterface<IInstanceContainerListener> listener;
    if( listener.Mount(this, IID_INSTANCE_CONTAINER_LISTENER) ) {
        listener -> OnRemoveInstance( instance ); 
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceContainer::IncRef() 
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
int atom::CInstanceContainer::DecRef() 
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
int atom::CInstanceContainer::GetRef() 
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
atom::IInterface * atom::CInstanceContainer::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceContainer::SetNest(IInterface * value) 
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
bool atom::CInstanceContainer::Insert(CObjectPtr & instance) 
{
    //TODO Auto-generated method stub
    bool result = false;
	if( instance )
	{
        size_t offset = 
            instance -> GetName() % CONTAINER_QUEUE;
		if( true == ( 
            result = instances[offset].Insert(instance) ) ) {
			OnInsertInstance( instance );
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CInstanceContainer::Obtain(U64 instance_name) 
{
    //TODO Auto-generated method stub
    size_t offset = instance_name % CONTAINER_QUEUE;
    return instances[offset].Obtain( instance_name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceContainer::Obtain(CU64Array & out) 
{
    //TODO Auto-generated method stub
    for( size_t i = 0; i < CONTAINER_QUEUE; ++ i ) {
        instances[i].Obtain( out );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceContainer::Inside(U64 instance_name) 
{
    //TODO Auto-generated method stub
    size_t offset = instance_name % CONTAINER_QUEUE;
    return instances[offset].Inside( instance_name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CInstanceContainer::Amount() 
{
    //TODO Auto-generated method stub
    U64 result = 0;
    for( size_t i = 0; i < CONTAINER_QUEUE; ++ i ) {
        result += instances[i].Amount();
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceContainer::Remove(U64 instance_name) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( instance_name )
    {
        // 计算位置；
        size_t offset = instance_name % CONTAINER_QUEUE;

        // 获取对象，并移除对象；
        CObjectPtr instance = 
            instances[offset].Obtain( instance_name );
    	if( instance )
    	{
	    	if( true == ( 
                result = instances[offset].Remove(instance_name) ) ) {
    		    OnRemoveInstance( instance );
            }
    	}
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceContainer::RemoveAll() 
{
    //TODO Auto-generated method stub
    CU64Array names; Obtain( names );
    for( size_t i = 0, j = names.size(); i < j; ++ i ) {
    	Remove( names[i] );
    }
}
