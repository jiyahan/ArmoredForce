#include "CDataWriter.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CDataWriter::CDataWriter() : 
bind(NULL)
{
    closable  .SetNest( this );
    swappable .SetNest( this );
    clonable  .SetNest( this );
    flushable .SetNest( this );
    exportable.SetNest( this );
}

atom::CDataWriter::~CDataWriter() 
{
}

atom::IInterface * atom::CDataWriter::QueryInterface(U32 iid) 
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
    case IID_CLONABLE:
        result = & clonable;
        break;
    case IID_FLUSHABLE:
        result = & flushable;
        break;
    case IID_EXPORTABLE:
        result = & exportable;
        break;
    }
    return result;
}

void atom::CDataWriter::Attach(IInterface * node) 
{
    if( node )
    {
        bind = node;
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( node );
        if( refered ) {
            refered -> IncRef();
        }

        closable  .Attach( node );
        swappable .Attach( node );
        clonable  .Attach( node );
        flushable .Attach( node );
        exportable.Attach( node );

        IInterface * unknow;
        unknow = bind -> QueryInterface( IID_EXPORT_STREAM );
        if( unknow )
        {
            swappable.SetTarget( IID_EXPORT_STREAM );
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

void atom::CDataWriter::Detach() 
{
    if( bind )
    {
        closable  .Attach( NULL );
        swappable .Attach( NULL );
        clonable  .Attach( NULL );
        flushable .Attach( NULL );
        exportable.Attach( NULL );

        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( bind );
        if( refered ) {
            refered -> DecRef();
        }

        bind = NULL;
    }
}

void atom::CDataWriter::Write(I08 value) 
{
    exportable.Write( value );
}

void atom::CDataWriter::Write(I16 value) 
{
    exportable.Write( value );
}

void atom::CDataWriter::Write(I32 value) 
{
    exportable.Write( value );
}

void atom::CDataWriter::Write(I64 value) 
{
    exportable.Write( value );
}

void atom::CDataWriter::Write(U08 value) 
{
    exportable.Write( value );
}

void atom::CDataWriter::Write(U16 value) 
{
    exportable.Write( value );
}

void atom::CDataWriter::Write(U32 value) 
{
    exportable.Write( value );
}

void atom::CDataWriter::Write(U64 value) 
{
    exportable.Write( value );
}

void atom::CDataWriter::Write(float value) 
{
    exportable.Write( value );
}

void atom::CDataWriter::Write(double value) 
{
    exportable.Write( value );
}

void atom::CDataWriter::Write(const char * value) 
{
    exportable.Write( value );
}

void atom::CDataWriter::Write(const wchar_t * value) 
{
    exportable.Write( value );
}

void atom::CDataWriter::Write(const void * bytes, U64 length) 
{
    exportable.Write( bytes, length );
}

void atom::CDataWriter::Close() 
{
    closable.Close();
}

void atom::CDataWriter::Flush() 
{
    flushable.Flush();
}

bool atom::CDataWriter::Clone(CMemory & data) 
{
    return clonable.Clone( data );
}

bool atom::CDataWriter::Swap(CMemory & data) 
{
    return swappable.Swap( data );
}
