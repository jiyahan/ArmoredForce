#include "CTcpNetworkServiceController.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/IInstanceLife.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpNetworkServiceController.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpNetworkServiceController.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpNetworkServiceController::CTcpNetworkServiceController() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpNetworkServiceController::~CTcpNetworkServiceController() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpNetworkServiceController::IncRef() 
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
int atom::CTcpNetworkServiceController::DecRef() 
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
int atom::CTcpNetworkServiceController::GetRef() 
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
atom::IInterface * atom::CTcpNetworkServiceController::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpNetworkServiceController::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpNetworkServiceController::Initiate() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpNetworkServiceController::Shutdown() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CTcpNetworkServiceController::GetModel(U32 io_model) 
{
    //TODO Auto-generated method stub
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
