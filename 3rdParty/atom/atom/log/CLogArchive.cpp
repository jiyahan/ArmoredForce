#include "CLogArchive.h"
#include "CLogService.h"
#include "../enumeration/LOG_LEVEL.h"


atom::CLogArchive::CLogArchive() : 
nest(NULL)
{
}

atom::CLogArchive::~CLogArchive() 
{
}

int atom::CLogArchive::IncRef() 
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

int atom::CLogArchive::DecRef() 
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

int atom::CLogArchive::GetRef() 
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

atom::IInterface * atom::CLogArchive::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CLogArchive::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

void atom::CLogArchive::Append(const char * value) 
{
    if( value ) {
        data += value;
    }
}

void atom::CLogArchive::Finish(U08 level) 
{
    CLogService::GetInstance() -> Record( level, data.c_str() );
    data.clear();
}
