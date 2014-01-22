#ifndef CATOMALLOCATORSINGLETONBIND_H
#define CATOMALLOCATORSINGLETONBIND_H
#include "../singleton/CSingleton.h"



namespace atom
{
	


	class CAtomAllocator;
	typedef CSingleton<CAtomAllocator> CAtomAllocatorSingletonBind;



} //end namespace atom



#endif
