#ifndef CCODEPAGEBIND_H
#define CCODEPAGEBIND_H
#include "../../Common.h"
#include "../../utility/stl/a_string.h"


namespace atom
{


    typedef std::map<a_string, I32, less<a_string>, atom_allocator<pair<a_string, I32> > > CCodePageBind ;

}//end namespace atom


#endif
