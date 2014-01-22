#include "CLogExporter.h"
#include "../utility/charset/CUtf8Charset.h"
#include "../os/character/CCharacter.h"


atom::CLogExporter::CLogExporter() : 
nest(NULL)
{
}

atom::CLogExporter::~CLogExporter() 
{
}
int atom::CLogExporter::IncRef() 
{
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

int atom::CLogExporter::DecRef() 
{
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

int atom::CLogExporter::GetRef() 
{
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

atom::IInterface * atom::CLogExporter::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CLogExporter::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

void atom::CLogExporter::Bind(bool & value) 
{
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        if( value )
            segment -> Append( "[type: bool][data: true]" );
        else
            segment -> Append( "[type: bool][data: false]" );
    }
}

void atom::CLogExporter::Bind(char & value) 
{
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: plain char][data: %d|%c]", value, value );
        segment -> Append( msg );
    }
}

void atom::CLogExporter::Bind(I08 & value) 
{
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: i08][data: %i]", value );
        segment -> Append( msg );
    }
}

void atom::CLogExporter::Bind(I16 & value) 
{
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: i16][data: %i]", value );
        segment -> Append( msg );
    }
}

void atom::CLogExporter::Bind(I32 & value) 
{
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: i32][data: %i]", value );
        segment -> Append( msg );
    }
}

void atom::CLogExporter::Bind(I64 & value) 
{
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: i64][data: %lli]", value );
        segment -> Append( msg );
    }
}

void atom::CLogExporter::Bind(U08 & value) 
{
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: u08][data: %u]", value );
        segment -> Append( msg );
    }
}

void atom::CLogExporter::Bind(U16 & value) 
{
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: u16][data: %u]", value );
        segment -> Append( msg );
    }
}

void atom::CLogExporter::Bind(U32 & value) 
{
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: u32][data: %u]", value );
        segment -> Append( msg );
    }
}

void atom::CLogExporter::Bind(U64 & value) 
{
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: u64][data: %llu]", value );
        segment -> Append( msg );
    }
}

void atom::CLogExporter::Bind(float & value) 
{
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: float][data: %f]", value );
        segment -> Append( msg );
    }
}

void atom::CLogExporter::Bind(double & value) 
{
    CInterface<ILogArchive> segment;
    if( segment.Mount(this, IID_LOG_ARCHIVE) )
    {
        char msg[64];
        sprintf( msg, "[type: double][data: %f]", value );
        segment -> Append( msg );
    }
}

void atom::CLogExporter::Bind(a_string & value) 
{
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

void atom::CLogExporter::Bind(a_wstring & value) 
{
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

void atom::CLogExporter::Bind(void * buffer, U64 length) 
{
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
