#ifndef COBJECTCACHESETBIND_H
#define COBJECTCACHESETBIND_H
#include "tagObjectCache.h"
#include "../stl/allocator.h"



namespace atom
{



    typedef std::map<U64, tagObjectCache, std::less<U64>, atom_allocator<pair<U64, tagObjectCache> > >  CObjectCacheSetBind ;



} //end namespace atom



#endif
