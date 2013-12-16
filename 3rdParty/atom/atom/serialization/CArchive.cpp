#include "CArchive.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CArchive.cpp
//TODO: Add definitions that you want preserved
//End section for file CArchive.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CArchive::CArchive() 
{
    //TODO Auto-generated method stub
    stream        .SetNest( this );
    importable    .SetNest( this );
    exportable    .SetNest( this );
    import_archive.SetNest( this );
    export_archive.SetNest( this );
    
    importable    .Attach ( this );
    exportable    .Attach ( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CArchive::~CArchive() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CArchive::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CArchive::Assign(CMemory & data) 
{
    //TODO Auto-generated method stub
    return stream.Assign( data );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CArchive::Clone(CMemory & data) 
{
    //TODO Auto-generated method stub
    return stream.Clone( data );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CArchive::Clear() 
{
    //TODO Auto-generated method stub
    stream.Reset();
}
