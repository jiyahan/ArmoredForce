#include "CFlushableWrapper.h"
#include "../../interface/IExportStream.h"
#include "../../interface/IStream.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CFlushableWrapper.cpp
//TODO: Add definitions that you want preserved
//End section for file CFlushableWrapper.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CFlushableWrapper::CFlushableWrapper() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
bind(NULL),wrap(IID_UNKNOW)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CFlushableWrapper::~CFlushableWrapper() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFlushableWrapper::Verify() 
{
    //TODO Auto-generated method stub
    if( bind )
    {
        IInterface * unknow;
        unknow = bind -> QueryInterface( IID_EXPORT_STREAM );
        if( unknow )
        {
			/* not increase any reference, nest will do it */
            wrap = IID_EXPORT_STREAM;
			port.e = dynamic_cast<IExportStream *>( unknow );
            if( port.e ) port.e -> DecRef();
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
void atom::CFlushableWrapper::Attach(IInterface * value) 
{
    //TODO Auto-generated method stub
    /* not increase any reference, nest will do it */
    bind = value;
    wrap = IID_UNKNOW;
	port.Clear();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CFlushableWrapper::IncRef() 
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
int atom::CFlushableWrapper::DecRef() 
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
int atom::CFlushableWrapper::GetRef() 
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
atom::IInterface * atom::CFlushableWrapper::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFlushableWrapper::SetNest(IInterface * value) 
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
void atom::CFlushableWrapper::Flush() 
{
    //TODO Auto-generated method stub
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Flush();
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Flush();
        }
        break;
    }
}
