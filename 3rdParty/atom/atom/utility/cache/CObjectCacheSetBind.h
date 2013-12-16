#ifndef COBJECTCACHESETBIND_H
#define COBJECTCACHESETBIND_H
//Begin section for file CObjectCacheSetBind.h
//TODO: Add definitions that you want preserved
//End section for file CObjectCacheSetBind.h
#include "tagObjectCache.h"
#include "../stl/allocator.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef std::map<U64, tagObjectCache, std::less<U64>, atom_allocator<pair<U64, tagObjectCache> > >  CObjectCacheSetBind ;



} //end namespace atom



#endif
