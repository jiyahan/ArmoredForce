#include "CDataWriter.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CDataWriter.cpp
//TODO: Add definitions that you want preserved
//End section for file CDataWriter.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CDataWriter::CDataWriter() : 
bind(NULL)
{
    //TODO Auto-generated method stub
    closable  .SetNest( this );
    swappable .SetNest( this );
    clonable  .SetNest( this );
    flushable .SetNest( this );
    exportable.SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CDataWriter::~CDataWriter() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CDataWriter::QueryInterface(U32 iid) 
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Attach(IInterface * node) 
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Detach() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Write(I08 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Write(I16 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Write(I32 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Write(I64 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Write(U08 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Write(U16 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Write(U32 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Write(U64 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Write(float value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Write(double value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Write(const char * value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Write(const wchar_t * value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Write(const void * bytes, U64 length) 
{
    //TODO Auto-generated method stub
    exportable.Write( bytes, length );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Close() 
{
    //TODO Auto-generated method stub
    closable.Close();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CDataWriter::Flush() 
{
    //TODO Auto-generated method stub
    flushable.Flush();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CDataWriter::Clone(CMemory & data) 
{
    //TODO Auto-generated method stub
    return clonable.Clone( data );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CDataWriter::Swap(CMemory & data) 
{
    //TODO Auto-generated method stub
    return swappable.Swap( data );
}
