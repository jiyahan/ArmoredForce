#include "CExportArchive.h"
#include "../utility/charset/CUtf8Charset.h"
#include "../utility/tool/CInterface.h"
#include "../interface/IExportable.h"
#include "../enumeration/INTERFACE_ID.h"


atom::CExportArchive::CExportArchive() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

atom::CExportArchive::~CExportArchive() 
{
}

int atom::CExportArchive::IncRef() 
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

int atom::CExportArchive::DecRef() 
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

int atom::CExportArchive::GetRef() 
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

atom::IInterface * atom::CExportArchive::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CExportArchive::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

void atom::CExportArchive::Bind(bool & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( static_cast<U08>(value) );
    }
}

void atom::CExportArchive::Bind(char & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( static_cast<U08>(value) );
    }
}

void atom::CExportArchive::Bind(I08 & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

void atom::CExportArchive::Bind(I16 & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

void atom::CExportArchive::Bind(I32 & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

void atom::CExportArchive::Bind(I64 & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

void atom::CExportArchive::Bind(U08 & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

void atom::CExportArchive::Bind(U16 & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

void atom::CExportArchive::Bind(U32 & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

void atom::CExportArchive::Bind(U64 & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

void atom::CExportArchive::Bind(float & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

void atom::CExportArchive::Bind(double & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

void atom::CExportArchive::Bind(a_string & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) 
    {
        U08 flags = CUtf8Charset::IsUtf8( value.c_str() );
        segment -> Write( flags );
        segment -> Write( value.c_str() );
    }
}

void atom::CExportArchive::Bind(a_wstring & value) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( U08(true) );
        segment -> Write( value.c_str() );
    }
}

void atom::CExportArchive::Bind(void * buffer, U64 length) 
{
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( buffer, length );
    }
}
