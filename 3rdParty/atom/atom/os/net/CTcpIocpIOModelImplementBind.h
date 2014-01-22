#ifndef CTCPIOCPIOMODELIMPLEMENTBIND_H
#define CTCPIOCPIOMODELIMPLEMENTBIND_H
#include "../../utility/allocator/CAllocator.h"
#include "tagIocpOperation.h"



namespace atom
{



	typedef CAllocator<tagIocpOperation,128,32> CTcpIocpIOModelImplementBind;



} //end namespace atom



#endif
