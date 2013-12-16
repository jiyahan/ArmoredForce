#include "CLogExporter.h"
#include "../utility/charset/CUtf8Charset.h"
#include "../os/character/CCharacter.h"
//Begin section for file CLogExporter.cpp
//TODO: Add definitions that you want preserved
//End section for file CLogExporter.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLogExporter::CLogExporter() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLogExporter::~CLogExporter() 
{
    //TODO Auto-generated method stub
}
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CLogExporter::IncRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CLogExporter::DecRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CLogExporter::GetRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CLogExporter::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(bool & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        if( value )
            segment -> Append( "[type: bool][data: true]" );
        else
            segment -> Append( "[type: bool][data: false]" );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(char & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: plain char][data: %d|%c]", value, value );
        segment -> Append( msg );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(I08 & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: i08][data: %i]", value );
        segment -> Append( msg );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(I16 & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: i16][data: %i]", value );
        segment -> Append( msg );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(I32 & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: i32][data: %i]", value );
        segment -> Append( msg );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(I64 & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: i64][data: %lli]", value );
        segment -> Append( msg );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(U08 & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: u08][data: %u]", value );
        segment -> Append( msg );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(U16 & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: u16][data: %u]", value );
        segment -> Append( msg );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(U32 & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: u32][data: %u]", value );
        segment -> Append( msg );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(U64 & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: u64][data: %llu]", value );
        segment -> Append( msg );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(float & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: float][data: %f]", value );
        segment -> Append( msg );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(double & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: double][data: %f]", value );
        segment -> Append( msg );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(a_string & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        // output is utf-8 format
        a_string msg;
        msg += "[type: multi-bytes string][data: ";
        if( CUtf8Charset::IsUtf8( value.c_str() ) ) {
			msg += value;
		} else {
            msg += CCharacter::MultiBytesToUtf8( value.c_str() );
		}
        msg += "]";
        segment -> Append( msg.c_str() );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(a_wstring & value) 
{
    //TODO Auto-generated method stub
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        a_string msg;
        msg += "[type: unicode string][data: ";
        msg += CCharacter::UnicodeToUtf8( value.c_str() );
        msg += "]";
        segment -> Append( msg.c_str() );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogExporter::Bind(void * buffer, U64 length) 
{
    //TODO Auto-generated method stub
    if( buffer && length )
    {
        CInterface<ILogArchive> segment;
        if( segment.Mount(this, IID_LOG_ARCHIVE) )
        {
            a_string msg;
            msg += "[type: memory][data:";

            char data[64];
            for( size_t i = 0; i < length; ++ i )
            {
                sprintf( data, " 0x%02X", reinterpret_cast<unsigned char *>(buffer)[i] ); 
                msg += data;
            }

            msg += "]";
            segment -> Append( msg.c_str() );
        }
    }
}
