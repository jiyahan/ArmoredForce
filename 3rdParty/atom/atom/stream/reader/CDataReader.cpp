#include "CDataReader.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CDataReader::CDataReader() : 
bind(NULL)
{
    closable   .SetNest( this );
    swappable  .SetNest( this );
    assignable .SetNest( this );
    truncatable.SetNest( this );
    importable .SetNest( this );
}

atom::CDataReader::~CDataReader() 
{
}

atom::IInterface * atom::CDataReader::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_CLOSABLE:
        result = & closable;
        break;
    case IID_SWAPPABLE:
        result = & swappable;
        break;
    case IID_ASSIGNABLE:
        result = & assignable;
        break;
    case IID_TRUNCATABLE:
        result = & truncatable;
        break;
    case IID_IMPORTABLE:
        result = & importable;
        break;
    }
    return result;
}

void atom::CDataReader::Attach(IInterface * node) 
{
    if( node )
    {
        bind = node;
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( node );
        if( refered ) {
            refered -> IncRef();
        }

        closable   .Attach( node );
        swappable  .Attach( node );
        assignable .Attach( node );
        truncatable.Attach( node );
        importable .Attach( node );

        IInterface * unknow;
        unknow = bind -> QueryInterface( IID_IMPORT_STREAM );
        if( unknow )
        {
            swappable.SetTarget( IID_IMPORT_STREAM );
            IReferencedInterface * refered = 
                dynamic_cast<IReferencedInterface *>( unknow );
            SAFE_DECREF( refered );
        }

        unknow = bind -> QueryInterface( IID_STREAM );
        if( unknow )
        {
            swappable.SetTarget( IID_STREAM );
            IReferencedInterface * refered = 
                dynamic_cast<IReferencedInterface *>( unknow );
            SAFE_DECREF( refered );
        }   
    }
}

void atom::CDataReader::Detach() 
{
    if( bind )
    {
        closable   .Attach( NULL );
        swappable  .Attach( NULL );
        assignable .Attach( NULL );
        truncatable.Attach( NULL );
        importable .Attach( NULL );

        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( bind );
        if( refered ) {
            refered -> DecRef();
        }

        bind = NULL;
    }
}

bool atom::CDataReader::Assign(CMemory & data) 
{
    return assignable.Assign( data );
}

void atom::CDataReader::Close() 
{
    closable.Close();
}

bool atom::CDataReader::Swap(CMemory & data) 
{
    return swappable.Swap( data );
}

void atom::CDataReader::Truncate() 
{
    truncatable.Truncate();
}

I08 atom::CDataReader::ReadI08() 
{
    return importable.ReadI08();
}

I16 atom::CDataReader::ReadI16() 
{
    return importable.ReadI16();
}

I32 atom::CDataReader::ReadI32() 
{
    return importable.ReadI32();
}

I64 atom::CDataReader::ReadI64() 
{
    return importable.ReadI64();
}

U08 atom::CDataReader::ReadU08() 
{
    return importable.ReadU08();
}

U16 atom::CDataReader::ReadU16() 
{
    return importable.ReadU16();
}

U32 atom::CDataReader::ReadU32() 
{
    return importable.ReadU32();
}

U64 atom::CDataReader::ReadU64() 
{
    return importable.ReadU64();
}

float atom::CDataReader::ReadFloat() 
{
    return importable.ReadFloat();
}

double atom::CDataReader::ReadDouble() 
{
    return importable.ReadDouble();
}

atom::a_string atom::CDataReader::ReadString() 
{
    return importable.ReadString();
}

atom::a_string atom::CDataReader::ReadUtf8String() 
{
    return importable.ReadUtf8String();
}

atom::a_wstring atom::CDataReader::ReadWString() 
{
    return importable.ReadWString();
}

U64 atom::CDataReader::ReadBytes(void * bytes, U64 length) 
{
    return importable.ReadBytes( bytes, length );
}

void atom::CDataReader::SkipBytes(I64 count) 
{
    return importable.SkipBytes( count );
}

U64 atom::CDataReader::Available()
{
    return importable.Available();
}
