#include "CInstanceLifeEntry.h"
#include "../../maintainer/CMaintainer.h"
#include "../../interface/IInstanceLifeController.h"
#include "../../interface/IInstanceLifeReference.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
//Begin section for file CInstanceLifeEntry.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstanceLifeEntry.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLifeEntry::CInstanceLifeEntry() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLifeEntry::~CInstanceLifeEntry() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLifeEntry::IncRef() 
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
int atom::CInstanceLifeEntry::DecRef() 
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
int atom::CInstanceLifeEntry::GetRef() 
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
atom::IInterface * atom::CInstanceLifeEntry::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeEntry::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeEntry::Initiate() 
{
    //TODO Auto-generated method stub
	CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object ) {
	    CMaintainer::GetInstance() -> Attach( object );
    }

	bool result = true;
	CInterface<IInstanceLifeController> segment_1;
	if( segment_1.Mount(this, IID_INSTANCE_LIFE_CONTROLLER) ) {
		result = segment_1 -> Initiate() && result;
	}

	CInterface<IInstanceLifeReference>  segment_2;
	if( segment_2.Mount(this, IID_INSTANCE_LIFE_REFERENCE) ) {
		result = segment_2 -> Initiate() && result;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeEntry::Shutdown() 
{
    //TODO Auto-generated method stub
	CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object ) {
	    CMaintainer::GetInstance() -> Detach( object );
    }

	bool result = true;
	CInterface<IInstanceLifeReference>  segment_2;
	if( segment_2.Mount(this, IID_INSTANCE_LIFE_REFERENCE) ) {
		result = segment_2 -> Shutdown() && result;
	}

	CInterface<IInstanceLifeController> segment_1;
	if( segment_1.Mount(this, IID_INSTANCE_LIFE_CONTROLLER) ) {
		result = segment_1 -> Shutdown() && result;
	}
    return result;
}
