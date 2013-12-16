#include "CDataReader.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CDataReader.cpp
//TODO: Add definitions that you want preserved
//End section for file CDataReader.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CDataReader::CDataReader() : 
bind(NULL)
{
    //TODO Auto-generated method stub
    closable   .SetNest( this );
    swappable  .SetNest( this );
    assignable .SetNest( this );
    truncatable.SetNest( this );
    importable .SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CDataReader::~CDataReader() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CDataReader::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataReader::Attach(IInterface * node) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataReader::Detach() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CDataReader::Assign(CMemory & data) 
{
    //TODO Auto-generated method stub
    return assignable.Assign( data );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataReader::Close() 
{
    //TODO Auto-generated method stub
    closable.Close();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CDataReader::Swap(CMemory & data) 
{
    //TODO Auto-generated method stub
    return swappable.Swap( data );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataReader::Truncate() 
{
    //TODO Auto-generated method stub
    truncatable.Truncate();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I08 atom::CDataReader::ReadI08() 
{
    //TODO Auto-generated method stub
    return importable.ReadI08();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I16 atom::CDataReader::ReadI16() 
{
    //TODO Auto-generated method stub
    return importable.ReadI16();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I32 atom::CDataReader::ReadI32() 
{
    //TODO Auto-generated method stub
    return importable.ReadI32();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I64 atom::CDataReader::ReadI64() 
{
    //TODO Auto-generated method stub
    return importable.ReadI64();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U08 atom::CDataReader::ReadU08() 
{
    //TODO Auto-generated method stub
    return importable.ReadU08();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U16 atom::CDataReader::ReadU16() 
{
    //TODO Auto-generated method stub
    return importable.ReadU16();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CDataReader::ReadU32() 
{
    //TODO Auto-generated method stub
    return importable.ReadU32();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CDataReader::ReadU64() 
{
    //TODO Auto-generated method stub
    return importable.ReadU64();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
float atom::CDataReader::ReadFloat() 
{
    //TODO Auto-generated method stub
    return importable.ReadFloat();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
double atom::CDataReader::ReadDouble() 
{
    //TODO Auto-generated method stub
    return importable.ReadDouble();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CDataReader::ReadString() 
{
    //TODO Auto-generated method stub
    return importable.ReadString();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CDataReader::ReadUtf8String() 
{
    //TODO Auto-generated method stub
    return importable.ReadUtf8String();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_wstring atom::CDataReader::ReadWString() 
{
    //TODO Auto-generated method stub
    return importable.ReadWString();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CDataReader::ReadBytes(void * bytes, U64 length) 
{
    //TODO Auto-generated method stub
    return importable.ReadBytes( bytes, length );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataReader::SkipBytes(I64 count) 
{
    //TODO Auto-generated method stub
    return importable.SkipBytes( count );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CDataReader::Available()
{
    //TODO Auto-generated method stub
    return importable.Available();
}
