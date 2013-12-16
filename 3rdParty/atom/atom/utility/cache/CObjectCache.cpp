#include "CObjectCache.h"
//Begin section for file CObjectCache.cpp
//TODO: Add definitions that you want preserved
//End section for file CObjectCache.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
TLS_DECLARE atom::CObjectCacheSet * atom::CObjectCache::cache = NULL;

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CObjectCache::Initiate() 
{
    //TODO Auto-generated method stub
    // if system support thread storage local, then create cache;
    #ifndef TLS_NOT_SUPPORT
    cache = new CObjectCacheSet;
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CObjectCache::Shutdown() 
{
    //TODO Auto-generated method stub
    if( cache )
    {
        cache -> Release();
        SAFE_DELETE( cache );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CObjectCache::Recover() 
{
    //TODO Auto-generated method stub
    if( cache ) cache -> Recycle();
}
