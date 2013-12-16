#include "CInstanceFactoryLife.h"
#include "../../maintainer/CMaintainer.h"
#include "../../interface/IInstanceFactoryEntry.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
//Begin section for file CInstanceFactoryLife.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstanceFactoryLife.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceFactoryLife::CInstanceFactoryLife() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceFactoryLife::~CInstanceFactoryLife() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceFactoryLife::IncRef() 
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
int atom::CInstanceFactoryLife::DecRef() 
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
int atom::CInstanceFactoryLife::GetRef() 
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
atom::IInterface * atom::CInstanceFactoryLife::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceFactoryLife::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceFactoryLife::Initiate() 
{
    //TODO Auto-generated method stub
	CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object ) {
	    CMaintainer::GetInstance() -> Attach( object );
    }
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceFactoryLife::Shutdown() 
{
    //TODO Auto-generated method stub
	CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object ) {
	    CMaintainer::GetInstance() -> Detach( object );
    }

	bool result = false;
	CInterface<IInstanceFactoryEntry> segment;
	if( segment.Mount(this, IID_INSTANCE_FACTORY_ENTRY) ) {
		result = segment -> Shutdown();
	}
	return result;
}
