#include "CInstanceUtility.h"
#include "../tool/CInterface.h"
#include "../../pattern/factory/CInstanceFactory.h"
#include "../../pattern/life/CInstanceLife.h"
#include "../../interface/IReferencedObject.h"
#include "../../interface/IInstanceLife.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CObjectPtr atom::CInstanceUtility::CreateInstance(U32 type)
{
	CObjectPtr result;
    if( type )
    {
	    U64 name = CInstanceLife::GetInstance() -> Create( type );
	    if( name ) {
		    result = CInstanceFactory::GetInstance() -> Inquire( name );
	    }
    }
	return result;
}

atom::CObjectPtr atom::CInstanceUtility::ObtainInstance(U64 name)
{
	return CInstanceFactory::GetInstance() -> Inquire( name );
}

bool atom::CInstanceUtility::InitiateInstance(CObjectPtr & value)
{
	bool result = false;
    if( value )
    {
	    CInterface<IInstanceLife> life;
	    if( life.Mount(value, IID_INSTANCE_LIFE) ) 
	    {
		    // initiate instance life;
		    result = life -> Initiate();

		    // if failed, shutdown instance life;
		    if( !result ) {
			    ShutdownInstance( value );
		    }
	    }
    }
	return result;
}

bool atom::CInstanceUtility::ShutdownInstance(CObjectPtr & value)
{
	bool result = false;
    if( value )
    {
	    CInterface<IInstanceLife> life;
	    if( life.Mount(value, IID_INSTANCE_LIFE) ) {
		    result = life -> Shutdown();
	    }
    }
	return result;
}

U64 atom::CInstanceUtility::GetInstanceName(IInterface * value) 
{
	U64 result = 0;
	if( value )
	{
		IReferencedObject * refered = 
            dynamic_cast<IReferencedObject *>( value );
        if( refered ) {
			result = refered -> GetName();
		}
	}
	return result;
}

U32 atom::CInstanceUtility::GetInstanceType(IInterface * value) 
{
	U32 result = 0;
	if( value )
	{
		IReferencedObject * refered = 
            dynamic_cast<IReferencedObject *>( value );
        if( refered ) {
			result = refered -> GetType();
		}
	}
	return result;
}

const char * atom::CInstanceUtility::GetInstanceDesc(IInterface * value) 
{
	const char * result = NULL;
	if( value )
	{
		IReferencedObject * refered = 
            dynamic_cast<IReferencedObject *>( value );
        if( refered ) {
			result = refered -> ToString();
		}
	}
	return result;
}

atom::CObjectPtr atom::CInstanceUtility::MakeObject(IInterface * nest)
{
    CObjectPtr result;
    if( nest )
    {
        IReferencedObject * refer =
            dynamic_cast<IReferencedObject *>( nest );
        if( refer ) {
            result = refer;
        }
    }
    return result;
}
