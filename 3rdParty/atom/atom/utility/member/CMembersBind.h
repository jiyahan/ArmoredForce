#ifndef CMEMBERSBIND_H
#define CMEMBERSBIND_H
#include "../stl/a_string.h"



namespace atom
{



    typedef std::map<a_string, CMemory, less<a_string>, atom_allocator<pair<a_string, CMemory> > >  CMembersBind ;



} //end namespace atom



#endif
