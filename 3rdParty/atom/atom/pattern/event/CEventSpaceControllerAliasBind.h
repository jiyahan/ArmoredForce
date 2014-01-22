#ifndef CEVENTSPACECONTROLLERALIASBIND_H
#define CEVENTSPACECONTROLLERALIASBIND_H
#include "../../Common.h"
#include "../../utility/stl/a_string.h"
#include "../../utility/stl/allocator.h"



namespace atom
{



	typedef std::map<a_string, U64, less<a_string>, atom_allocator<pair<a_string, U64> > >  CEventSpaceControllerAliasBind ;



} //end namespace atom



#endif
