#include "CImportableWrapper.h"
#include "../../interface/IImportStream.h"
#include "../../interface/IStream.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/byteswap/CByteSwap.h"
#include "../../os/character/CCharacter.h"
//Begin section for file CImportableWrapper.cpp
//TODO: Add definitions that you want preserved
//End section for file CImportableWrapper.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CImportableWrapper::CImportableWrapper() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
bind(NULL),wrap(IID_UNKNOW)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CImportableWrapper::~CImportableWrapper() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportableWrapper::Verify() 
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
void atom::CImportableWrapper::Attach(IInterface * value) 
{
    //TODO Auto-generated method stub
    /* not increase any reference, nest will do it */
    bind = value;
    wrap = IID_UNKNOW;
	port.Clear();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CImportableWrapper::IncRef() 
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
int atom::CImportableWrapper::DecRef() 
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
int atom::CImportableWrapper::GetRef() 
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
atom::IInterface * atom::CImportableWrapper::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportableWrapper::SetNest(IInterface * value) 
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
I08 atom::CImportableWrapper::ReadI08() 
{
    //TODO Auto-generated method stub
    if( !bind ) return 0;

    I08 result = 0;
    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_IMPORT_STREAM:
        if( port.i ) 
        {
            if( port.i -> Available() >= sizeof(I08) ) { 
                result = port.i -> Read();
            }
        }
        break;
    case IID_STREAM:
        if( port.s ) 
        {
            if( port.s -> Available() >= sizeof(I08) ) { 
                result = port.s -> Read();
            }
        }
        break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I16 atom::CImportableWrapper::ReadI16() 
{
    //TODO Auto-generated method stub
    if( !bind ) return 0;

    I16 result = 0;
    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_IMPORT_STREAM:
        if( port.i ) 
        {
            if( port.i -> Available()  >= sizeof(I16) ) { 
                port.i -> Read( & result, sizeof(I16) );
                result = CByteSwap::ntoh( result );
            }
        }
        break;
    case IID_STREAM:
        if( port.s ) 
        {
            if( port.s -> Available()  >= sizeof(I16) ) { 
                port.s -> Read( & result, sizeof(I16) );
                result = CByteSwap::ntoh( result );
            }
        }
        break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I32 atom::CImportableWrapper::ReadI32() 
{
    //TODO Auto-generated method stub
    if( !bind ) return 0;

    I32 result = 0;
    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_IMPORT_STREAM:
        if( port.i ) 
        {
            if( port.i -> Available()  >= sizeof(I32) ) { 
                port.i -> Read( & result, sizeof(I32) );
                result = CByteSwap::ntoh( result );
            }
        }
        break;
    case IID_STREAM:
        if( port.s ) 
        {
            if( port.s -> Available()  >= sizeof(I32) ) { 
                port.s -> Read( & result, sizeof(I32) );
                result = CByteSwap::ntoh( result );
            }
        }
        break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I64 atom::CImportableWrapper::ReadI64() 
{
    //TODO Auto-generated method stub
    if( !bind ) return 0;

    I64 result = 0;
    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_IMPORT_STREAM:
        if( port.i ) 
        {
            if( port.i -> Available()  >= sizeof(I64) ) { 
                port.i -> Read( & result, sizeof(I64) );
                result = CByteSwap::ntoh( result );
            }
        }
        break;
    case IID_STREAM:
        if( port.s ) 
        {
            if( port.s -> Available()  >= sizeof(I64) ) { 
                port.s -> Read( & result, sizeof(I64) );
                result = CByteSwap::ntoh( result );
            }
        }
        break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U08 atom::CImportableWrapper::ReadU08() 
{
    //TODO Auto-generated method stub
    if( !bind ) return 0;

    U08 result = 0;
    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_IMPORT_STREAM:
        if( port.i ) 
        {
            if( port.i -> Available() >= sizeof(U08) ) { 
                result = port.i -> Read();
            }
        }
        break;
    case IID_STREAM:
        if( port.s ) 
        {
            if( port.s -> Available() >= sizeof(U08) ) { 
                result = port.s -> Read();
            }
        }
        break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U16 atom::CImportableWrapper::ReadU16() 
{
    //TODO Auto-generated method stub
    if( !bind ) return 0;

    U16 result = 0;
    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_IMPORT_STREAM:
        if( port.i ) 
        {
            if( port.i -> Available()  >= sizeof(U16) ) { 
                port.i -> Read( & result, sizeof(U16) );
                result = CByteSwap::ntoh( result );
            }
        }
        break;
    case IID_STREAM:
        if( port.s ) 
        {
            if( port.s -> Available()  >= sizeof(U16) ) { 
                port.s -> Read( & result, sizeof(U16) );
                result = CByteSwap::ntoh( result );
            }
        }
        break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CImportableWrapper::ReadU32() 
{
    //TODO Auto-generated method stub
    if( !bind ) return 0;

    U32 result = 0;
    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_IMPORT_STREAM:
        if( port.i ) 
        {
            if( port.i -> Available()  >= sizeof(U32) ) { 
                port.i -> Read( & result, sizeof(U32) );
                result = CByteSwap::ntoh( result );
            }
        }
        break;
    case IID_STREAM:
        if( port.s ) 
        {
            if( port.s -> Available()  >= sizeof(U32) ) { 
                port.s -> Read( & result, sizeof(U32) );
                result = CByteSwap::ntoh( result );
            }
        }
        break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CImportableWrapper::ReadU64() 
{
    //TODO Auto-generated method stub
    if( !bind ) return 0;

    U64 result = 0;
    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_IMPORT_STREAM:
        if( port.i ) 
        {
            if( port.i -> Available()  >= sizeof(U64) ) { 
                port.i -> Read( & result, sizeof(U64) );
                result = CByteSwap::ntoh( result );
            }
        }
        break;
    case IID_STREAM:
        if( port.s ) 
        {
            if( port.s -> Available()  >= sizeof(U64) ) { 
                port.s -> Read( & result, sizeof(U64) );
                result = CByteSwap::ntoh( result );
            }
        }
        break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
float atom::CImportableWrapper::ReadFloat() 
{
    //TODO Auto-generated method stub
    if( !bind ) return 0.0f;

    float result = 0.0f;
    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_IMPORT_STREAM:
        if( port.i ) 
        {
            if( port.i -> Available()  >= sizeof(float) ) 
            { 
                float retval(0.0f);
                port.i -> Read( & retval, sizeof(float) );
                CByteSwap::ntoh_float( retval, result );
            }
        }
        break;
    case IID_STREAM:
        if( port.s ) 
        {
            if( port.s -> Available()  >= sizeof(float) ) 
            { 
                float retval(0.0f);
                port.s -> Read( & retval, sizeof(float) );
                CByteSwap::ntoh_float( retval, result );
            }
        }
        break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
double atom::CImportableWrapper::ReadDouble() 
{
    //TODO Auto-generated method stub
    if( !bind ) return 0.0f;

    double result = 0.0f;
    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_IMPORT_STREAM:
        if( port.i ) 
        {
            if( port.i -> Available()  >= sizeof(double) ) 
            { 
                double retval(0.0f);
                port.i -> Read( & retval, sizeof(double) );
                CByteSwap::ntoh_float( retval, result );
            }
        }
        break;
    case IID_STREAM:
        if( port.s ) 
        {
            if( port.s -> Available()  >= sizeof(double) ) 
            { 
                double retval(0.0f);
                port.s -> Read( & retval, sizeof(double) );
                CByteSwap::ntoh_float( retval, result );
            }
        }
        break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CImportableWrapper::ReadString() 
{
    //TODO Auto-generated method stub
    a_string result;
    if( !bind ) return result;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    U32 length = ReadU32();
    if( length )
    {
        switch( wrap )
        {
        case IID_IMPORT_STREAM:
            if( port.i ) 
            {
                CMemory data;
                if( port.i -> Available() >= length && 
                    data.Alloc( static_cast<size_t>(length + 1) ) )
                { 
                    U64 bytes = port.i -> Read( data, length );
                    data.Query<char>()[bytes] = 0;

                    if( bytes < length ) SkipBytes( length - bytes );
                    result = CCharacter::Utf8ToMultiBytes( data.Query<char>() );
                }
            }
            break;
        case IID_STREAM:
            if( port.s ) 
            {
                CMemory data;
                if( port.s -> Available() >= length && 
                    data.Alloc( static_cast<size_t>(length + 1) ) )
                { 
                    U64 bytes = port.s -> Read( data, length );
                    data.Query<char>()[bytes] = 0;

                    if( bytes < length ) SkipBytes( length - bytes );
                    result = CCharacter::Utf8ToMultiBytes( data.Query<char>() );
                }
            }
            break;
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CImportableWrapper::ReadUtf8String() 
{
    //TODO Auto-generated method stub
    a_string result;
    if( !bind ) return result;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    U32 length = ReadU32();
    if( length )
    {
        switch( wrap )
        {
        case IID_IMPORT_STREAM:
            if( port.i ) 
            {
                CMemory data;
                if( port.i -> Available() >= length && 
                    data.Alloc( static_cast<size_t>(length + 1) ) )
                { 
                    U64 bytes = port.i -> Read( data, length );
                    data.Query<char>()[bytes] = 0;

                    if( bytes < length ) SkipBytes( length - bytes );
                    result = data.Query<char>();
                }
            }
            break;
        case IID_STREAM:
            if( port.s ) 
            {
                CMemory data;
                if( port.s -> Available() >= length && 
                    data.Alloc( static_cast<size_t>(length + 1) ) )
                { 
                    U64 bytes = port.s -> Read( data, length );
                    data.Query<char>()[bytes] = 0;

                    if( bytes < length ) SkipBytes( length - bytes );
                    result = data.Query<char>();
                }
            }
            break;
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_wstring atom::CImportableWrapper::ReadWString() 
{
    //TODO Auto-generated method stub
    a_wstring result;
    if( !bind ) return result;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    U32 length = ReadU32();
    if( length )
    {
        switch( wrap )
        {
        case IID_IMPORT_STREAM:
            if( port.i ) 
            {
                CMemory data;
                if( port.i -> Available() >= length && 
                    data.Alloc( static_cast<size_t>(length + 1) ) )
                { 
                    U64 bytes = port.i -> Read( data, length );
                    data.Query<char>()[bytes] = 0;

                    if( bytes < length ) SkipBytes( length - bytes );
                    result = CCharacter::Utf8ToUnicode( data.Query<char>() );
                }
            }
            break;
        case IID_STREAM:
            if( port.s ) 
            {
                CMemory data;
                if( port.s -> Available() >= length && 
                    data.Alloc( static_cast<size_t>(length + 1) ) )
                { 
                    U64 bytes = port.s -> Read( data, length );
                    data.Query<char>()[bytes] = 0;

                    if( bytes < length ) SkipBytes( length - bytes );
                    result = CCharacter::Utf8ToUnicode( data.Query<char>() );
                }
            }
            break;
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CImportableWrapper::ReadBytes(void * bytes, U64 length) 
{
    //TODO Auto-generated method stub
    if( !bind ) return 0;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    U64 result = 0;
    if( bytes && length )
    {
        switch( wrap )
        {
        case IID_IMPORT_STREAM:
            if( port.i && port.i -> Available() >= length ) {
                result =  port.i -> Read( bytes, length );
            }
            break;
        case IID_STREAM:
            if( port.s && port.s -> Available() >= length ) {
                result =  port.s -> Read( bytes, length );
            }
            break;
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportableWrapper::SkipBytes(I64 count) 
{
    //TODO Auto-generated method stub
    if( !bind ) return;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    switch( wrap )
    {
    case IID_IMPORT_STREAM:
        if( port.i ) {
            port.i -> Skip( count );
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            port.s -> Skip( count );
        }
        break;
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CImportableWrapper::Available()
{
    //TODO Auto-generated method stub
    if( !bind ) return 0;

    if( wrap == IID_UNKNOW ) {
        Verify();
    }

    U64 result = 0;
    switch( wrap )
    {
    case IID_IMPORT_STREAM:
        if( port.i ) {
            result = port.i -> Available();
        }
        break;
    case IID_STREAM:
        if( port.s ) {
            result = port.s -> Available();
        }
        break;
    }
    return result;
}
