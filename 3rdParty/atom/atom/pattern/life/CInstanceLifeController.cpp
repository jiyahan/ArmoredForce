#include "CInstanceLifeController.h"
#include "../factory/CInstanceFactory.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceLifeReference.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CInstanceLifeController::CInstanceLifeController() : 
nest(NULL)
{
}

atom::CInstanceLifeController::~CInstanceLifeController() 
{
}

int atom::CInstanceLifeController::IncRef() 
{
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

int atom::CInstanceLifeController::DecRef() 
{
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

int atom::CInstanceLifeController::GetRef() 
{
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

atom::IInterface * atom::CInstanceLifeController::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CInstanceLifeController::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

U64 atom::CInstanceLifeController::Create(U32 type) 
{
	U64 result = 0;
	if( type )
	{
        CInterface<IInstanceLifeReference> segment;
		if( segment.Mount(this, IID_INSTANCE_LIFE_REFERENCE) )
        {
    	    result = CInstanceFactory::GetInstance() -> Product( type );
    	    if( result )
    	    {
                // 如果成功，则在移除时间轴上注册该对象；
                if( segment -> Insert(result) ) {
					Remove( result, 120000 );
                }

                // 如果失败，则销毁实例；
                else
				{
                    CInstanceFactory::GetInstance() -> Destroy( result );
					result = 0;
                }
            }
    	}
	}
	return result;
}

bool atom::CInstanceLifeController::Remove(U64 instance, U64 time) 
{
	if( instance ) {
		remove.Insert( CMilisecondTimer::Now() + time, instance );
	}
	return true;
}

bool atom::CInstanceLifeController::Remove(CU64Array & instances, U64 time) 
{
	for( size_t i = 0, j = instances.size(); i < j; ++ i ) {
		Remove( instances[i], time );
	}
    return true;
}

void atom::CInstanceLifeController::Delete(U64 instance) 
{
    if( instance )
    {
		// 移除实例
        CInterface<IInstanceLifeReference> segment;
		if( segment.Mount(this, IID_INSTANCE_LIFE_REFERENCE) )
        {
            // 如果引用为0，则注销实例，并删除弱引用计数；
            if( segment -> Remove(instance) )
            {
                // 通知工厂删除实例；
				CInstanceFactory::GetInstance() -> Destroy( instance );
            }
        }
    }
}

void atom::CInstanceLifeController::Delete(CU64Array & instances) 
{
    CInterface<IInstanceLifeReference> segment;
	if( segment.Mount(this, IID_INSTANCE_LIFE_REFERENCE) )
    {
        // 如果引用为0，则注销实例，并删除弱引用计数；
		for( size_t i = 0, j = instances.size(); i < j; ++ i )
		{
			// 如果移除成功，则通知工厂删除实例；
			if( segment -> Remove(instances[i]) ) {
				CInstanceFactory::GetInstance() -> Destroy( instances[i] );
			}
		}
    }
}

void atom::CInstanceLifeController::OnProcess(U64 time) 
{
	CU64Array indices;
	remove.Obtain( time, indices );
	if( !indices.empty() ) Delete( indices );
}

bool atom::CInstanceLifeController::Initiate() 
{
	return true;
}

bool atom::CInstanceLifeController::Shutdown() 
{
	remove.Clear();
	return true;
}
