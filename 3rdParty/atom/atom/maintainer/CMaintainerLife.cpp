#include "CMaintainerLife.h"
#include "../interface/IThreadControl.h"
#include "../interface/IInstanceContainer.h"
#include "../enumeration/INTERFACE_ID.h"
#include "../utility/tool/CInterface.h"
//Begin section for file CMaintainerLife.cpp
//TODO: Add definitions that you want preserved
//End section for file CMaintainerLife.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMaintainerLife::CMaintainerLife() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMaintainerLife::~CMaintainerLife() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CMaintainerLife::IncRef() 
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
int atom::CMaintainerLife::DecRef() 
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
int atom::CMaintainerLife::GetRef() 
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
atom::IInterface * atom::CMaintainerLife::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMaintainerLife::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMaintainerLife::Initiate() 
{
    //TODO Auto-generated method stub
	bool result = false;
	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnBegin();
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMaintainerLife::Shutdown() 
{
    //TODO Auto-generated method stub
	bool result = false;
	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnClose();
	}

	CInterface<IInstanceContainer> segment_2;
	if( segment_2.Mount(this, IID_INSTANCE_CONTAINER) ) {
		segment_2 -> RemoveAll();
	}
    return result;
}
