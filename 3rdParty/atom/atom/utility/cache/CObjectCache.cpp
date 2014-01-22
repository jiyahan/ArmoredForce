#include "CObjectCache.h"


TLS_DECLARE atom::CObjectCacheSet * atom::CObjectCache::cache = NULL;

void atom::CObjectCache::Initiate() 
{
    // if system support thread storage local, then create cache;
    #ifndef TLS_NOT_SUPPORT
    cache = new CObjectCacheSet;
    #endif
}

void atom::CObjectCache::Shutdown() 
{
    if( cache )
    {
        cache -> Release();
        SAFE_DELETE( cache );
    }
}

void atom::CObjectCache::Recover() 
{
    if( cache ) cache -> Recycle();
}
