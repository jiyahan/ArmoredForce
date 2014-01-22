#ifndef CSTRINGARRAY_H
#define CSTRINGARRAY_H
#include "../../Common.h"
#include "a_string.h"



namespace atom
{

    typedef std::vector<a_string, atom_allocator<a_string> >  CStringArray ;

} //end namespace atom

#endif
