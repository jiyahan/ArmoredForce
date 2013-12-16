#include "CInstanceUtility.h"
#include "../tool/CInterface.h"
#include "../../pattern/factory/CInstanceFactory.h"
#include "../../pattern/life/CInstanceLife.h"
#include "../../interface/IReferencedObject.h"
#include "../../interface/IInstanceLife.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CInstanceUtility.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstanceUtility.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CInstanceUtility::CreateInstance(U32 type)
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CInstanceUtility::ObtainInstance(U64 name)
{
    //TODO Auto-generated method stub
	return CInstanceFactory::GetInstance() -> Inquire( name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceUtility::InitiateInstance(CObjectPtr & value)
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceUtility::ShutdownInstance(CObjectPtr & value)
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CInstanceUtility::GetInstanceName(IInterface * value) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CInstanceUtility::GetInstanceType(IInterface * value) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CInstanceUtility::GetInstanceDesc(IInterface * value) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CInstanceUtility::MakeObject(IInterface * nest)
{
    //TODO Auto-generated method stub
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
