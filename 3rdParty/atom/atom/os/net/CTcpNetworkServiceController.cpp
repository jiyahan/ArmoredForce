#include "CTcpNetworkServiceController.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/IInstanceLife.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpNetworkServiceController::CTcpNetworkServiceController() : 
nest(NULL)
{
}

atom::CTcpNetworkServiceController::~CTcpNetworkServiceController() 
{
}

int atom::CTcpNetworkServiceController::IncRef() 
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

int atom::CTcpNetworkServiceController::DecRef() 
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

int atom::CTcpNetworkServiceController::GetRef() 
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

atom::IInterface * atom::CTcpNetworkServiceController::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpNetworkServiceController::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CTcpNetworkServiceController::Initiate() 
{
    return true;
}

bool atom::CTcpNetworkServiceController::Shutdown() 
{
	CInterface<IInstanceContainer> segment;
	if( segment.Mount(this, IID_INSTANCE_CONTAINER) )
	{
		CCriticalSectionScope scope( section );
		for( CTcpNetworkServiceControllerBind::
			iterator it = mapping.begin(); it != mapping.end(); ++ it )
		{
			// query io model object
			CObjectPtr object = segment -> Obtain( it -> second );
			if( object == NULL ) {
				continue;
			}

			// first, shutdown io model's life, for existed 
			// connector can normally shutdown;
			CInstanceUtility::ShutdownInstance( object );

			// after shutdown, remove from container;
			segment -> Remove( object -> GetName() );
		}
	}
    return true;
}

atom::CObjectPtr atom::CTcpNetworkServiceController::GetModel(U32 io_model) 
{
	CObjectPtr result = NULL;
	if( io_model )
	{
		CInterface<IInstanceContainer> segment;
		if( segment.Mount(this, IID_INSTANCE_CONTAINER) )
		{
			CCriticalSectionScope scope( section );

			CTcpNetworkServiceControllerBind::
				iterator it = mapping.find( io_model );
			if( it != mapping.end() ) {
				result = segment -> Obtain( it -> second );
			}

			// if not exist, create a io model and initiate;
			else
			{
				bool succeed = false;
				result = CInstanceUtility::CreateInstance( io_model );

				// if succeed, initiate io model;
				if( result )
				{
					if( CInstanceUtility::InitiateInstance(result) ) {
						succeed = segment -> Insert( result );
					}
				}

				// if failed, reset result;
				if( succeed == false ) result = NULL;

				// insert into io model mapping;
				if( result ) {
					mapping.insert( make_pair(io_model, result -> GetName() ) );
				}
			}
		}
	}
	return result;
}
