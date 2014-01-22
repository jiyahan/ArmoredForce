#ifndef TAGMEMORYSECTOR_H
#define TAGMEMORYSECTOR_H
#include "../../Common.h"


namespace atom
{



    struct tagMemorySector
    {


        public:


            //<p>memory length</p>
            size_t level;



            //<p>memory capacity</p>
            size_t limit;



            //<p>user data length</p>
            size_t valid;



            //<p>reference counter</p>
			#ifdef _WIN32
            volatile long refer;
			#endif

			#if defined(__linux) || defined(__APPLE__)
            volatile int  refer;
			#endif



            inline tagMemorySector(); 



            inline int IncRef(); 



            inline int DecRef(); 



            inline int GetRef(); 



            inline void Reset(); 



            inline void Reset(size_t valid); 

	
	
	};  //end struct tagMemorySector


}//end namespace atom


atom::tagMemorySector::tagMemorySector() : 
level(0),limit(0),valid(0),refer(0)
{
}

int atom::tagMemorySector::IncRef() 
{
    #ifdef _WIN32
    return InterlockedIncrement( &refer);
    #endif

    #if defined(__linux) || defined(__APPLE__)
    return __sync_add_and_fetch( &refer, 1 );
    #endif
}

int atom::tagMemorySector::DecRef() 
{
    #ifdef _WIN32
    return InterlockedDecrement( &refer );
    #endif

    #if defined(__linux) || defined(__APPLE__)
    return __sync_sub_and_fetch( &refer, 1 );
    #endif
}

int atom::tagMemorySector::GetRef() 
{
    #ifdef _WIN32
    return InterlockedCompareExchange ( &refer, 0, 0 );
    #endif

    #if defined(__linux) || defined(__APPLE__)
    return __sync_val_compare_and_swap( &refer, 0, 0 );
    #endif
}

void atom::tagMemorySector::Reset() 
{
    // clear user data length
    valid = 0;

    #ifdef _WIN32
    InterlockedExchange( &refer, 0 );
    #endif

    #if defined(__linux) || defined(__APPLE__)
    __sync_lock_release( &refer );
    #endif
}

void atom::tagMemorySector::Reset(size_t align)
{
    level = align;
    limit = align - sizeof( tagMemorySector );
    refer = 0;
    valid = 0;
}

#endif
