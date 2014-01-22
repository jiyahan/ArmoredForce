#ifndef CINSTANCESBIND_H
#define CINSTANCESBIND_H
#include "../../Common.h"
#include "../object/CReferencedObject.h"
#include "../../utility/stl/stl_extend.h"
#include "../../utility/stl/allocator.h"



namespace atom
{

    typedef std::map<U64, CReferencedObject *, less<U64>, atom_allocator<pair<U64, CReferencedObject *> > >  CInstancesBind ;

} //end namespace atom

#endif
