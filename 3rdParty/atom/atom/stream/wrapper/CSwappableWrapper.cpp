#include "CSwappableWrapper.h"
#include "../../interface/IImportStream.h"
#include "../../interface/IExportStream.h"
#include "../../interface/IStream.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CSwappableWrapper.cpp
//TODO: Add definitions that you want preserved
//End section for file CSwappableWrapper.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CSwappableWrapper::CSwappableWrapper() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif	
bind(NULL),wrap(IID_UNKNOW)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CSwappableWrapper::~CSwappableWrapper() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CSwappableWrapper::SetTarget(U32 iid) 
{
    //TODO Auto-generated method stub
    wrap = iid;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CSwappableWrapper::Attach(IInterface * value) 
{
    //TODO Auto-generated method stub
    /* not increase any reference, nest will do it */
    bind = value;
    wrap = IID_UNKNOW;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CSwappableWrapper::IncRef() 
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
int atom::CSwappableWrapper::DecRef() 
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
int atom::CSwappableWrapper::GetRef() 
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
atom::IInterface * atom::CSwappableWrapper::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CSwappableWrapper::SetNest(IInterface * value) 
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
bool atom::CSwappableWrapper::Swap(CMemory & data) 
{
    //TODO Auto-generated method stub
    if( !bind ) return false;

    bool result = false;
    IInterface * unknow = bind -> QueryInterface( wrap );
    if( unknow )
    {
        switch( wrap )
        {
        case IID_IMPORT_STREAM:
            {
                IImportStream * stream = 
                    dynamic_cast<IImportStream *>( unknow );
                if( stream ) {
                    result = stream -> Swap( data );
                }
            }
            break;
        case IID_EXPORT_STREAM:
            {
                IExportStream * stream = 
                    dynamic_cast<IExportStream *>( unknow );
                if( stream ) {
                    result = stream -> Swap( data );
                }
            }
            break;
        case IID_STREAM:
            {
                IStream * stream = dynamic_cast<IStream *>( unknow );
                if( stream ) {
                    result = stream -> Swap( data );
                }
            }
            break;
        }

        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( unknow );
        SAFE_DECREF( refered );
    }
    return result;
}
