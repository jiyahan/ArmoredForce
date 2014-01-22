#ifndef CIMPORTSTREAMBIND_H
#define CIMPORTSTREAMBIND_H
#include "../../Common.h"
#include "../../os/memory/CMemory.h"
#include "../../utility/stl/allocator.h"


namespace atom
{


    typedef std::list<CMemory, atom_allocator<CMemory> > CImportStreamBind ;

}//end namespace atom


#endif
