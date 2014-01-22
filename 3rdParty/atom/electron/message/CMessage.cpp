#include "CMessage.h"
#include "../enumeration/INTERFACE_ID.h"


electron::CMessage::CMessage(U16 command) 
{
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

electron::CMessage::~CMessage() 
{
}

bool electron::CMessage::Initiate() 
{
    return life.Initiate();
}

bool electron::CMessage::Shutdown() 
{
    return life.Shutdown();
}

U16 electron::CMessage::GetCommandID() 
{
    return entry.GetCommandID();
}

void electron::CMessage::SetConnector(U64 value) 
{
    entry.SetConnector( value );
}

U64 electron::CMessage::GetConnector() 
{
    return entry.GetConnector();
}

void electron::CMessage::Write(I08 value) 
{
    exportable.Write( value );
}

void electron::CMessage::Write(I16 value) 
{
    exportable.Write( value );
}

void electron::CMessage::Write(I32 value) 
{
    exportable.Write( value );
}

void electron::CMessage::Write(I64 value) 
{
    exportable.Write( value );
}

void electron::CMessage::Write(U08 value) 
{
    exportable.Write( value );
}

void electron::CMessage::Write(U16 value) 
{
    exportable.Write( value );
}

void electron::CMessage::Write(U32 value) 
{
    exportable.Write( value );
}

void electron::CMessage::Write(U64 value) 
{
    exportable.Write( value );
}

void electron::CMessage::Write(float value) 
{
    exportable.Write( value );
}

void electron::CMessage::Write(double value) 
{
    exportable.Write( value );
}

void electron::CMessage::Write(const char * value) 
{
    exportable.Write( value );
}

void electron::CMessage::Write(const wchar_t * value) 
{
    exportable.Write( value );
}

void electron::CMessage::Write(const void * bytes, U64 length) 
{
    exportable.Write( bytes, length );
}

I08 electron::CMessage::ReadI08() 
{
    return importable.ReadI08();
}

I16 electron::CMessage::ReadI16() 
{
    return importable.ReadI16();
}

I32 electron::CMessage::ReadI32() 
{
    return importable.ReadI32();
}

I64 electron::CMessage::ReadI64() 
{
    return importable.ReadI64();
}

U08 electron::CMessage::ReadU08() 
{
    return importable.ReadU08();
}

U16 electron::CMessage::ReadU16() 
{
    return importable.ReadU16();
}

U32 electron::CMessage::ReadU32() 
{
    return importable.ReadU32();
}

U64 electron::CMessage::ReadU64() 
{
    return importable.ReadU64();
}

float electron::CMessage::ReadFloat() 
{
    return importable.ReadFloat();
}

double electron::CMessage::ReadDouble() 
{
    return importable.ReadDouble();
}

a_string electron::CMessage::ReadString() 
{
    return importable.ReadString();
}

a_string electron::CMessage::ReadUtf8String() 
{
    return importable.ReadUtf8String();
}

a_wstring electron::CMessage::ReadWString() 
{
    return importable.ReadWString();
}

U64 electron::CMessage::ReadBytes(void * bytes, U64 length) 
{
    return importable.ReadBytes( bytes, length );
}

bool electron::CMessage::Analyze(CMemory & data)
{
    bool result = false;
    if( stream.Assign(data) )
    {
        U16 command = ReadU16();
        entry.SetCommandID( command );
        result = true;
    }
    return result;
}

IInterface * electron::CMessage::QueryInterface(U32 iid) 
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
    case IID_INSTANCE_LIFE:
        result = & life;
        break;
    case IID_MESSAGE_ENTRY:
        result = & entry;
        break;
    }
    return result;
}
