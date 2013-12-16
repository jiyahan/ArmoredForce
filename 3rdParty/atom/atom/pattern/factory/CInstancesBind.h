#ifndef CINSTANCESBIND_H
#define CINSTANCESBIND_H
//Begin section for file CInstancesBind.h
//TODO: Add definitions that you want preserved
//End section for file CInstancesBind.h
#include "../../Common.h"
#include "../object/CReferencedObject.h"
#include "../../utility/stl/stl_extend.h"
#include "../../utility/stl/allocator.h"



namespace atom
{

    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef std::map<U64, CReferencedObject *, less<U64>, atom_allocator<pair<U64, CReferencedObject *> > >  CInstancesBind ;

} //end namespace atom

#endif
