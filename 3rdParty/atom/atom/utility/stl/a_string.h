#ifndef A_STRING_H
#define A_STRING_H
#include "../../Common.h"
#include "allocator.h"

namespace atom
{


    typedef std::basic_string<char, std::char_traits<char>, atom_allocator<char> > a_string ;


}//end namespace atom


#endif
