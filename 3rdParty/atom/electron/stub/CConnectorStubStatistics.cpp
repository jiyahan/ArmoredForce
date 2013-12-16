#include "CConnectorStubStatistics.h"
//Begin section for file CConnectorStubStatistics.cpp
//TODO: Add definitions that you want preserved
//End section for file CConnectorStubStatistics.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectorStubStatistics::CConnectorStubStatistics() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
large(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectorStubStatistics::~CConnectorStubStatistics() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectorStubStatistics::IncRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> IncRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectorStubStatistics::DecRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> DecRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectorStubStatistics::GetRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> GetRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
IInterface * electron::CConnectorStubStatistics::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectorStubStatistics::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectorStubStatistics::OnReadFrame(U64 origin, U64 reduce) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    plain.read_bytes += origin;
    final.read_bytes += reduce;
    plain.read_frame += 1;
    final.read_frame += 1;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectorStubStatistics::OnSendFrame(U64 origin, U64 reduce) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    plain.send_bytes += origin;
    final.send_bytes += reduce;
    plain.send_frame += 1;
    final.send_frame += 1;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectorStubStatistics::OnLongFrame(U64 value) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    large = atom_max( large, value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectorStubStatistics::GetStatistics(U64 & l, tagFlowStatistics & p, tagFlowStatistics & f) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    l = large;
    p = plain;
    f = final;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectorStubStatistics::Reset() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    large            = 0;
    plain.read_bytes = 0;
    plain.read_frame = 0;
    plain.send_bytes = 0;
    plain.send_frame = 0;
    final.read_bytes = 0;
    final.read_frame = 0;
    final.send_bytes = 0;
    final.send_frame = 0;
}
