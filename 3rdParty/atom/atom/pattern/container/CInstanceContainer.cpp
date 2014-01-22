#include "CInstanceContainer.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceContainerListener.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CInstanceContainer::CInstanceContainer() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

atom::CInstanceContainer::~CInstanceContainer() 
{
    RemoveAll();
}

void atom::CInstanceContainer::OnInsertInstance(CObjectPtr & instance) 
{
    CInterface<IInstanceContainerListener> listener;
    if( listener.Mount(this, IID_INSTANCE_CONTAINER_LISTENER) ) {
        listener -> OnInsertInstance( instance ); 
	}
}

void atom::CInstanceContainer::OnRemoveInstance(CObjectPtr & instance) 
{
    CInterface<IInstanceContainerListener> listener;
    if( listener.Mount(this, IID_INSTANCE_CONTAINER_LISTENER) ) {
        listener -> OnRemoveInstance( instance ); 
	}
}

int atom::CInstanceContainer::IncRef() 
{
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

int atom::CInstanceContainer::DecRef() 
{
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

int atom::CInstanceContainer::GetRef() 
{
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

atom::IInterface * atom::CInstanceContainer::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CInstanceContainer::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool atom::CInstanceContainer::Insert(CObjectPtr & instance) 
{
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

atom::CObjectPtr atom::CInstanceContainer::Obtain(U64 instance_name) 
{
    size_t offset = instance_name % CONTAINER_QUEUE;
    return instances[offset].Obtain( instance_name );
}

void atom::CInstanceContainer::Obtain(CU64Array & out) 
{
    for( size_t i = 0; i < CONTAINER_QUEUE; ++ i ) {
        instances[i].Obtain( out );
    }
}

bool atom::CInstanceContainer::Inside(U64 instance_name) 
{
    size_t offset = instance_name % CONTAINER_QUEUE;
    return instances[offset].Inside( instance_name );
}

U64 atom::CInstanceContainer::Amount() 
{
    U64 result = 0;
    for( size_t i = 0; i < CONTAINER_QUEUE; ++ i ) {
        result += instances[i].Amount();
    }
    return result;
}

bool atom::CInstanceContainer::Remove(U64 instance_name) 
{
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

void atom::CInstanceContainer::RemoveAll() 
{
    CU64Array names; Obtain( names );
    for( size_t i = 0, j = names.size(); i < j; ++ i ) {
    	Remove( names[i] );
    }
}
