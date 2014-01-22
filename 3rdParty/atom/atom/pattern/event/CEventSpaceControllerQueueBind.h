#ifndef CEVENTSPACECONTROLLERQUEUEBIND_H
#define CEVENTSPACECONTROLLERQUEUEBIND_H
#include "../../Common.h"
#include "tagEvent.h"
#include "../../utility/stl/allocator.h"



namespace atom
{



	typedef std::list<tagEvent,  atom_allocator<tagEvent> >  CEventSpaceControllerQueueBind ;



} //end namespace atom



#endif
