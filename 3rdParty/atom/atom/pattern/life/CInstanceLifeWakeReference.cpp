#include "CInstanceLifeWakeReference.h"
#include "../factory/CInstanceFactory.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../interface/IInstanceLifeNotifyReceiver.h"
#include "../../interface/IInstanceContainer.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CInstanceLifeWakeReference::CInstanceLifeWakeReference() 
{
}

atom::CInstanceLifeWakeReference::~CInstanceLifeWakeReference() 
{
}

bool atom::CInstanceLifeWakeReference::Insert(U64 instance, CObjectPtr & receiver) 
{
    bool result = false;
    if( instance )
    {
        // �����ٽ�����������ö��������λ�ã�
        CCriticalSectionScope scope( section );
        pair<CInstanceLifeWakeReferenceBind::iterator, 
            bool> retval = instances.insert( make_pair(instance, 0) );
        if( retval.second )
        {
			result = true;
			if( receiver )
			{
				// ����֪ͨ����ʵ���ɹ���
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

bool atom::CInstanceLifeWakeReference::Remove(U64 instance, CObjectPtr & receiver) 
{
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

            // �ɹ��ҵ����󣬲��Ҷ���������Ϊ0����ɾ��λ�ã�
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

int atom::CInstanceLifeWakeReference::Increase(U64 instance) 
{
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

int atom::CInstanceLifeWakeReference::Decrease(U64 instance) 
{
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

void atom::CInstanceLifeWakeReference::Clear(CObjectPtr & receiver) 
{
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

int atom::CInstanceLifeWakeReference::GetReference(U64 instance) 
{
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

void atom::CInstanceLifeWakeReference::GetInstances(CU64Array & indices) 
{
    CCriticalSectionScope scope( section );
    std::transform( instances.begin(), 
		instances.end(), back_inserter(indices), 
		atom::select1st<CInstanceLifeWakeReferenceBind::value_type>() );
}
