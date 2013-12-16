#include "CEventServiceLife.h"
#include "../../interface/IThreadControl.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/IEventServiceEntry.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"
//Begin section for file CEventServiceLife.cpp
//TODO: Add definitions that you want preserved
//End section for file CEventServiceLife.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventServiceLife::CEventServiceLife() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventServiceLife::~CEventServiceLife() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CEventServiceLife::IncRef() 
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
int atom::CEventServiceLife::DecRef() 
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
int atom::CEventServiceLife::GetRef() 
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
atom::IInterface * atom::CEventServiceLife::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventServiceLife::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventServiceLife::Initiate() 
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
bool atom::CEventServiceLife::Shutdown() 
{
    //TODO Auto-generated method stub
	bool result = false;
	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnClose();
	}

	CInterface<IInstanceContainer> segment_2;
	if( segment_2.Mount(this, IID_INSTANCE_CONTAINER) ) 
	{
		CInterface<IEventServiceEntry> segment_3;
		if( segment_3.Mount(this, IID_EVENT_SERVICE_ENTRY) )
		{
			CU64Array indices;
			segment_2 -> Obtain( indices );

			for( size_t i = 0, j = indices.size(); i < j; ++ i ) {
				segment_3 -> Remove( indices[i] );
			}
		}

		segment_2 -> RemoveAll();
	}
    return result;
}
