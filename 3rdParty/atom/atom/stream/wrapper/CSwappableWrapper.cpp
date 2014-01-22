#include "CSwappableWrapper.h"
#include "../../interface/IImportStream.h"
#include "../../interface/IExportStream.h"
#include "../../interface/IStream.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CSwappableWrapper::CSwappableWrapper() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif	
bind(NULL),wrap(IID_UNKNOW)
{
}

atom::CSwappableWrapper::~CSwappableWrapper() 
{
}

void atom::CSwappableWrapper::SetTarget(U32 iid) 
{
    wrap = iid;
}

void atom::CSwappableWrapper::Attach(IInterface * value) 
{
    /* not increase any reference, nest will do it */
    bind = value;
    wrap = IID_UNKNOW;
}

int atom::CSwappableWrapper::IncRef() 
{
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

int atom::CSwappableWrapper::DecRef() 
{
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

int atom::CSwappableWrapper::GetRef() 
{
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

atom::IInterface * atom::CSwappableWrapper::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CSwappableWrapper::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool atom::CSwappableWrapper::Swap(CMemory & data) 
{
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
