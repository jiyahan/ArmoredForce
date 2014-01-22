#ifndef TAGMEMORYCOUNT_H
#define TAGMEMORYCOUNT_H
#include "../../Common.h"



namespace atom
{



    struct tagMemoryCount
    {


        private:


            volatile long a_count;



            volatile long r_count;



            volatile long m_count;




        public:

            inline tagMemoryCount(); 



            inline ~tagMemoryCount(); 



            inline void Reset(long & a, long & r, long & m); 



            inline void IncACount(); 



            inline void IncRCount(); 



            inline void IncMCount(); 



    };  //end struct tagMemoryCount


}//end namespace atom


atom::tagMemoryCount::tagMemoryCount() : 
a_count(0),r_count(0),m_count(0)
{
}

atom::tagMemoryCount::~tagMemoryCount() 
{
}

void atom::tagMemoryCount::Reset(long & a, long & r, long & m) 
{
    #ifdef _WIN32
    a = InterlockedExchange( & a_count, 0 );
    r = InterlockedExchange( & r_count, 0 );
    m = InterlockedExchange( & m_count, 0 );
    #endif

    #ifdef __linux
    a = __sync_lock_test_and_set( & a_count, 0 );
    r = __sync_lock_test_and_set( & r_count, 0 );
    m = __sync_lock_test_and_set( & m_count, 0 );
    #endif

    #ifdef __APPLE__
    a = __sync_lock_test_and_set( & a_count, 0 );
    r = __sync_lock_test_and_set( & r_count, 0 );
    m = __sync_lock_test_and_set( & m_count, 0 );
    #endif
}

void atom::tagMemoryCount::IncACount() 
{
    #ifdef _WIN32
    InterlockedIncrement( & a_count);
    #endif

    #ifdef __linux
    __sync_add_and_fetch( & a_count, 1 );
    #endif

    #ifdef __APPLE__
    __sync_add_and_fetch( & a_count, 1 );
    #endif
}

void atom::tagMemoryCount::IncRCount() 
{
    #ifdef _WIN32
    InterlockedIncrement( & r_count);
    #endif

    #ifdef __linux
    __sync_add_and_fetch( & r_count, 1 );
    #endif

	#ifdef __APPLE__
    __sync_add_and_fetch( & r_count, 1 );
    #endif
}

void atom::tagMemoryCount::IncMCount() 
{
    #ifdef _WIN32
    InterlockedIncrement( & m_count);
    #endif

    #ifdef __linux
    __sync_add_and_fetch( & m_count, 1 );
    #endif

	#ifdef __APPLE__
    __sync_add_and_fetch( & m_count, 1 );
    #endif
}

#endif
