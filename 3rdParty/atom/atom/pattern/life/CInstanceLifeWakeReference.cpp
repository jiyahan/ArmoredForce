#include "CInstanceLifeWakeReference.h"
#include "../factory/CInstanceFactory.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../interface/IInstanceLifeNotifyReceiver.h"
#include "../../interface/IInstanceContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CInstanceLifeWakeReference.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstanceLifeWakeReference.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLifeWakeReference::CInstanceLifeWakeReference() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLifeWakeReference::~CInstanceLifeWakeReference() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeWakeReference::Insert(U64 instance, CObjectPtr & receiver) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( instance )
    {
        // 进入临界区，并插入该对象的引用位置；
        CCriticalSectionScope scope( section );
        pair<CInstanceLifeWakeReferenceBind::iterator, 
            bool> retval = instances.insert( make_pair(instance, 0) );
        if( retval.second )
        {
			result = true;
			if( receiver )
			{
				// 尝试通知创建实例成功；
				CInterface<IInstanceLifeNotifyReceiver> segment;
				if( segment.Mount(receiver, IID_INSTANCE_LIFE_NOTIFY_RECEIVER) ) {
					result = segment -> OnCreateInstance( instance );
				}
			}

            if( !result ) 
            {
                instances.erase( retval.first );

				// show message;
            }
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeWakeReference::Remove(U64 instance, CObjectPtr & receiver) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( instance )
    {
        CCriticalSectionScope scope( section );
        CInstanceLifeWakeReferenceBind::
            iterator it = instances.find( instance );
        if( it != instances.end() && it -> second == 0 )
        {
			result = true;
			if( receiver )
			{
				CInterface<IInstanceLifeNotifyReceiver> segment;
				if( segment.Mount(receiver, IID_INSTANCE_LIFE_NOTIFY_RECEIVER) ) {
					result = segment -> OnRemoveInstance( instance );
				}
			}

            // 成功找到对象，并且对象弱引用为0；则删除位置；
            if( result ) instances.erase( it ); 
        }

        // if succeeded, remove all child object in container;
        if( result )
        {
			CObjectPtr object =
				CInstanceFactory::GetInstance() -> Inquire( instance );
			if( object )
			{
				CInterface<IInstanceContainer> segment;
				if( segment.Mount(object, IID_INSTANCE_CONTAINER) ) {
					segment -> RemoveAll();
				}
			}
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLifeWakeReference::Increase(U64 instance) 
{
    //TODO Auto-generated method stub
    int result = 0;
    if( instance )
    {
    	CCriticalSectionScope scope( section );
        CInstanceLifeWakeReferenceBind::
            iterator it = instances.find( instance );
    	if( it != instances.end() )
    	{
    		result = ( ++ (it -> second) );
    	}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLifeWakeReference::Decrease(U64 instance) 
{
    //TODO Auto-generated method stub
    int result = 0;
    if( instance )
    {
    	CCriticalSectionScope scope( section );
        CInstanceLifeWakeReferenceBind::
            iterator it = instances.find( instance );
    	if( it != instances.end() )
    	{
    		result = ( -- (it -> second) );
    	}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeWakeReference::Clear(CObjectPtr & receiver) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
	if( receiver )
	{
		CInterface<IInstanceLifeNotifyReceiver> segment;
		if( segment.Mount(receiver, IID_INSTANCE_LIFE_NOTIFY_RECEIVER) )
		{
			for( CInstanceLifeWakeReferenceBind::
				iterator it = instances.begin(); it != instances.end(); ++ it )
			{
				segment -> OnRemoveInstance( it -> first );
			}
		}
	}
    instances.clear();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLifeWakeReference::GetReference(U64 instance) 
{
    //TODO Auto-generated method stub
    int result = 0;
    if( instance )
    {
    	CCriticalSectionScope scope( section );
        CInstanceLifeWakeReferenceBind::
            iterator it = instances.find( instance );
    	if( it != instances.end() )
    	{
    		result = it -> second;
    	}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeWakeReference::GetInstances(CU64Array & indices) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    std::transform( instances.begin(), 
		instances.end(), back_inserter(indices), 
		atom::select1st<CInstanceLifeWakeReferenceBind::value_type>() );
}
