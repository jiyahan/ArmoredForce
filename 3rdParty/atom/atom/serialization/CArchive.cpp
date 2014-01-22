#include "CArchive.h"
#include "../enumeration/INTERFACE_ID.h"


atom::CArchive::CArchive() 
{
    stream        .SetNest( this );
    importable    .SetNest( this );
    exportable    .SetNest( this );
    import_archive.SetNest( this );
    export_archive.SetNest( this );
    
    importable    .Attach ( this );
    exportable    .Attach ( this );
}

atom::CArchive::~CArchive() 
{
}

atom::IInterface * atom::CArchive::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_STREAM:
        result = & stream;
        break;
    case IID_IMPORTABLE:
        result = & importable;
        break;
    case IID_EXPORTABLE:
        result = & exportable;
        break;
    }
    return result;
}

bool atom::CArchive::Assign(CMemory & data) 
{
    return stream.Assign( data );
}

bool atom::CArchive::Clone(CMemory & data) 
{
    return stream.Clone( data );
}

void atom::CArchive::Clear() 
{
    stream.Reset();
}
