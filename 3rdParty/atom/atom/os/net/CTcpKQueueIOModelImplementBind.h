#ifndef CTCPKQUEUEIOMODELIMPLEMENTBIND_H
#define CTCPKQUEUEIOMODELIMPLEMENTBIND_H
#include "../../utility/allocator/CAllocator.h"
#include "tagTcpKQueueOperation.h"



namespace atom
{



	typedef CAllocator<tagTcpKQueueOperation,128,32> CTcpKQueueIOModelImplementBind;



} //end namespace atom



#endif
