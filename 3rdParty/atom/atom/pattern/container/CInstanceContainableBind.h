#ifndef CINSTANCECONTAINABLEBIND_H
#define CINSTANCECONTAINABLEBIND_H
#include "../../Common.h"
#include "../../utility/stl/allocator.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



    typedef std::map<U64, CObjectPtr, less<U64>, atom_allocator<pair<U64, CObjectPtr> > >  CInstanceContainableBind ;



}



#endif
