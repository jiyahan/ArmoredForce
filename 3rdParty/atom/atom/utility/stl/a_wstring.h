#ifndef A_WSTRING_H
#define A_WSTRING_H
#include "../../Common.h"
#include "allocator.h"



namespace atom
{


    typedef std::basic_string<wchar_t, std::char_traits<wchar_t>, atom_allocator<wchar_t> > a_wstring ;


}//end namespace atom


#endif
