#include "CLog.h"
#include "../enumeration/INTERFACE_ID.h"
#include "../enumeration/LOG_LEVEL.h"


atom::CLog::CLog() 
{
    archive .SetNest( this );
    exporter.SetNest( this );
}

atom::CLog::~CLog() 
{
}

atom::IInterface * atom::CLog::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_LOG_ARCHIVE:
        result = & archive;
        break;
    }
    return result;
}

atom::CLog & atom::CLog::operator <<(const char * message) 
{
    archive.Append( message );
    return( *this );
}

atom::CLog & atom::CLog::operator <<(LINE_END flag) 
{
    UNREFERENCED_PARAMETER( flag );
    archive.Append( "\r\n" );
    return( *this );
}

void atom::CLog::operator <<(END_DEBUG flag) 
{
    UNREFERENCED_PARAMETER( flag );
    archive.Finish( LL_DEBUG );
}

void atom::CLog::operator <<(END_ALARM flag) 
{
    UNREFERENCED_PARAMETER( flag );
    archive.Finish( LL_ALARM );
}

void atom::CLog::operator <<(END_ERROR flag) 
{
    UNREFERENCED_PARAMETER( flag );
    archive.Finish( LL_ERROR );
}
