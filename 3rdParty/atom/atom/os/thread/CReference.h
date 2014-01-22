#ifndef CREFERENCE_H
#define CREFERENCE_H
#include "../../Common.h"



namespace atom
{



    class CReference
    {

        private:


            #ifdef _WIN32
            volatile long counter;
			#endif

            #if defined(__linux) || defined(__APPLE__)
            volatile int  counter;
			#endif




        public:

            inline CReference() : counter(0)
            {
            }



            inline ~CReference()
            {
            }


            inline void Assign(int value)
            {
                #ifdef _WIN32
                InterlockedExchange( & counter, value );
                #endif
        
                #if defined(__linux) || defined(__APPLE__)
                __sync_lock_test_and_set( & counter, value );
                #endif
            }



            inline int Increase()
            {
                #ifdef _WIN32
                return InterlockedIncrement( & counter );
                #endif
        
                #if defined(__linux) || defined(__APPLE__)
                return __sync_add_and_fetch( & counter, 1 );
                #endif
            }



            inline int Decrease()
            {
                #ifdef _WIN32
                return InterlockedDecrement( & counter );
                #endif

                #if defined(__linux) || defined(__APPLE__)
                return __sync_sub_and_fetch( & counter, 1 );
                #endif
            }



            inline int GetReference()
            {
                #ifdef _WIN32
                return InterlockedCompareExchange ( & counter, 0, 0 );
                #endif

                #if defined(__linux) || defined(__APPLE__)
                return __sync_val_compare_and_swap( & counter, 0, 0 );
                #endif
            }



    };  //end class CReference


}//end namespace atom


#endif
