#include "CAssignableWrapper.h"
#include "../../interface/IImportStream.h"
#include "../../interface/IStream.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CAssignableWrapper.cpp
//TODO: Add definitions that you want preserved
//End section for file CAssignableWrapper.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CAssignableWrapper::CAssignableWrapper() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
bind(NULL),wrap(IID_UNKNOW)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CAssignableWrapper::~CAssignableWrapper() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAssignableWrapper::Verify() 
{
    //TODO Auto-generated method stub
    if( bind )
    {
        IInterface * unknow;
        unknow = bind -> QueryInterface( IID_IMPORT_STREAM );
        if( unknow )
        {
		    /* not increase any reference, nest will do it */
            wrap = IID_IMPORT_STREAM;
			port.i = dynamic_cast<IImportStream *>( unknow );
            if( port.i ) port.i -> DecRef();
            return;
        }

        unknow = bind -> QueryInterface( IID_STREAM );
        if( unknow )
        {
			/* not increase any reference, nest will do it */
            wrap = IID_STREAM;
			port.s = dynamic_cast<IStream *>( unknow );
            if( port.s ) port.s -> DecRef();
        }        
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAssignableWrapper::Attach(IInterface * value) 
{
    //TODO Auto-generated method stub
    /* not increase any reference, nest will do it */
    bind = value;
    wrap = IID_UNKNOW;
	port.Clear();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CAssignableWrapper::IncRef() 
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
int atom::CAssignableWrapper::DecRef() 
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
int atom::CAssignableWrapper::GetRef() 
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
atom::IInterface * atom::CAssignableWrapper::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAssignableWrapper::SetNest(IInterface * value) 
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
bool atom::CAssignableWrapper::Assign(CMemory & data) 
{
    //TODO Auto-generated method stub
    if( !bind ) return false;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    bool result = false;
    switch( wrap )
    {
    case IID_IMPORT_STREAM:
		if( port.i ) {
			result = port.i -> Assign( data );
		}
        break;
    case IID_STREAM:
		if( port.s ) {
	        result = port.s -> Assign( data );
		}
        break;
    }
    return result;
}
