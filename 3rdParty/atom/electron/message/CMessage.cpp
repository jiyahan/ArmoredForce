#include "CMessage.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CMessage.cpp
//TODO: Add definitions that you want preserved
//End section for file CMessage.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CMessage::CMessage(U16 command) 
{
    //TODO Auto-generated method stub
    entry     .SetNest( this );
    stream    .SetNest( this );
    importable.SetNest( this );
    exportable.SetNest( this );
    life      .SetNest( this );

    importable.Attach ( this );
    exportable.Attach ( this );

    entry.SetCommandID( command );
    if( command != MID_UNKNOW ) Write( command );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CMessage::~CMessage() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CMessage::Initiate() 
{
    //TODO Auto-generated method stub
    return life.Initiate();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CMessage::Shutdown() 
{
    //TODO Auto-generated method stub
    return life.Shutdown();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U16 electron::CMessage::GetCommandID() 
{
    //TODO Auto-generated method stub
    return entry.GetCommandID();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::SetConnector(U64 value) 
{
    //TODO Auto-generated method stub
    entry.SetConnector( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 electron::CMessage::GetConnector() 
{
    //TODO Auto-generated method stub
    return entry.GetConnector();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::Write(I08 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::Write(I16 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::Write(I32 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::Write(I64 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::Write(U08 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::Write(U16 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::Write(U32 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::Write(U64 value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::Write(float value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::Write(double value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::Write(const char * value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::Write(const wchar_t * value) 
{
    //TODO Auto-generated method stub
    exportable.Write( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessage::Write(const void * bytes, U64 length) 
{
    //TODO Auto-generated method stub
    exportable.Write( bytes, length );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I08 electron::CMessage::ReadI08() 
{
    //TODO Auto-generated method stub
    return importable.ReadI08();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I16 electron::CMessage::ReadI16() 
{
    //TODO Auto-generated method stub
    return importable.ReadI16();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I32 electron::CMessage::ReadI32() 
{
    //TODO Auto-generated method stub
    return importable.ReadI32();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I64 electron::CMessage::ReadI64() 
{
    //TODO Auto-generated method stub
    return importable.ReadI64();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U08 electron::CMessage::ReadU08() 
{
    //TODO Auto-generated method stub
    return importable.ReadU08();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U16 electron::CMessage::ReadU16() 
{
    //TODO Auto-generated method stub
    return importable.ReadU16();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 electron::CMessage::ReadU32() 
{
    //TODO Auto-generated method stub
    return importable.ReadU32();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 electron::CMessage::ReadU64() 
{
    //TODO Auto-generated method stub
    return importable.ReadU64();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
float electron::CMessage::ReadFloat() 
{
    //TODO Auto-generated method stub
    return importable.ReadFloat();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
double electron::CMessage::ReadDouble() 
{
    //TODO Auto-generated method stub
    return importable.ReadDouble();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
a_string electron::CMessage::ReadString() 
{
    //TODO Auto-generated method stub
    return importable.ReadString();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
a_string electron::CMessage::ReadUtf8String() 
{
    //TODO Auto-generated method stub
    return importable.ReadUtf8String();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
a_wstring electron::CMessage::ReadWString() 
{
    //TODO Auto-generated method stub
    return importable.ReadWString();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 electron::CMessage::ReadBytes(void * bytes, U64 length) 
{
    //TODO Auto-generated method stub
    return importable.ReadBytes( bytes, length );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CMessage::Analyze(CMemory & data)
{
    //TODO Auto-generated method stub
    bool result = false;
    if( stream.Assign(data) )
    {
        U16 command = ReadU16();
        entry.SetCommandID( command );
        result = true;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
IInterface * electron::CMessage::QueryInterface(U32 iid) 
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
    case IID_INSTANCE_LIFE:
        result = & life;
        break;
    case IID_MESSAGE_ENTRY:
        result = & entry;
        break;
    }
    return result;
}
