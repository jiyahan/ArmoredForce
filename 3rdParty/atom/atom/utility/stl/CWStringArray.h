#ifndef CWSTRINGARRAY_H
#define CWSTRINGARRAY_H
#include "../../Common.h"
#include "a_wstring.h"



namespace atom
{

    typedef std::vector<a_wstring, atom_allocator<a_wstring> >  CWStringArray ;

} //end namespace atom

#endif
