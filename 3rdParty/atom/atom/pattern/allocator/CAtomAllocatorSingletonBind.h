#ifndef CATOMALLOCATORSINGLETONBIND_H
#define CATOMALLOCATORSINGLETONBIND_H
//Begin section for file CAtomAllocatorSingletonBind.h
//TODO: Add definitions that you want preserved
//End section for file CAtomAllocatorSingletonBind.h
#include "../singleton/CSingleton.h"



namespace atom
{
	


	class CAtomAllocator;
	typedef CSingleton<CAtomAllocator> CAtomAllocatorSingletonBind;



} //end namespace atom



#endif
