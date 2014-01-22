#include "CExportableWrapper.h"
#include "../../interface/IExportStream.h"
#include "../../interface/IStream.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/byteswap/CByteSwap.h"
#include "../../utility/charset/CUtf8Charset.h"
#include "../../os/character/CCharacter.h"


atom::CExportableWrapper::CExportableWrapper() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
bind(NULL),wrap(IID_UNKNOW)
{
}

atom::CExportableWrapper::~CExportableWrapper() 
{
}

void atom::CExportableWrapper::Verify() 
{
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

void atom::CExportableWrapper::Attach(IInterface * value) 
{
    /* not increase any reference, nest will do it */
    bind = value;
    wrap = IID_UNKNOW;
	port.Clear(); 
}

int atom::CExportableWrapper::IncRef() 
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

int atom::CExportableWrapper::DecRef() 
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

int atom::CExportableWrapper::GetRef() 
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

atom::IInterface * atom::CExportableWrapper::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CExportableWrapper::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

void atom::CExportableWrapper::Write(I08 value) 
{
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Write( & value, sizeof(I08) );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Write( & value, sizeof(I08) );
        }
        break;
    }
}

void atom::CExportableWrapper::Write(I16 value) 
{
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    I16 data = CByteSwap::hton( value );
    
	switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Write( & data, sizeof(I16) );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Write( & data, sizeof(I16) );
        }
        break;
    }
}

void atom::CExportableWrapper::Write(I32 value) 
{
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    I32 data = CByteSwap::hton( value );
    
	switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Write( & data, sizeof(I32) );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Write( & data, sizeof(I32) );
        }
        break;
    }
}

void atom::CExportableWrapper::Write(I64 value) 
{
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    I64 data = CByteSwap::hton( value );
    
	switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Write( & data, sizeof(I64) );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Write( & data, sizeof(I64) );
        }
        break;
    }
}

void atom::CExportableWrapper::Write(U08 value) 
{
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

	switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Write( & value, sizeof(U08) );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Write( & value, sizeof(U08) );
        }
        break;
    }
}

void atom::CExportableWrapper::Write(U16 value) 
{
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    U16 data = CByteSwap::hton( value );
    
	switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Write( & data, sizeof(U16) );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Write( & data, sizeof(U16) );
        }
        break;
    }
}

void atom::CExportableWrapper::Write(U32 value) 
{
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    U32 data = CByteSwap::hton( value );
    
	switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Write( & data, sizeof(U32) );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Write( & data, sizeof(U32) );
        }
        break;
    }
}

void atom::CExportableWrapper::Write(U64 value) 
{
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    U64 data = CByteSwap::hton( value );
    
	switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Write( & data, sizeof(U64) );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Write( & data, sizeof(U64) );
        }
        break;
    }
}

void atom::CExportableWrapper::Write(float value) 
{
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    float data(0.0f); 
    CByteSwap::hton_float( value, data );

	switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Write( & data, sizeof(float) );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Write( & data, sizeof(float) );
        }
        break;
    }
}

void atom::CExportableWrapper::Write(double value) 
{
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    double data(0.0f); 
    CByteSwap::hton_float( value, data );

	switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Write( & data, sizeof(double) );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Write( & data, sizeof(double) );
        }
        break;
    }
}

void atom::CExportableWrapper::Write(const char * value) 
{
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    a_string text;
    if( value ) 
    {
		// if input string is utf-8 format, don't convert.
		if( CUtf8Charset::IsUtf8(value) ) {
			text = value;
		} else {
			text = CCharacter::MultiBytesToUtf8( value );
		}

		// check input string's length.
        if( text.length() > U32_MAX ) {
            text.clear();
        }
    }

    U32 length( static_cast<U32>( text.length() ) );
    Write( length );

    switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Write( text.c_str(), text.length() );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Write( text.c_str(), text.length() );
        }
        break;
    }
}

void atom::CExportableWrapper::Write(const wchar_t * value) 
{
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    a_string text;
    if( value ) 
    {
        text = CCharacter::UnicodeToUtf8( value );
        if( text.length() > U32_MAX ) {
            text.clear();
        }
    }

    U32 length( static_cast<U32>( text.length() ) );
    Write( length );

    switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Write( text.c_str(), text.length() );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Write( text.c_str(), text.length() );
        }
        break;
    }
}

void atom::CExportableWrapper::Write(const void * bytes, U64 length) 
{
    if( !bind || !bytes || !length ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_EXPORT_STREAM:
        if( port.e ) {
            port.e -> Write( bytes, length );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Write( bytes, length );
        }
        break;
    }
}
